/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "tcpwid.h"
#include "express.h"
#include "ui_tcpwid.h"
#include <QHostInfo>
#include <QMessageBox>
#include <QTableWidget>
#include <QFile>
#include <QFileDialog>
#include "sendfile.h"
#include <QApplication>
#include <QScreen>
#include <mythread.h>
#include <QDateTime>
#include <QJsonObject>
#include "myinfo.h"
#include "mycpp.h"
/*********************************************************************************************************/
/*                          用于好友间直接通信聊天,此时每个客户端程序上既有实现服务端功能的部分                    */
/*                         又有实现客户端功能的部分,前者用于接受聊天数据,后者用于发送聊天数据                      */
/*********************************************************************************************************/
Tcpwid::Tcpwid( QString friend_name,int friend_id)
    :ui(new Ui::Tcpwid),
    Friend_name(friend_name),
    Friend_ID(friend_id)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800,570));
    m_curwidth = 80;
    //connect(client_socket,&QTcpSocket::readyRead,this,&Tcpwid::tcp_read_stream);
    //初始化数据
    init();
    //获取主机的IP信息
    //gethostifo();
}

//初始化控件的图标、权限，信号关联
void Tcpwid::init()
{
     //设置聊天窗口只读
     //ui->recordEdit->setReadOnly(true);

     //表情的按钮状态默认为不显示
     expre_stat = 0;
     //初始化发送的表情
     express_url = nullptr;
     //初始化发送文件的数据
     filesize = 0;
     sendsize = 0;
     filename = nullptr;

}

//获取主机信息显示出来
void Tcpwid::gethostifo()
{
    //获取主机用户名
    QString hostname = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(hostname);
    QList<QHostAddress> add = info.addresses();
    //ui->recordEdit->append(hostname);
    foreach(QHostAddress address,add)
    {
        //ui->recordEdit->append("**************");
        //ui->recordEdit->append(address.toString());
    }
}

//表情包界面的槽函数
void Tcpwid::on_expreBt_pressed()
{
    //用点击表情按钮的次数来控制显示和关闭，偶数关闭，奇数显示
    expre_stat++;
    if(expre_stat%2 != 0)
    {
        exprewid= new Express(this,nullptr);
        exprewid->setParent(this);
        exprewid->move(0,136);
        exprewid->show();
    }
    if(expre_stat%2 == 0)
    {
        exprewid->close();
    }
}
//获取子项表情的槽函数
void Tcpwid::getitem_expre(QUrl url)
{
    //将表情添加到发送信息框里
    ui->sendEdit->insertHtml("<img src='" + url.toString() + "'/>");
    QString express_path = url.toString().split("file:").at(1);
    Send_express_List.append(express_path);
    qDebug()<<express_path;
    express_url = url;
}
void Tcpwid::Recv_Send_express_signals()
{
    foreach(auto item,Send_express_List)
    {
        Send_express_List.removeOne(item);
    }
    qDebug()<<QStringLiteral("发送表情完毕，清空表情列表")<<Send_express_List.size()<<Send_express_List;
}

//发送GIF图片
void Tcpwid::on_GIFBt_pressed()
{
    //用点击表情按钮的次数来控制显示和关闭，偶数关闭，奇数显示
    expre_stat++;
    if(expre_stat%2 != 0)
    {
       // exprewid= new Express(this);
        exprewid->setParent(this);
        exprewid->move(0,0);
        exprewid->show();
    }
    if(expre_stat%2 == 0)
    {
        exprewid->close();
    }
}

//截屏
void Tcpwid::on_shotBt_pressed()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    QString filePathName = "full-";

    //filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");

    filePathName += ".jpg";

    if(!screen->grabWindow(0).save(filePathName, "jpg"))

    {

        qDebug()<<"save full screen failed";

    }
}

Tcpwid::~Tcpwid()
{
    qDebug()<<"关闭窗口";
    udp_thread->exit();
    delete ui;
}

//打开文件对话框，获取文件属性
void Tcpwid::on_send_fileBt_clicked()
{
    //获取文件路径
    filepath = QFileDialog::getOpenFileName(this,tr("文件对话框"),"C:");
    //控制开始发送
    if(filename != nullptr)
    {
        //发送文件头
        send_file_head();
        //当套接字发送文件头完毕会发送一个信号bytesWritten
        connect(client_socket,&QTcpSocket::bytesWritten,this,&Tcpwid::send_file_text);//发送文件内容
    }
}

//发送文件头
void Tcpwid::send_file_head()
{
    QFileInfo file_info(filepath);
    //获取文件大小
    filesize = file_info.size();
    //获取文件名
    filename = file_info.fileName();

    QByteArray array; //空间
    //把array与数据流绑定
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream<<filesize<<filename;

    //设置文件名
    file.setFileName(filepath);
    file.open(QIODevice::ReadOnly);
    //获取文件内容
    filetext = file.readAll();
    //发送
    client_socket->write(array);
    qDebug()<<QStringLiteral("发送文件头完毕");
}
//发送文件内容
void Tcpwid::send_file_text()
{

    if(sendsize < filesize)
    {
        QByteArray array = file.read(1024*10);//读取一段内容
        client_socket->write(array);//发送一段内容
        sendsize += array.size();
    }
    if(sendsize == filesize)
    {
        file.close();//关闭文件
    }
    qDebug()<<QStringLiteral("发送文件内容完毕");
}
/**@
 * 表情动态显示GIF
 *
 * */
void Tcpwid::addAnimation(const QUrl& url, const QString& fileName)
{
    //插入Html描述的图片
    //ui->recordEdit->insertHtml("<img src='" + url.toString() + "'/>");

    //判断是否是相同的图片
    if (m_lstUrls.contains(url))
    {
        return;
    }
    else
    {
        m_lstUrls.append(url);
    }

    //创建QMovie以显示Gif
    QMovie* movie = new QMovie(this);
    movie->setFileName(fileName);
    movie->setCacheMode(QMovie::CacheNone);

    m_hasUrls.insert(movie, url);

    //绑定帧切换信号槽
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(subAnimate(int)));
    movie->start();
}
void Tcpwid::subAnimate(int a)
{
    //使用QMovie中的当前帧替换掉富文本中的图片元素
    QMovie* movie = qobject_cast<QMovie*>(sender());
    //ui->recordEdit->document()->addResource(QTextDocument::ImageResource,
            //m_hasUrls.value(movie), movie->currentPixmap());
    //ui->recordEdit->setLineWrapColumnOrWidth(ui->recordEdit->lineWrapColumnOrWidth());
}
void Tcpwid::on_m_editAnimated_clicked(QStringList express_path)
{
    for(int i=0;i<express_path.count();i++)
    {
        m_count++;
        if(express_path.at(i) != nullptr)
        addAnimation(QUrl(QString("%1").arg(m_count)), express_path.at(i));
    }

}
