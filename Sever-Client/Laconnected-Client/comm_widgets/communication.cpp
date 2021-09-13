/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "communication.h"
#include "ui_communication.h"
#include "addwin.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QListWidgetItem>
#include <QMenu>
#include <QSqlQuery>
#include <ui_tcpwid.h>
#include "treewidget.h"
#include <tcp_udp_socket/tcpwid.h>
#include "mycpp.h"
#include "myinfo.h"
#include "login/rotatingstackedwidget.h"
#include <QTime>
#include <ui_addwin.h>
#include "ui_groupwid.h"
#include <QMessageBox>
#include <QMovie>
#include "otheroperations.h"

#include <tcp_udp_socket/chatcontentcircular.h>

Communication::Communication(QTcpSocket *socket) :
    ui(new Ui::Communication)
{
    ui->setupUi(this);
    m_socket = socket;
    this->setFixedSize(QSize(380,640));

    //this->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明
    //初始默认状态
    acquiesce();
    //创建一个树列表作为好友列表、群聊列表
    tree = new Treewidget(Get_Widget(USER_FRIEND_WIDGET),QRect(QPoint(0,0),QSize(380,360)));
    group_tree = new Treewidget(Get_Widget(USER_GROUP_WIDGET),QRect(QPoint(0,0),QSize(380,360)));

    tree->init(USER_FRIEND_WIDGET);
    group_tree->init(USER_GROUP_WIDGET);

    Get_Friend_Count();

    friend_item = tree->create_friendlist();
    group_item = group_tree->create_grouplist();
    //与好友列表关联
    connect(tree,SIGNAL(tcpstart(QString)),this,SLOT(TCPchat(QString)));//注意：此地方不能写变量名，不然信号发射不出去
    connect(group_tree,SIGNAL(udpstart(QString)),this,SLOT(Group_Chat(QString)));

    //初始化显示好友已存在的列表
    open_friend_database_show();
    open_groupbase_show();
    Create_Friend_Msg_DataBase();
    //Open_Friend_Msg_database();

    connect(m_socket,&QTcpSocket::readyRead,this,&Communication::M_Recv_Msg);
}

//初始默认状态
void Communication::acquiesce()
{
    Create_Widgets();
    //个性签名
    QString m_name = QStringLiteral("本人很懒，没有留下什么签名");
    //主界面的上半部的背景图片
    QLabel *backgroundlabel = new QLabel(ui->page);
    backgroundlabel->setFixedSize(QSize(390,175));
    backgroundlabel->move(0,0);
    //backgroundlabel->setPixmap(QPixmap(":/resource/Mainbackgroud_3.gif"));
    QMovie *movie = new QMovie(":/resource/Mainbackgroud_3.gif");
    backgroundlabel->setScaledContents(true);
    backgroundlabel->setMovie(movie);
    movie->start();

    //默认的用户名和个性签名
   QLabel *User_Name_label = new QLabel(ui->page);
   User_Name_label->setFixedSize(QSize(280,30));
   User_Name_label->move(95,80);
   QPalette pe;
   pe.setColor(QPalette::WindowText,Qt::white);
   User_Name_label->setPalette(pe);
   User_Name_label->setText((QString(QStringLiteral("用户名: ") + Mycpp::USERNAME)));
   User_Name_label->setStyleSheet("background:transparent");//label透明显示

   QLabel *User_Uni_Name_label = new QLabel(ui->page);
   User_Uni_Name_label->setFixedSize(QSize(280,30));
   User_Uni_Name_label->move(95,100);
   pe.setColor(QPalette::WindowText,Qt::white);
   User_Uni_Name_label->setPalette(pe);
   User_Uni_Name_label->setText(QStringLiteral( "个性签名: ") + m_name);
   User_Uni_Name_label->setStyleSheet("background:transparent");

   //头像按钮，后期可自定义头像更换
   QPushButton *headbt = new QPushButton(ui->page);
   headbt->setIcon(QIcon(QPixmap(":/resource/UserHead.jpg")));
   headbt->setIconSize(QSize(65,65));
   headbt->move(20,50);
   headbt->setStyleSheet("background:transparent");
   //其他操作按钮
   other_widget = new OtherOperations(this);
   other_widget->move(QPoint(30,450));
   other_widget->hide();
   is_other_operations = true;
   //头像按钮关联槽函数
   connect(headbt,&QPushButton::clicked,this,&Communication::headBt_event);
   connect(other_widget,SIGNAL(exit_login_signal()),this,SLOT(exit_login()));
}
//打开好友数据库，初始化显示
void Communication::open_friend_database_show()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("friend.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from friend");
    query.exec(sql);
    while ((query.next()))
    {
        QString friend_name = query.value(2).toString();
        /*发送服务器获取好友状态*/
        Get_Friend_State_from_Server(friend_name);
        qDebug()<<"初始化显示好友列表";
        tree->show_save_friendlist(friend_name);
    }

}

void Communication::Get_Friend_State_from_Server(QString friend_name)
{
     QJsonObject get_state;
     get_state.insert("friend_name",friend_name);
     get_state.insert("type",USER_GET_FRIEND_STATE);

     QJsonDocument document;
     document.setObject(get_state);

     m_socket->write(document.toJson(QJsonDocument::Compact));
}

//打开讨论组/群聊数据库，初始化显示
void Communication::open_groupbase_show()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_group.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from user_group");
    query.exec(sql);
    while ((query.next()))
    {
        QString group_name = query.value(2).toString();
        qDebug()<<"初始化显示群聊列表";
        qDebug()<<group_name;
        group_tree->show_save_grouplist(nullptr,group_name);
    }

}
//创建聊天记录数据库
void Communication::Create_Friend_Msg_DataBase()
{
    QSqlDatabase Msg_database = QSqlDatabase::addDatabase("QSQLITE");
    Msg_database.setDatabaseName("Msg.db");

    if(!Msg_database.open())
        qDebug()<<"open Msg.db error";
    else
        qDebug()<<"open Msg.db ok";
    QString Msg_sql = "create table if not exists Msg(friend_id int not NULL,user_id int not NULL,Msg_text text not NULL,curr_time text not NULL)";
    QSqlQuery query(Msg_sql);
    if(!query.exec())
        qDebug()<<"create Msg table error";
    else
        qDebug()<<"create Msg table ok";
}
//打开好友聊天记录数据库
void Communication::Open_Friend_Msg_database()
{
    QSqlDatabase Msg_db = QSqlDatabase::addDatabase("QSQLITE");
    Msg_db.setDatabaseName("Msg.db");
    if(!Msg_db.open())
        qDebug()<<"open Msg.db error";
    else
        qDebug()<<"open Msg.db ok";
}

int Communication::Get_Friend_Count()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("friend.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from friend");
    query.exec(sql);
    int count = 0;
    while(query.next())
    {
       count++;
    }
    Mycpp::FRIEND_NUM = count;
    return  count;
}

//头像自定义
void Communication::headBt_event()
{
    qDebug()<<QStringLiteral( "更换头像");
}
//添加好友
void Communication::on_addBt_clicked()
{
    Addwin *addwin = new Addwin();
    addwin->setFixedSize(QSize(450,150));
    ADD_FRIEND_SIGNAL_CONNECTED(addwin);
    addwin->show();
}
/*@关联添加好友界面控件
 * 添加好友按钮
 * */
void Communication::ADD_FRIEND_SIGNAL_CONNECTED(Addwin *addwin)
{
    connect(addwin->ui->addBt,&QPushButton::clicked,this,[=](){
            Add_Friend_SendJson_to_Server(addwin);
    });
    connect(addwin->ui->UDP_addBt,&QPushButton::clicked,this,[=](){
            Add_Group_SendJson_to_Sever(addwin);
    });
}

void Communication::Add_Friend_database_insert(int friend_id, int userid, QString friend_name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("friend.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString add_friend_sql = QString("insert into friend(friend_id,user_id,friend_name) values('%1','%2','%3')").arg(friend_id).arg(userid).arg(friend_name);
    QSqlQuery query;
    if(!query.exec(add_friend_sql))
    {
        qDebug()<<QStringLiteral("新好友插入数据库失败");
    }
    else
        qDebug()<<QStringLiteral("新好友插入数据库成功");
}

void Communication::Add_Group_database_insert(int group_id, int user_id, QString group_name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_group.db");

    if(!db.open())
    {
        qDebug()<<"open group sql error";
    }
    else {
        qDebug()<<"open group ok";
    }

    QString add_group_sql = QString("insert into user_group(group_id,user_id,group_name) values('%1','%2','%3')").arg(group_id).arg(user_id).arg(group_name);
    QSqlQuery query;
    if(!query.exec(add_group_sql))
    {
        qDebug()<<QStringLiteral("新群聊插入数据库失败");
    }
    else
        qDebug()<<QStringLiteral("新群聊插入数据库成功");
}
/*@服务器返回添加好友成功信息
 * 解析JSON
 * */
void Communication::M_Recv_Add_Friend_Success(QJsonValue &data_json)
{
    QJsonObject data_obj = data_json.toObject();
    int friend_id = data_obj.value("id").toInt();
    QString friend_name = data_obj.value("name").toString();
    Add_Friend_database_insert(friend_id,Mycpp::USERID,friend_name);
    QMessageBox::information(this,QStringLiteral("添加好友"),QStringLiteral("添加成功"));
    tree->add_new_friend(friend_item,friend_name,NULL);
    tree->User_Online_Or_Disconnected_Msg(USER_ADD_FRIEND_NUM);
}

void Communication::M_Recv_Add_Friend_No(QJsonValue &)
{
    QMessageBox::information(this,QStringLiteral("添加好友"),QStringLiteral("添加失败"));
}
/*@服务器返回添加好友通知
 * 解析JSON
 * 选择同意、拒绝
 * */
void Communication::M_Recv_Add_Friend_Widget(QJsonValue &data_json)
{
    QJsonObject data_obj = data_json.toObject();
    QString friend_name = data_obj.value("name").toString();
    int friend_id = data_obj.value("id").toInt();
    qDebug()<<data_json<<friend_name;
    Addwin *addwin = new Addwin();
    Add_Friend_database_insert(friend_id,Mycpp::USERID,friend_name);
    QMessageBox::information(this,QStringLiteral("添加好友"),friend_name +QStringLiteral( "添加你为好友"),QMessageBox::Ok,QMessageBox::No);
    tree->add_new_friend(friend_item,friend_name,NULL);
    tree->User_Online_Or_Disconnected_Msg(USER_ADD_FRIEND_NUM);
}
/*@服务器返回添加群聊成功信息
 * 解析JSON
 * */
void Communication::M_Recv_Add_Group_Succsee(QJsonValue &data_json)
{
    QJsonObject data_obj = data_json.toObject();
    int group_id = data_obj.value("group_id").toInt();
    QString group_name = data_obj.value("group_name").toString();
    qDebug()<<QStringLiteral("服务器返回添加群聊成功信息")<<group_name;
    Add_Group_database_insert(group_id,Mycpp::USERID,group_name);
    QMessageBox::information(this,QStringLiteral("添加群聊"),QStringLiteral("添加成功"));
    group_tree->add_new_friend(group_item,NULL,group_name);
}

void Communication::M_Recv_Add_Group_No(QJsonValue &)
{
    QMessageBox::information(this,QStringLiteral("添加群聊"),QStringLiteral("添加失败"));
}
/*@添加好友
 * 发送JSON到服务器
 * 服务器接收JSON
 * 返回成功或失败JSON
 * */
void Communication::Add_Friend_SendJson_to_Server(Addwin *addwin)
{
    QString addname = addwin->ui->add_NameEdit->text();
    /*添加好友前先检索是否已存在该好友*/
    if(Get_Friend_ID(addname) != -1)
        return ;
    if(addname.count())
    {
        //将添加好友信息包装JSON发送到服务器
        QJsonObject add_obj;

        QJsonObject data_obj;
        data_obj.insert("userid",-1);
        data_obj.insert("username",addname);
        data_obj.insert("userpass","");
        data_obj.insert("text","");

        add_obj.insert("data",data_obj);
        add_obj.insert("from_id",Mycpp::USERID);
        add_obj.insert("type",USER_ADDFRIEND);

        QJsonDocument document;
        document.setObject(add_obj);
        QByteArray bytearray = document.toJson(QJsonDocument::Compact);
        QString strjson(bytearray);
        qDebug()<<QStringLiteral("添加好友信息")<<strjson;
        //发送JSON
        m_socket->write(bytearray);
        qDebug()<<QStringLiteral("发送好友添加信息");
        //QMessageBox::information(this,QStringLiteral("发送注册信息"),QStringLiteral("发送成功"));
    }
   else
    {
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("好友IP或端口号不能为空"));
    }
}
/*@添加群聊
 * 发送JSON到服务器
 * 服务器接收JSON
 * 返回成功或失败JSON
 * */
void Communication::Add_Group_SendJson_to_Sever(Addwin *addwin)
{
    QString add_group_name = addwin->ui->UDPname_addproEdit->text();
    /*添加好友前先检索是否已存在该群聊*/
    int group_id = -1;
    if(is_Have_Group_Name(add_group_name))
        group_id = Get_Group_ID(add_group_name);
    if(add_group_name.count())
    {
        //将添加群聊信息包装JSON发送到服务器
        QJsonObject add_obj;

        QJsonObject data_obj;
        data_obj.insert("group_id",group_id);
        data_obj.insert("group_name",add_group_name);
        data_obj.insert("text","");
        data_obj.insert("user_id",Mycpp::USERID);

        add_obj.insert("data",data_obj);
        add_obj.insert("type",USER_ADDGROUP);

        QJsonDocument document;
        document.setObject(add_obj);
        QByteArray bytearray = document.toJson(QJsonDocument::Compact);
        QString strjson(bytearray);
        qDebug()<<QStringLiteral("添加群聊信息")<<strjson;
        //发送JSON
        m_socket->write(bytearray);
        qDebug()<<QStringLiteral("发送群聊添加信息");
        //QMessageBox::information(this,QStringLiteral("发送注册信息"),QStringLiteral("发送成功"));
    }
   else
    {
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("群聊呢称不能为空"));
    }
}

void Communication::Loat_Group_Friend_List(QTreeWidget *treewidget)
{
    QTreeWidgetItem *head_item = new QTreeWidgetItem(treewidget);
    head_item->setText(0,"群友列表");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_group.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from user_group");
    query.exec(sql);
    while(query.next())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(head_item);
        item->setText(0,query.value(2).toString());
    }
}

//获取好友的ID
int Communication::Get_Friend_ID(QString friend_name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("friend.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from friend where friend_name='%1'").arg(friend_name);
    query.exec(sql);
    if(query.next())
    {
        int m_id = query.value(0).toInt();
        qDebug()<<QStringLiteral("获取好友ID成功")<<m_id;
        return m_id;
    }
         qDebug()<<QStringLiteral("获取好友ID失败");
         return -1;
}

int Communication::Get_Group_ID(QString group_name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_group.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from user_group where group_name='%1'").arg(group_name);
    query.exec(sql);
    if(query.next())
    {
        int m_id = query.value(0).toInt();
        qDebug()<<QStringLiteral("获取群聊ID成功")<<m_id;
        return m_id;
    }
         qDebug()<<QStringLiteral("获取群聊ID失败")<<group_name;
         return -1;
}

QString Communication::Get_Group_Name(int group_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_group.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from user_group where group_id='%1'").arg(group_id);
    if(!query.exec(sql))
        qDebug()<<QStringLiteral("Get_Group_Name error");
    if(query.next())
    {
        QString m_name = query.value(2).toString();
        qDebug()<<QStringLiteral("获取群聊呢称成功")<<m_name;
        return m_name;
    }
         qDebug()<<QStringLiteral("获取群聊呢称失败")<<group_id;
         return "";
}

QString Communication::Get_Friend_name(int friend_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("friend.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QSqlQuery query;
    QString sql = QString("select * from friend where friend_id='%1'").arg(friend_id);
    query.exec(sql);
    if(query.next())
    {
        QString m_name = query.value(2).toString();
        qDebug()<<QStringLiteral("获取好友名字成功")<<m_name;
        return m_name;
    }
         qDebug()<<QStringLiteral("获取好友名字失败");
         return 0;
}

Tcpwid *Communication::Get_TcpwidList_One(int friend_id)
{
    for(int i=0;i<Tcpwid_friendID_List.count();i++)
    {
        if(Tcpwid_friendID_List.at(i) == friend_id)
            return TcpwidList.at(i);
    }
    return 0;
}

int Communication::Get_Tcpwid_FriendID_One(Tcpwid *tcpwin)
{
    for(int i=0;i<TcpwidList.count();i++)
    {
        if(TcpwidList.at(i) == tcpwin)
            return Tcpwid_friendID_List.at(i);
    }
    return -1;
}

Groupwid *Communication::Get_GroupwidList_One(int group_id)
{
    for(int i=0;i<group_ID_List.count();i++)
    {
        if(group_ID_List.at(i) == group_id)
            return groupwid_List.at(i);
    }
    return 0;
}

int Communication::Get_GroupID_One(Groupwid *groupwid)
{
    for(int i=0;i<groupwid_List.count();i++)
    {
        if(groupwid_List.at(i) == groupwid)
            return group_ID_List.at(i);
    }
    return -1;
}

QStringList Communication::Get_Friend_Msg_Ten(int friend_id, int user_id)
{
    /*获取最新的10条信息前，先获取信息总数*/
    int Msg_Num = Get_Friend_Msg_Num(friend_id,user_id);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msg.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }
    QStringList Msg_List;
    int start_get_msg = 0;
    QString Msg_sql = QString("select * from Msg where friend_id='%1' and user_id='%2' ").arg(friend_id).arg(user_id);
    QSqlQuery query(Msg_sql);
    query.exec();
    while(query.next())
    {
        start_get_msg++;
        if(start_get_msg > Msg_Num-10)
        {
            Msg_List.append(query.value(3).toString());
            Msg_List.append(query.value(2).toString());
        }

    }
    qDebug()<<QStringLiteral("获取聊天记录")<<Msg_List;
    return Msg_List;
}

int Communication::Get_Friend_Msg_Num(int friend_id, int user_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msg.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }
    int Num = 0;
    QString Msg_sql = QString("select * from Msg where friend_id='%1' and user_id='%2' ").arg(friend_id).arg(user_id);
    QSqlQuery query(Msg_sql);
    query.exec();
    while(query.next())
    {
        Num++;
    }
    qDebug()<<QStringLiteral("信息总数")<<Num;
    return Num;
}

void Communication::Save_Friend_Msg_One(int friend_id, int user_id,QString Msg_text,QString Curr_Time)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msg.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }
    /*插入新记录前检索是否已满100条记录，若满100条则删除全部信息，再插入新记录*/
    if(is_Have_Ten_Msg(friend_id,user_id))
        Delete_First_Msg(friend_id,user_id);
    QString Msg_sql = QString("insert into Msg(friend_id,user_id,Msg_text,curr_time) values('%1','%2','%3','%4')").arg(friend_id).arg(user_id).arg(Msg_text).arg(Curr_Time);
    QSqlQuery query;
    if(!query.exec(Msg_sql))
    {
        qDebug()<<QStringLiteral("保存历史记录失败")<<Msg_sql;
    }
    else
        qDebug()<<QStringLiteral("保存历史记录成功");
}

bool Communication::is_Have_Ten_Msg(int friend_id, int user_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msg.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString Msg_sql = QString("select * from Msg where friend_id='%1' and user_id='%2' ").arg(friend_id).arg(user_id);
    QSqlQuery query(Msg_sql);
    query.exec();
    int Msg_count = 0;
    while(query.next())
    {
        Msg_count++;
    }
    if(Msg_count >= 100)
    {
        qDebug()<<QStringLiteral("已满100条")<<Msg_count;
        return true;
    }

    return false;
}

bool Communication::is_Have_Msg(int friend_id, int user_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msg.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString Msg_sql = QString("select * from Msg where friend_id='%1' and user_id='%2' ").arg(friend_id).arg(user_id);
    QSqlQuery query(Msg_sql);
    query.exec();
    if(query.next())
        return true;
    return false;
}

bool Communication::is_Have_Group_Name(QString group_name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user_group.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString Msg_sql = QString("select * from user_group where group_name='%1'").arg(group_name);
    QSqlQuery query(Msg_sql);
    query.exec();
    if(query.next())
        return true;
    return false;
}

void Communication::Delete_First_Msg(int friend_id, int user_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msg.db");

    if(!db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString Msg_sql = QString("delete  from Msg where friend_id='%1' and user_id='%2' ").arg(friend_id).arg(user_id);
    QSqlQuery query(Msg_sql);
    query.exec();
}

bool Communication::is_Open_QWidget_Tcp(int friend_id)
{
    for(int i=0;i<Tcpwid_friendID_List.count();i++)
    {
        if(Tcpwid_friendID_List.at(i) == friend_id)
        {
            return true;
        }
    }
    return false;
}

bool Communication::is_Open_QWidget_Group(int group_id)
{
    for(int i=0;i<group_ID_List.count();i++)
    {
        if(group_ID_List.at(i) == group_id)
        {
            return true;
        }
    }
    return false;
}


/*@好友通信
 * 聊天窗口管理，创建聊天窗口列表、聊天窗口好友ID列表
 * 打开聊天窗口，则加入聊天窗口容器中，绑定ID
 * */
void Communication::TCPchat(QString friend_name)
{
   qDebug()<<QStringLiteral("好友名字")<<friend_name;
   int friend_id = Get_Friend_ID(friend_name);
   Tcpwid *tcpwin = new Tcpwid(friend_name,friend_id);//传好友呢称和id
   tcpwin->setWindowTitle(QStringLiteral( "正在和 ")+friend_name+QStringLiteral( " 聊天中")+ "     " +QStringLiteral("在线"));
   /*弹出聊天窗口前先检索是否有历史聊天记录，若有记录则加载记录*/
   if(is_Have_Msg(friend_id,Mycpp::USERID))
   {
       //加载历史记录
       QStringList Msg_List = Get_Friend_Msg_Ten(friend_id,Mycpp::USERID);
       for(int i=0;i<Msg_List.count();i++)
       {
           QString express_msg = Msg_List.at(i);
           if(express_msg.contains(Mycpp::QStringspilt))
           {
               //QStringList express_msg_spilt;
               //express_msg_spilt = express_msg.split(Mycpp::QStringspilt);
               //express_msg_spilt.removeFirst();
               qDebug()<<express_msg<<QStringLiteral("加载历史表情");

               if(express_msg.contains(Mycpp::M_QString_Spilt_Friend,Qt::CaseSensitive))
                   Show_Friend_Chat_Currtext(express_msg,tcpwin);
               else if(express_msg.contains(Mycpp::M_QString_Spilt_My,Qt::CaseSensitive))
                   Show_Self_Chat_Currtext(express_msg,tcpwin);
           }
           else
           {
               //tcpwin->ui->recordEdit->append(Msg_List.at(i));
               if(i%2 != 0)
               {
                   QString text = Msg_List.at(i);
                   if(text.contains(Mycpp::M_QString_Spilt_Friend,Qt::CaseSensitive))
                   {
                       Show_Friend_Chat_Currtext(text,tcpwin);
                   }
                   else if(text.contains(Mycpp::M_QString_Spilt_My,Qt::CaseSensitive))
                   {
                       Show_Self_Chat_Currtext(text,tcpwin);
                   }
               }

           }
       }
   }
   TcpwidList.append(tcpwin);
   Tcpwid_friendID_List.append(friend_id);

   TCPWIN_SIGNAL_CONNECTED(tcpwin);

   tcpwin->show();
}

void Communication::Group_Chat(QString group_name)
{
    int group_id = Get_Group_ID(group_name);
    Groupwid *groupwid = new Groupwid();
    groupwid->setWindowTitle(group_name);

    /*加载群聊好友列表*/
    Loat_Group_Friend_List(groupwid->ui->treeWidget);

    groupwid_List.append(groupwid);
    group_ID_List.append(group_id);

    UDPWID_SIGNAL_CONNECTED(groupwid,group_id);

    groupwid->show();
}
/*好友聊天窗口界面的所有控件的信号关联*/
void Communication::TCPWIN_SIGNAL_CONNECTED(Tcpwid *tcpwin)
{
    /*聊天窗口关闭时，从管理容器中除去聊天窗口和ID*/
    connect(tcpwin->ui->closeBt,&QPushButton::clicked,this,[=](){
        Tcpwid_friendID_List.removeOne(Get_Tcpwid_FriendID_One(tcpwin));
        TcpwidList.removeOne(tcpwin);
        tcpwin->hide();
    });
    /*发送信息，并显示到聊天窗口上*/
    connect(tcpwin->ui->sendBt,&QPushButton::clicked,this,[=](){
        M_Send_Friend_Msg(tcpwin);
    });

    connect(this,&Communication::Send_express_success_singals,tcpwin,&Tcpwid::Recv_Send_express_signals);
}

void Communication::UDPWID_SIGNAL_CONNECTED(Groupwid *groupwid,int group_id)
{
    /*聊天窗口关闭时，从管理容器中除去聊天窗口和ID*/
    connect(groupwid->ui->closeBt_2,&QPushButton::clicked,this,[=](){
        group_ID_List.removeOne(group_id);
        groupwid_List.removeOne(groupwid);
        groupwid->hide();
    });
    /*发送信息，并显示到聊天窗口上*/
    connect(groupwid->ui->sendBt_2,&QPushButton::clicked,this,[=](){
        M_Send_Group_Msg(groupwid,group_id);
    });

    connect(this,&Communication::Send_express_Group_singals,groupwid,&Groupwid::Recv_Send_Group_express_signals);
}

/**@处理服务器信息
 * type
 * 1) USER_RECV_FRIEND_MSG
 * */
void Communication::M_Recv_Msg()
{
    qDebug()<<QStringLiteral("接受消息");
    QByteArray bytearray = m_socket->readAll();
    QJsonParseError jsonerror;
    QJsonDocument document = QJsonDocument::fromJson(bytearray,&jsonerror);
    if(!document.isNull() && (jsonerror.error == QJsonParseError::NoError))
    {
        if(document.isObject())
        {
              QJsonObject jsonObj = document.object();
              QJsonValue dataVal = jsonObj.value("data");
              int _type = jsonObj.value("type").toInt();
              switch(_type)
              {
                    case USER_RECV_FRIEND_MSG:
                         M_Recv_Friend_Msg(dataVal);break;

                    case USER_ADDFRIEND_SUCCESS:
                         M_Recv_Add_Friend_Success(dataVal);break;

                    case USER_ADDFRIEND_NO:
                         M_Recv_Add_Friend_No(dataVal);break;

                    case USER_ADDFRIEND_Widget:
                         M_Recv_Add_Friend_Widget(dataVal);break;

                    case USER_ONLINE:
                         M_Recv_User_Online(dataVal);break;

                    case USER_DISCONNECTED:
                         M_Recv_User_Disconnected(dataVal);break;

                    case USER_GET_FRIEND_STATE:
                         M_Recv_User_State(dataVal);break;

                    case USER_ADDGROUP_SUCCESS:
                         M_Recv_Add_Group_Succsee(dataVal);break;

                    case USER_ADDGROUP_NO:
                         M_Recv_Add_Group_No(dataVal);break;

                    case USER_GROUP_MSG:
                         M_Recv_Group_Msg(dataVal);break;

                    case USER_GROUP_ADD_NEWFRIEND:
                         M_Recv_Group_Join_Newfriend(dataVal);break;
              }
        }
    }
}
/*@接收好友信息
 * USER_RECV_FRIEND_MSG
 *
 * */
void Communication::M_Recv_Friend_Msg(QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject dataobj = dataVal.toObject();
        int friend_id = dataobj.value("from_id").toInt();
        QString text = dataobj.value("text").toString();
        int type = dataobj.value("type").toInt();
        QString current_date =current_date_time.currentDateTime().toString("yyyy.MM.dd hh:mm:ss ddd");
        /*实现信息接收自动检索好友ID弹出聊天窗口*/
        if(is_Open_QWidget_Tcp(friend_id))
        {
            Show_Chat_Currtime(Get_TcpwidList_One(friend_id),nullptr);
            /*判断内容是文本、表情、文件*/
            if(type == USER_EXPRESSION_MSG)
            {
                /*根据好友ID检索到相对应的聊天窗口，并将信息发送到聊天窗口*/
                Show_Friend_Chat_Currtext(text,Get_TcpwidList_One(friend_id));
            }
            else if(type == USER_RECV_FRIEND_MSG)
            Show_Friend_Chat_Currtext(Mycpp::M_QString_Spilt_Friend + text,Get_TcpwidList_One(friend_id));
            Save_Friend_Msg_One(friend_id,Mycpp::USERID,Mycpp::M_QString_Spilt_Friend +text,current_date);
        }
        else/*自动弹出聊天窗口*/
        {
            QString friend_name = Get_Friend_name(friend_id);
            qDebug()<<QStringLiteral("Get_Friend_name")<<friend_name;
            Save_Friend_Msg_One(friend_id,Mycpp::USERID,Mycpp::M_QString_Spilt_Friend +text,current_date);
            TCPchat(friend_name);
        }
    }
}
/*@接收群聊信息
 * USER_RECV_FRIEND_MSG
 *
 * */
void Communication::M_Recv_Group_Msg(QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject dataobj = dataVal.toObject();
        qDebug()<<QStringLiteral("接收群聊信息")<<dataobj;
        int group_id = dataobj.value("group_id").toInt();
        QString user_name = Get_Friend_name(dataobj.value("user_id").toInt());
        QString text = dataobj.value("text").toString();
        QString current_date =current_date_time.currentDateTime().toString("yyyy.MM.dd hh:mm:ss ddd");

        /*实现信息接收自动检索群聊ID弹出聊天窗口*/
        if(is_Open_QWidget_Group(group_id))
        {
            /*根据群聊ID检索到相对应的聊天窗口，并将信息发送到聊天窗口*/
            Show_Chat_Currtime(nullptr, Get_GroupwidList_One(group_id));
            /*检索内容类型，表情、文件、文本内容*/
            if(text.contains(Mycpp::QStringspilt))
            {
                Show_Friend_Group_Chat_Currtext(text,Get_GroupwidList_One(group_id));
            }
            else
            {
                Show_Friend_Group_Chat_Currtext(Mycpp::M_QString_Spilt_Friend + text,Get_GroupwidList_One(group_id));
            }
            //Save_Friend_Msg_One(friend_id,Mycpp::USERID,QString(QStringLiteral("对方：")) +text,current_date);
        }
        else/*自动弹出聊天窗口*/
        {
            QString group_name = Get_Group_Name(group_id);
            Group_Chat(group_name);
        }
    }
}
/*@新成员加入群聊数据库
 * USER_GROUP_ADD_NEWFRIEND
 *
 * */
void Communication::M_Recv_Group_Join_Newfriend(QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject dataobj = dataVal.toObject();
        int group_id = dataobj.value("group_id").toInt();
        int user_id = dataobj.value("user_id").toInt();
        QString group_name = dataobj.value("group_name").toString();

        Add_Group_database_insert(group_id,user_id,group_name);
    }

}
/*@发送好友聊天信息给服务器
 * USER_CHAR_MSG
 *
 * */
void Communication::M_Send_Friend_Msg(Tcpwid *tcpwid)
{
     int friend_id = Get_Tcpwid_FriendID_One(tcpwid);
     QString text;
     int type;
     QString current_date =current_date_time.currentDateTime().toString("yyyy.MM.dd hh:mm:ss ddd");
     Show_Chat_Currtime(tcpwid,nullptr);
     /*判断发送内容,文本、表情、文件*/
     if(tcpwid->Send_express_List.count()==0)
     {
         text = tcpwid->ui->sendEdit->toPlainText();
         type = USER_RECV_FRIEND_MSG;
         Show_Self_Chat_Currtext(Mycpp::M_QString_Spilt_My + text,tcpwid);
     }

     else
     {
         for(int i=0;i< tcpwid->Send_express_List.count();i++)
         {
             text +=Mycpp::QStringspilt + tcpwid->Send_express_List.at(i);
         }
         Show_Self_Chat_Currtext(Mycpp::M_QString_Spilt_My + text,tcpwid);
         type = USER_EXPRESSION_MSG;
     }
     tcpwid->ui->sendEdit->setText("");

     QJsonObject object;
     QJsonObject data_obj;
     data_obj.insert("friendid",friend_id);
     data_obj.insert("text",text);
     data_obj.insert("from_id",Mycpp::USERID);
     data_obj.insert("type",type);

     object.insert("data",data_obj);
     object.insert("type",USER_CHAR_MSG);


     QJsonDocument document;
     document.setObject(object);

     qDebug()<<QStringLiteral("发送内容数据")<<document.toJson()<<text;
     //发送JSON文档
     m_socket->write(document.toJson(QJsonDocument::Compact));
     Save_Friend_Msg_One(friend_id,Mycpp::USERID,Mycpp::M_QString_Spilt_My +text,current_date);
     emit Send_express_success_singals();
}

void Communication::M_Send_Group_Msg(Groupwid *groupwid,int group_id)
{
    QString text = groupwid->ui->sendEdit_2->toPlainText();
    groupwid->ui->sendEdit->setText("");
    Show_Chat_Currtime(nullptr,groupwid);
    QString current_date =current_date_time.currentDateTime().toString("yyyy.MM.dd hh:mm:ss ddd");
    groupwid->ui->sendEdit_2->setText("");

    if(groupwid->Send_express_List.count() == 0)
    {
        Show_Self_Group_Chat_Currtext(Mycpp::M_QString_Spilt_My + text,groupwid);
    }
    else
    {
        for(int i=0;i< groupwid->Send_express_List.count();i++)
        {
            text +=Mycpp::QStringspilt + groupwid->Send_express_List.at(i);
        }
        Show_Self_Group_Chat_Currtext(Mycpp::M_QString_Spilt_My + text,groupwid);
    }

    QJsonObject object;
    QJsonObject data_obj;
    data_obj.insert("group_id",group_id);
    data_obj.insert("group_name",Get_Group_Name(group_id));
    data_obj.insert("text",text);
    data_obj.insert("user_id",Mycpp::USERID);

    object.insert("data",data_obj);
    object.insert("type",USER_GROUP_MSG);

    QJsonDocument document;
    document.setObject(object);

    qDebug()<<QStringLiteral("发送群聊内容数据")<<document.toJson();
    //发送JSON文档
    m_socket->write(document.toJson(QJsonDocument::Compact));
    //Save_Friend_Msg_One(friend_id,Mycpp::USERID,QString(QStringLiteral("自己：")) +text,current_date);
    emit Send_express_Group_singals();
}

void Communication::M_Recv_User_Online(QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject dataobj = dataVal.toObject();
        QString friend_name = dataobj.value("name").toString();
        tree->Updata_Friend_State(friend_name,USER_ONLINE);
        tree->User_Online_Or_Disconnected_Msg(USER_ONLINE);
    }
}

void Communication::M_Recv_User_Disconnected(QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        qDebug()<<QStringLiteral("好友下线");
        QJsonObject dataobj = dataVal.toObject();
        QString friend_name = dataobj.value("name").toString();
        tree->Updata_Friend_State(friend_name,USER_DISCONNECTED);
        tree->User_Online_Or_Disconnected_Msg(USER_DISCONNECTED);
    }
}

int Communication::M_Recv_User_State(QJsonValue &dataVal)
{

    return 0;
}

Communication::~Communication()
{
    delete ui;
}
//多媒体应用
void Communication::on_Multimedia_Bt_clicked()
{
    qDebug()<<QStringLiteral("多媒体");
    mul_play = new Multimedia();
    mul_play->show();
    connect(mul_play,SIGNAL(back_com_signal()),this,SLOT(recv_from_mult_back()));
    //禁用按钮
    ui->Multimedia_Bt->setEnabled(false);
}


void Communication::recv_from_mult_back()
{
    mul_play->close();
    //激活按钮
    ui->Multimedia_Bt->setEnabled(true);
}
#if 0
void Communication::on_pushButton_2_clicked()
{
    ui->stackedWidget->nextPage();
}
#endif

void Communication::Create_Widgets()
{
    QWidget *friend_widget = new QWidget(this);
    friend_widget->setFixedSize(QSize(380,340));
    friend_widget->move(QPoint(0,150));
    friend_widget->hide();
    Widgets_List.append(friend_widget);

    QWidget *group_widget = new QWidget(this);
    group_widget->setFixedSize(QSize(380,340));
    group_widget->move(QPoint(0,150));
    group_widget->hide();
    Widgets_List.append(group_widget);

    QWidget *chart_widget = new QWidget(this);
    chart_widget->setFixedSize(QSize(380,340));
    chart_widget->move(QPoint(0,150));
    chart_widget->hide();
    Widgets_List.append(chart_widget);

    QWidget *media_widget = new QWidget(this);
    media_widget->setFixedSize(QSize(380,340));
    media_widget->move(QPoint(0,150));
    media_widget->hide();
    Widgets_List.append(media_widget);

    Curr_Widget = Widgets_List.at(USER_FRIEND_WIDGET);
    Curr_Widget->show();
}

void Communication::Set_Widget(int Index)
{

}

QWidget * Communication::Get_Widget(int Index)
{
    return Widgets_List.at(Index);
}

void Communication::Set_Friend_Widget()
{

}

void Communication::Set_Group_Widget()
{

}

void Communication::Show_Chat_Currtime(Tcpwid *tcpwid,Groupwid *groupwid)
{
    QListWidgetItem *item = new QListWidgetItem;
    ChatContentCirCular *chatwid = new ChatContentCirCular();
    chatwid->settalkTime(current_date_time.currentDateTime());
    chatwid->run(SHOW_TYPE_TIME);
    if(tcpwid != nullptr)
    {
        tcpwid->ui->recordEdit->addItem(item);
        tcpwid->ui->recordEdit->setItemWidget(item,chatwid);
    }
    if(groupwid != nullptr)
    {
        groupwid->ui->recordEdit->addItem(item);
        groupwid->ui->recordEdit->setItemWidget(item,chatwid);
    }
    chatwid->show();
}

void Communication::Show_Self_Chat_Currtext(QString text, Tcpwid *tcpwid)
{
    QListWidgetItem *item = new QListWidgetItem;
    ChatContentCirCular *chatwid = new ChatContentCirCular();
    chatwid->setuserIconName(":/resource/UserHead.jpg");
    QStringList express_msg_spilt;
    express_msg_spilt = text.split(Mycpp::QStringspilt);
    express_msg_spilt.removeFirst();

    if(text.contains(Mycpp::QStringspilt))
    {
        QString express_show_width = "";
        for(int i=0;i<express_msg_spilt.count();i++)
        {
            express_show_width = express_show_width + "   ";
            tcpwid->m_curwidth += 24;
            QLabel *pic = new QLabel(chatwid);
            pic->move(tcpwid->m_curwidth,25);
            QMovie *movie = new QMovie(express_msg_spilt.at(i));
            pic->setScaledContents(true);
            pic->setMovie(movie);
            movie->start();
        }
        chatwid->setuserChatContent(express_show_width);
    }
    else
    {
        chatwid->setuserChatContent(text.split(Mycpp::M_QString_Spilt_My).at(1));
    }

    chatwid->run(SHOW_TYPE_LEFT);
    chatwid->setFixedSize(tcpwid->ui->recordEdit->width(),80);

    tcpwid->ui->recordEdit->addItem(item);
    tcpwid->ui->recordEdit->setItemWidget(item,chatwid);
    chatwid->show();

    QListWidgetItem *_item = new QListWidgetItem;
    ChatContentCirCular *_chatwid = new ChatContentCirCular();
    _chatwid->setFixedSize(tcpwid->ui->recordEdit->width(),40);
    tcpwid->ui->recordEdit->addItem(_item);
    tcpwid->ui->recordEdit->setItemWidget(_item,_chatwid);
    _chatwid->show();

    tcpwid->m_curwidth = 80;
}

void Communication::Show_Friend_Chat_Currtext(QString text,Tcpwid *tcpwid)
{
    QListWidgetItem *item = new QListWidgetItem;
    ChatContentCirCular *chatwid = new ChatContentCirCular();
    chatwid->setuserIconName(":/resource/0.bmp");
    QStringList express_msg_spilt;
    express_msg_spilt = text.split(Mycpp::QStringspilt);
    express_msg_spilt.removeFirst();

    if(text.contains(Mycpp::QStringspilt))
    {   
        QString express_show_width = "";
        for(int i=0;i<express_msg_spilt.count();i++)
        {
            express_show_width = express_show_width + "   ";
            tcpwid->m_curwidth += 24;
            QLabel *pic = new QLabel(chatwid);
            pic->move(tcpwid->ui->recordEdit->width() - tcpwid->m_curwidth,25);
            QMovie *movie = new QMovie(express_msg_spilt.at(i));
            pic->setScaledContents(true);
            pic->setMovie(movie);
            movie->start();
        }
        chatwid->setuserChatContent(express_show_width);
    }
    else
    {
        chatwid->setuserChatContent(text.split(Mycpp::M_QString_Spilt_Friend).at(1));
    }

    chatwid->run(SHOW_TYPE_RIGHT);
    chatwid->setFixedSize(tcpwid->ui->recordEdit->width(),80);

    tcpwid->ui->recordEdit->addItem(item);
    tcpwid->ui->recordEdit->setItemWidget(item,chatwid);
    chatwid->show();

    QListWidgetItem *_item = new QListWidgetItem;
    ChatContentCirCular *_chatwid = new ChatContentCirCular();
    _chatwid->setFixedSize(tcpwid->ui->recordEdit->width(),40);
    tcpwid->ui->recordEdit->addItem(_item);
    tcpwid->ui->recordEdit->setItemWidget(_item,_chatwid);
    _chatwid->show();

    tcpwid->m_curwidth = 80;
}

void Communication::Show_Self_Group_Chat_Currtext(QString text, Groupwid *groupwid)
{
    QListWidgetItem *item = new QListWidgetItem;
    ChatContentCirCular *chatwid = new ChatContentCirCular();
    chatwid->setuserIconName(":/resource/0.bmp");

    QStringList express_msg_spilt;
    express_msg_spilt = text.split(Mycpp::QStringspilt);
    express_msg_spilt.removeFirst();

    if(text.contains(Mycpp::QStringspilt))
    {
        QString express_show_width = "";
        for(int i=0;i<express_msg_spilt.count();i++)
        {
            express_show_width = express_show_width + "   ";
            groupwid->m_curwidth += 24;
            QLabel *pic = new QLabel(chatwid);
            pic->move(groupwid->m_curwidth,25);
            QMovie *movie = new QMovie(express_msg_spilt.at(i));
            pic->setScaledContents(true);
            pic->setMovie(movie);
            movie->start();
        }
        chatwid->setuserChatContent(express_show_width);
    }
    else
    {
        chatwid->setuserChatContent(text.split(Mycpp::M_QString_Spilt_My).at(1));
    }

    chatwid->run(SHOW_TYPE_LEFT);
    chatwid->setFixedSize(groupwid->ui->recordEdit->width(),80);

    groupwid->ui->recordEdit->addItem(item);
    groupwid->ui->recordEdit->setItemWidget(item,chatwid);
    chatwid->show();

    QListWidgetItem *_item = new QListWidgetItem;
    ChatContentCirCular *_chatwid = new ChatContentCirCular();
    _chatwid->setFixedSize(groupwid->ui->recordEdit->width(),40);
    groupwid->ui->recordEdit->addItem(_item);
    groupwid->ui->recordEdit->setItemWidget(_item,_chatwid);
    _chatwid->show();

    groupwid->m_curwidth = 80;
}

void Communication::Show_Friend_Group_Chat_Currtext(QString text, Groupwid *groupwid)
{
    QListWidgetItem *item = new QListWidgetItem;
    ChatContentCirCular *chatwid = new ChatContentCirCular();
    chatwid->setuserIconName(":/resource/0.bmp");
    QStringList express_msg_spilt;
    express_msg_spilt = text.split(Mycpp::QStringspilt);
    express_msg_spilt.removeFirst();
    if(text.contains(Mycpp::QStringspilt))
    {
        QString express_show_width = "";
        for(int i=0;i<express_msg_spilt.count();i++)
        {
            express_show_width = express_show_width + "   ";
            groupwid->m_curwidth += 24;
            QLabel *pic = new QLabel(chatwid);
            pic->move(groupwid->ui->recordEdit->width() - groupwid->m_curwidth,25);
            QMovie *movie = new QMovie(express_msg_spilt.at(i));
            pic->setScaledContents(true);
            pic->setMovie(movie);
            movie->start();
        }
        chatwid->setuserChatContent(express_show_width);
    }
    else
    {
        chatwid->setuserChatContent(text.split(Mycpp::M_QString_Spilt_Friend).at(1));
    }
    chatwid->run(SHOW_TYPE_RIGHT);
    chatwid->setFixedSize(groupwid->ui->recordEdit->width(),80);

    groupwid->ui->recordEdit->addItem(item);
    groupwid->ui->recordEdit->setItemWidget(item,chatwid);
    chatwid->show();

    QListWidgetItem *_item = new QListWidgetItem;
    ChatContentCirCular *_chatwid = new ChatContentCirCular();
    _chatwid->setFixedSize(groupwid->ui->recordEdit->width(),40);
    groupwid->ui->recordEdit->addItem(_item);
    groupwid->ui->recordEdit->setItemWidget(_item,_chatwid);
    _chatwid->show();

    groupwid->m_curwidth = 80;
}

void Communication::on_friend_bt_clicked()
{
    Curr_Widget->hide();
    Curr_Widget = Widgets_List.at(USER_FRIEND_WIDGET);
    Curr_Widget->show();
    qDebug()<<"好友列表";
}

void Communication::on_group_bt_clicked()
{
    Curr_Widget->hide();
    Curr_Widget = Widgets_List.at(USER_GROUP_WIDGET);
    Curr_Widget->show();
    qDebug()<<"群聊列表";

}

void Communication::on_other_operations_bt_clicked()
{
    if(is_other_operations)
    {
        other_widget->show();
        is_other_operations = false;
    }
    else
    {
        other_widget->hide();
        is_other_operations = true;
    }
}

void Communication::exit_login()
{
    /*通知服务器用户下线*/
    QJsonObject send_disconnected;
    QJsonObject data_obj;
    data_obj.insert("userid",Mycpp::USERID);
    data_obj.insert("username",Mycpp::USERNAME);
    data_obj.insert("userpass","");
    data_obj.insert("text","");

    send_disconnected.insert("data",data_obj);
    send_disconnected.insert("from_id",Mycpp::USERID);
    send_disconnected.insert("type",USER_DISCONNECTED);

    QJsonDocument document;
    document.setObject(send_disconnected);
    m_socket->write(document.toJson(QJsonDocument::Compact));

    this->close();
    emit login_widget_show_signals();
    this->deleteLater();
}
