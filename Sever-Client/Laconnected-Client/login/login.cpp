/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QMovie>
#include <QDebug>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QTime>
#include <QPropertyAnimation>
#include <QHostAddress>
#include "log_tabel.h"
#include <comm_widgets/communication.h>
#include <QGroupBox>
#include <login/rotatingstackedwidget.h>
#include <QTimer>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    m_areaMovable = geometry();
    m_bPressed = false;
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    Connext_to_Server();
    passaction = false;
    login_init();
    QTimer *connect_timer = new QTimer();
    connect(connect_timer,&QTimer::timeout,this,&Login::Timer_Check_Connected);
    connect_timer->start(2000);
}
void Login::Connext_to_Server()
{
    m_socket = new QTcpSocket;
    m_socket->connectToHost(QHostAddress(Server::Server_IP),Server::Server_sendmsg_port);
    connect(m_socket,&QTcpSocket::connected,this,[=](){
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("连接成功"));
        connect(m_socket,&QTcpSocket::disconnected,this,&Login::Server_Disconnect);
        connect(m_socket,&QTcpSocket::readyRead,this,&Login::Deal_Server_BackLogMsg);
    });
}
//是否连接上服务器
bool Login::isConnected_Server()
{
     if(m_socket->state() == QAbstractSocket::ConnectedState)//套接字的状态
         return true;
     return false;
}
//定时监测是否连接服务器
void Login::Timer_Check_Connected()
{
     if(!isConnected_Server())
         Connext_to_Server();
}

//服务器断开
void Login::Server_Disconnect()
{
     m_socket->abort();
     QMessageBox::information(this,QStringLiteral("服务器配置"),QStringLiteral("服务器断开"));
}
//解析服务器返回的登录信息
void Login::Deal_Server_BackLogMsg()
{
    char reads[1024] = {0};
    m_socket->read(reads,sizeof reads);
    QByteArray bytearray = QByteArray(reads);
    qDebug()<<QStringLiteral("返回的登录信息")<< QString(bytearray) <<bytearray.size();
    QJsonParseError jsonerror ;
    QJsonDocument document = QJsonDocument::fromJson(bytearray,&jsonerror);
    if(!document.isNull() && (jsonerror.error == QJsonParseError::NoError))
    {
        if(document.isObject())
        {
            QJsonObject jsonObj = document.object();
            QJsonValue data_json = jsonObj.value("data");
            int M_type_State = jsonObj.value("type").toInt();
            switch(M_type_State)
            {
                case USER_LOGIN_SUCCESS:
                     Deal_Server_BackLogMsg_Succsee(data_json);break;
                case USER_LOGIN_NO:
                     Deal_Server_BackLogMsg_No();break;
            }
        }
    }
}

void Login::setAreaMovable(const QRect rt)
{
    if(m_areaMovable != rt)
    {
    m_areaMovable = rt;
    }
}

void Login::mousePressEvent(QMouseEvent *e)
{
    //鼠标左键
    if(e->button() == Qt::LeftButton)
    {
    m_ptPress = e->pos();
    qDebug() << pos() << e->pos() << m_ptPress;
    m_bPressed = m_areaMovable.contains(m_ptPress);
    }
}

void Login::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bPressed)
    {
    qDebug() << pos() << e->pos() << m_ptPress;
    move(pos() + e->pos() - m_ptPress);
    }
}

void Login::mouseReleaseEvent(QMouseEvent *)
{
    m_bPressed = false;
}

void Login::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information( this, tr("exit tip"), tr("Do you really want exit?"), tr("Yes"), tr("No"), 0, 1 ) )
       {
         case 0:
              event->accept();
              break;
         case 1:
         default:
             event->ignore();
             break;
       }
}
void Login::Deal_Server_BackLogMsg_Succsee(QJsonValue &data_json)
{
    //保存用户ID、呢称
    Mycpp::USERID = data_json.toObject().value("id").toInt();
    Mycpp::USERNAME = data_json.toObject().value("name").toString();
    //进入主界面之前先把该界面的用户名和密码清除
    ui->UserEdit_4->setText("");
    ui->PasswordEdit_4->setText("");
    QPropertyAnimation *animation = new QPropertyAnimation(this);
    animation->setDuration(1000);
    animation->setStartValue(QPoint(40, 115));
    animation->setEndValue(QPoint(this->width(), this->height()));
    animation->start();
    //进入主界面
    m_socket->disconnect(SIGNAL(readyRead()));//取消关联读取信号
    Communication *main_mywin = new Communication(m_socket);
    main_mywin->show();
    this->hide();
    connect(main_mywin,&Communication::login_widget_show_signals,this,[=](){
        this->show();
        connect(m_socket,&QTcpSocket::readyRead,this,&Login::Deal_Server_BackLogMsg);//恢复关联读取信号
    });
    qDebug()<<QStringLiteral("隐藏窗口");
}
void Login::Deal_Server_BackLogMsg_No()
{
    QMessageBox::information(this,QStringLiteral("登录"),QStringLiteral("登录失败"));
}

Login::~Login()
{
    delete ui;
}

void Login::login_init()
{
    //动态gif显示
    QMovie *movie = new QMovie(":/resource/Mainbackgroud_3.gif");
    ui->label->setScaledContents(true);
    ui->label->setMovie(movie);
    movie->start();
    //打开.qss样式表
    QFile file(":/QSS/button_icon.qss");
    file.open(QFile::ReadOnly);
    QString StyleSheet = file.readAll();
    qApp->setStyleSheet(StyleSheet);
    file.close();
    //设置控件图标
    ui->QQlabel_4->setPixmap(QPixmap(":/resource/1.gif"));
    ui->QQlabel_4->setScaledContents(true);
    ui->userlabel_4->setPixmap(QPixmap(":/comicon/ic_user.png"));
    ui->locklabel_4->setPixmap(QPixmap(":/resource/lock.png"));

}

//延时函数
void Login::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


//登录-------发送登录信息JSON给服务器进行验证
void Login::on_regBt_clicked()
{
    QString username = ui->UserEdit_4->text();
    QString password = ui->PasswordEdit_4->text();

    //生成JSON
    QJsonObject userinfo_json;

    QJsonObject data;
    data.insert("username" , username);
    data.insert("userpass" , password);
    data.insert("userid",Mycpp::USERID);
    data.insert("text","");

    userinfo_json.insert("data",QJsonValue(data));

    userinfo_json.insert("from_id" ,Mycpp::USERID);
    userinfo_json.insert("type",USER_LOGIN);//登录类型信息

    QJsonDocument document;
    document.setObject(userinfo_json);
    QByteArray bytearray = document.toJson(QJsonDocument::Compact);
    QString strjson(bytearray);
    qDebug()<<strjson;
    //发送JSON
    m_socket->write(bytearray);
    QMessageBox::information(this,QStringLiteral("发送登录信息"),QStringLiteral("发送成功"));

}
//注册
void Login::on_logonBt_clicked()
{  
    Log_tabel *log_ui = new Log_tabel(m_socket);
    log_ui->show();
}
//记住密码
void Login::on_re_password_clicked(bool checked)
{


}
//自动登录
void Login::on_auto_log_clicked(bool checked)
{

}

//其他设置按钮，比如帮助、服务器配置等
void Login::on_log_otherBt_activated(const QString &arg1)
{
    if(arg1 == QString::fromLocal8Bit("配置"))
    {
        //QLabel *group_label = new QLabel(ui->groupBox_2);
        //QMovie *movie = new QMovie(":/resource/Mainbackgroud_3.gif");
        //group_label->setScaledContents(true);
        //group_label->setMovie(movie);
        //group_label->setPixmap(QPixmap(":/resource/1.gif"));
        //group_label->setFixedSize(ui->groupBox_2->size());
        //group_label->lower();
        //movie->start();
        ui->stackedWidget->nextPage();
    }
    if(arg1 == QString::fromLocal8Bit("帮助"))
    {

    }

    return ;
}

void Login::on_yes_bt_clicked()
{
    Server::Server_IP = ui->ser_setip_Edit->text();
    Server::Server_sendmsg_port = ui->ser_setprot_Edit->text().toInt();
    QMessageBox::information(this,"服务器配置","配置成功");
}

void Login::on_cancel_bt_clicked()
{
    ui->stackedWidget->nextPage();
}

void Login::on_close_bt_clicked()
{
    QApplication* app;
    app->exit(0);
}

void Login::on_log_otherBt_activated(int index)
{
    if(index == 0)
    {

    }
    if(index == 1)
    {
        //QLabel *group_label = new QLabel(ui->groupBox_2);
        //QMovie *movie = new QMovie(":/resource/Mainbackgroud_3.gif");
        //group_label->setScaledContents(true);
        //group_label->setMovie(movie);
        //group_label->setPixmap(QPixmap(":/resource/1.gif"));
        //group_label->setFixedSize(ui->groupBox_2->size());
        //group_label->lower();
        //movie->start();
        ui->stackedWidget->nextPage();
    }
}
