#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QHostInfo>
#include <QTcpSocket>
#include <QMessageBox>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <myinfo.h>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString("%1").arg(Server_port));
    Server = new QTcpServer;
    adddatabase();
    Create_Group_DataBase();
    //Loat_DataBase();

    connect_timer = new QTimer();
    connect(connect_timer,&QTimer::timeout,this,&MainWindow::New_Client_Connected);
    connect_timer->start(3000);
}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        tcpClientSocketList.at(i)->deleteLater();
    }
}

void MainWindow::New_Client_Connected()
{
    //将准备连接的客户端的套接字传过来
    connect(Server,&QTcpServer::newConnection,this,[=](){
        QTcpSocket *Writ_Read_socket = new QTcpSocket;
        Writ_Read_socket = Server->nextPendingConnection();
    //提示有客户端连接成功
    ui->informtext->append("********新客户端连接成功**********");
    connect_timer->stop();
    //若收到客户端连接，触发准备读取信息的信号
    connect(Writ_Read_socket,&QTcpSocket::readyRead,this,[=](){
           qDebug()<<"读取信息";
           RecvClient_Msg(Writ_Read_socket);
     });
    });
}

void MainWindow::adddatabase()
{
    //添加数据库
    User_db = QSqlDatabase::addDatabase("QSQLITE","USER");
    User_db.setDatabaseName("user.db");

    if(!User_db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }
    //创建表格，保存账号、密码、状态
    QString createname = "create table if not exists user(id integer primary key autoincrement,username text not NULL,password text not NULL,status int )";
    QSqlQuery query(createname,QSqlDatabase::database("USER"));
    if(!query.exec())
    {
        qDebug()<<"create error";
    }
    else {
        qDebug()<<"create ok";
    }
}

void MainWindow::Create_Group_DataBase()
{
    //添加数据库
    User_db = QSqlDatabase::addDatabase("QSQLITE","USER");
    User_db.setDatabaseName("user.db");

    if(!User_db.open())
    {
        qDebug()<<"open group sql error";
    }
    else {
        qDebug()<<"open group ok";
    }
    //创建表格，保存群聊ID、用户ID、群聊呢称
    QString createname = "create table if not exists user_group(group_id int not NULL,user_id int not NULL,group_name text not NULL)";
    QSqlQuery query(createname,QSqlDatabase::database("USER"));
    if(!query.exec())
    {
        qDebug()<<"create group error";
    }
    else {
        qDebug()<<"create group ok";
    }
}
//加载数据库
void MainWindow::Loat_DataBase()
{
    QString Client_data = QString("select * from user");
    QSqlQuery query(QSqlDatabase::database("USER"));
    query.exec(Client_data);
     ClIENT_COUNT++;
    if(query.next())
    {
        ClIENT_COUNT++;//加载客户端个数
    }

    Client_data = QString("select * from user_group");
    QList <int >group_id;
    int i;
    query.exec(Client_data);
    if(query.next())
    {
        for(i=0;i<group_id.count();i++)
        {
            if(query.value(1) == group_id.at(i))
                break;
        }
        if(i == group_id.count())
        group_id.append(query.value(1).toInt());
    }
    USER_GROUP_COUNT == group_id.count();//加载群聊个数
}
//接收信息
void MainWindow::RecvClient_Msg(QTcpSocket *Writ_Read_socket)
{
    QByteArray bytearray = Writ_Read_socket->readAll();
    qDebug()<<bytearray;
    QJsonParseError jsonerror ;
    QJsonDocument document = QJsonDocument::fromJson(bytearray,&jsonerror);
    if(!document.isNull() && (jsonerror.error == QJsonParseError::NoError))
    {
        if(document.isObject())
        {
            QJsonObject jsonObj = document.object();
            int nType = jsonObj.value("type").toInt();
            QJsonValue dataVal = jsonObj.value("data");
            int from_id = jsonObj.value("from_id").toInt();
            switch(nType)
            {
                case USER_REGIN:
                     M_USER_REGIN(dataVal,Writ_Read_socket);break;

                case USER_CHAR_MSG:
                     M_USER_CHAR_MSG(dataVal);break;

                case USER_LOGIN:
                     M_USER_LOGIN(dataVal,Writ_Read_socket);break;

                case USER_ADDFRIEND:
                     M_USER_ADDFRIEND(dataVal,Writ_Read_socket,from_id);break;

                case USER_ADDGROUP:
                     M_USER_GROUP(dataVal,Writ_Read_socket);break;

                case USER_GROUP_MSG:
                     M_USER_GROUP_MSG(dataVal);break;

                case USER_DISCONNECTED:
                     M_USER_DICONNECTED(dataVal);break;

            }
        }
    }
}
//返回客户端的JSON
QJsonDocument MainWindow::JSON_BACK_MSG(int id, QString name, QString passwd, QString text, int type)
{
    QJsonObject json;
    QJsonObject data_object;
    data_object.insert("id", id);
    data_object.insert("name", name);
    data_object.insert("passwd", passwd);
    data_object.insert("text",text);

    json.insert("data",data_object);
    json.insert("type",type);

    // 构建 Json 文档
    QJsonDocument document;
    document.setObject(json);
    qDebug()<<document.toJson();
    return document;
}
//解析用户注册的个人信息
void MainWindow::M_USER_REGIN(QJsonValue &dataVal,QTcpSocket *Writ_Read_socket)
{
    // data 的 value 是对象
    if (dataVal.isObject())
    {
        QJsonObject dataObj = dataVal.toObject();

        QString strName = dataObj.value("username").toString();
        QString strPwd = dataObj.value("userpass").toString();
        int strId = dataObj.value("userid").toInt();

        //用户名没注册过
        if(!isReg_Username(strName))
        {
            // 返回客户端
            qDebug()<<"没注册GUO";
            strId = ++ClIENT_COUNT;//分配ID

            // 构建 Json 文档
            QJsonDocument document = JSON_BACK_MSG(strId,strName,strPwd,"",USER_REGIN_SUCCESS);

            Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
            Save_Userinfo_database(strId,strName,strPwd);//保存到数据库
        }
         else
        {
            qDebug()<<"注册过";
            // 构建 Json 文档
            QJsonDocument document = JSON_BACK_MSG(strId,strName,strPwd,"",USER_REGIN_SUCCESS);
            Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
        }
    }
}

//解析用户发送聊天信息
void MainWindow::M_USER_CHAR_MSG(QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject())
    {
        QJsonObject dataObj = dataVal.toObject();

        int Friend_ID = dataObj.value("friendid").toInt();
        //USER_ID = dataObj.value("from_id").toInt();
        QString send_text = dataObj.value("text").toString();
        int type = dataObj.value("type").toInt();

        //将发送者的ID和内容包装JSON发送到好友
        QJsonObject send_json ;
        QJsonObject send_data;
        send_data.insert("text",send_text);
        send_data.insert("from_id",dataObj.value("from_id").toInt());
        send_data.insert("type",type);

        send_json.insert("type",USER_RECV_FRIEND_MSG);
        send_json.insert("data",send_data);

        QJsonDocument document;
        document.setObject(send_json);
        //查找好友ID对应的套接字
        for(int i=0;i<Client_ID.count();i++)
        {
            if(Friend_ID == Client_ID.at(i))
            {
                /*查询对方是否在线*/
                if(tcpClientSocketList.at(i)->state() == QAbstractSocket::ConnectedState)
                tcpClientSocketList.at(i)->write(document.toJson(QJsonDocument::Compact));
            }
        }
    }
}
/*@解析群聊信息
 * 转发到其他在群聊的好友
 *
 * */
void MainWindow::M_USER_GROUP_MSG(QJsonValue &dataVal)
{
    if (dataVal.isObject())
    {
        QJsonObject dataObj = dataVal.toObject();
        qDebug()<<QStringLiteral("接收群聊信息")<<dataObj;
        int group_id = dataObj.value("group_id").toInt();
        int user_id = dataObj.value("user_id").toInt();
        QList <int> On_Group_UserID_List =  Get_Group_UserID(group_id,user_id);
         qDebug()<<QStringLiteral("转发群聊信息")<<On_Group_UserID_List;
        QJsonObject send_obj;

        send_obj.insert("data",dataObj);
        send_obj.insert("type",USER_GROUP_MSG);
        QJsonDocument document;
        document.setObject(send_obj);
        for(int i=0;i<On_Group_UserID_List.count();i++)
        {
            for(int j=0;j<Client_ID.count();j++)
            {
                if(Client_ID.at(j) == On_Group_UserID_List.at(i))
                    tcpClientSocketList.at(j)->write(document.toJson(QJsonDocument::Compact));
            }
        }
    }

}
//解析用户登录信息
void MainWindow::M_USER_LOGIN(QJsonValue &dataVal,QTcpSocket *Writ_Read_socket)
{
    qDebug()<<"解析登录信息";
    if(dataVal.isObject())
    {
        QJsonObject _data = dataVal.toObject();
        QString user_name = _data.value("username").toString();
        QString user_pass = _data.value("userpass").toString();

        //验证用户名和密码是否存在
        if(isLogin_User(user_name,user_pass))
        {
            qDebug()<<"登录信息存在";
            //验证成功加入客户端管理器
            tcpClientSocketList.append(Writ_Read_socket);
            //同时保存该客户端的ID,后期根据客户端的ID找到相对应的套接字
            Client_ID.append(Get_User_ID(user_name));
            // 构建 Json 文档
            QJsonDocument document = JSON_BACK_MSG(Get_User_ID(user_name),user_name,user_pass,"",USER_LOGIN_SUCCESS);
            Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
            connect(Writ_Read_socket,&QTcpSocket::disconnected,this,&MainWindow::Client_disconnect);

            /*用户上线，发送上线信息给其他好友，并更新数据库好友状态*/
            document = JSON_BACK_MSG(Get_User_ID(user_name),user_name,user_pass,"",USER_ONLINE);
            for(int i=0;i<Client_ID.count();i++)
            {
                if(Client_ID.at(i) != Get_User_ID(user_name))
                    tcpClientSocketList.at(i)->write(document.toJson(QJsonDocument::Compact));
            }
            Updata_User_Database_State(user_name,USER_ONLINE);
        }
        else
        {
            qDebug()<<"登录信息不存在";
            // 构建 Json 文档
            QJsonDocument document = JSON_BACK_MSG(Get_User_ID(user_name),user_name,user_pass,"",USER_LOGIN_NO);
            Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
        }

    }
}
//解析添加好友信息
void MainWindow::M_USER_ADDFRIEND(QJsonValue &dataVal, QTcpSocket *Writ_Read_socket,int from_id)
{
    if(dataVal.isObject())
    {
        QJsonObject _data = dataVal.toObject();
        QString friend_name = _data.value("username").toString();
        if(isAddFriend_Username(friend_name))
        {
            qDebug()<<"用户存在，添加成功";
            QJsonDocument document = JSON_BACK_MSG(Get_User_ID(friend_name),friend_name,"","",USER_ADDFRIEND_SUCCESS);
            Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
            /*实现向对方发出添加好友邀请*/
            document = JSON_BACK_MSG(from_id,Get_User_name(from_id),"","",USER_ADDFRIEND_Widget);
            for(int i=0;i<Client_ID.count();i++)
            {
                if(Client_ID.at(i) == Get_User_ID(friend_name))
                {
                    tcpClientSocketList.at(i)->write(document.toJson(QJsonDocument::Compact));
                    break;
                }
            }
        }
        else
        {
            qDebug()<<"用户不存在，添加失败";
            QJsonDocument document = JSON_BACK_MSG(-1,friend_name,"","",USER_ADDFRIEND_NO);
            Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
        }
    }
}
/*@解析添加群聊信息
 *
 * */
void MainWindow::M_USER_GROUP(QJsonValue &dataVal, QTcpSocket *Writ_Read_socket)
{
    if(dataVal.isObject())
    {
        QJsonObject _data = dataVal.toObject();
        QString group_name = _data.value("group_name").toString();
        int group_id  = Get_Group_ID(group_name);
        int user_id  = _data.value("user_id").toInt();

        QJsonObject group_obj ;
        QJsonObject data_obj;
        data_obj.insert("user_id",user_id);
        data_obj.insert("group_name",group_name);

        if(!isAddGroup_Groupname(group_name))
        {
            USER_GROUP_COUNT++;
            Save_User_Group_database(USER_GROUP_COUNT,user_id,group_name);
            data_obj.insert("group_id",USER_GROUP_COUNT);
        }
        else
        {
            qDebug()<<QStringLiteral("该群存在")<<group_id;
            Save_User_Group_database(group_id,user_id,group_name);
            data_obj.insert("group_id",group_id);
        }

        group_obj.insert("data",data_obj);
        group_obj.insert("type",USER_ADDGROUP_SUCCESS);
        QJsonDocument document ;
        document.setObject(group_obj);
        Writ_Read_socket->write(document.toJson(QJsonDocument::Compact));
#if 0
        /*通知群里已在成员，新成员加入*/
        QList <int > other_userid_list = Get_Group_Other_Userid(group_id);
        for(int i=0;i<other_userid_list.count();i++)
        {
            for(int j=0;j<Client_ID.count();j++)
            {
                if(Client_ID.at(j) == other_userid_list.at(i))
                {
                    group_obj.insert("type",USER_GROUP_ADD_NEWFRIEND);
                    tcpClientSocketList.at(j)->write(document.toJson(QJsonDocument::Compact));
                }
            }
        }
#endif
    }
}
/**
 * @brief MainWindow::M_USER_DICONNECTED
 * @param dataVal
 */
void MainWindow::M_USER_DICONNECTED(QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject _data = dataVal.toObject();
        int user_id = _data.value("userid").toInt();
        QString user_name = _data.value("username").toString();
        /*客户端断开，处理套接字、ID列表*/
        for(int i=0;i<Client_ID.count();i++)
        {
            if(Client_ID.at(i) == user_id)
            {
                /*通知其他好友状态改变*/
                Send_User_Disconnected_Msg(Client_ID.at(i),user_name,"","",USER_DISCONNECTED,tcpClientSocketList.at(i));
                tcpClientSocketList.removeAt(i);
                Client_ID.removeAt(i);
                break;
            }
        }
    }
}
/*@服务器发送用户下线信息
 *
 * */
void MainWindow::Send_User_Disconnected_Msg(int id, QString name, QString passwd, QString text, int type,QTcpSocket *m_socket)
{
    QJsonDocument document =  JSON_BACK_MSG(id,name,passwd,text,type);
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        if(tcpClientSocketList.at(i) != m_socket)
            tcpClientSocketList.at(i)->write(document.toJson(QJsonDocument::Compact));
    }
    qDebug()<<QStringLiteral("发送用户下线信息")<<document.toJson();
}
/*@更新数据库用户上线信息
 *
 * */
void MainWindow::Updata_User_Database_State(QString name, int state)
{
     QSqlDatabase userdb = QSqlDatabase::addDatabase("QSQLITE");
     userdb.setDatabaseName("user.db");

     if(!userdb.open())
     {
         qDebug()<<"open sql error";
     }
     else {
         qDebug()<<"open ok";
     }

     QString updata_state = QString("update  user set status=%1 where username='%2'").arg(state).arg(name);
     QSqlQuery query;
     if(query.exec(updata_state))
     {
         qDebug()<<QStringLiteral("数据库好友状态更新");
     }
}

QList<int> MainWindow::Get_Group_Other_Userid(int group_id)
{
    QSqlDatabase userdb = QSqlDatabase::addDatabase("QSQLITE");
    userdb.setDatabaseName("user.db");

    if(!userdb.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }
    QList <int > group_other_userid;
    QString other_userid = QString("select * from user_group where group_id='%1'").arg(group_id);
    QSqlQuery query;
    query.exec(other_userid);
    while(query.next())
    {
        qDebug()<<QStringLiteral("获取群里其他好友ID");
        group_other_userid.append(query.value(1).toInt());
    }
    return group_other_userid;
}
/*@客户端断开
 * 好友状态更新
 * 发送好友状态
 * */
void MainWindow::Client_disconnect()
{
   qDebug()<<QStringLiteral("客户端断开");
   QTcpSocket *dis_socket = (QTcpSocket *)this->sender();//返回发送信号的对象指针
   //将断开的客户端从列表中清除
   for(int i=0;i<tcpClientSocketList.count();i++)
   {
       if(dis_socket == tcpClientSocketList.at(i))
       {
           /*用户下线，发送下线信息给好友更新状态,并更新数据库好友状态*/
           Send_User_Disconnected_Msg(Client_ID.at(i),Get_User_name(Client_ID.at(i)),"","",USER_DISCONNECTED,tcpClientSocketList.at(i));
           Updata_User_Database_State(Get_User_name(Client_ID.at(i)),USER_DISCONNECTED);
           tcpClientSocketList.removeAt(i);
           Client_ID.removeAt(i);
       }
   }
   ui->informtext->append(QStringLiteral("客户端断开"));
}

//用户是否注册过
bool MainWindow::isReg_Username(QString username)
{
    qDebug()<<"是否注册过";
    QString sql = QString("select * from user where username='%1'").arg(username);
    QSqlQuery query(QSqlDatabase::database("USER"));
    query.exec(sql);
    //if(query.exec(sql))
        //return true;
    if(!query.next())
    {
         qDebug()<<"select find no";
         return false;
    }
    return true;
}
//该用户是否存在，验证登录
bool MainWindow::isLogin_User(QString user_name, QString user_pass)
{
    qDebug()<<"开始数据库验证登录信息";
    QString usersql = QString("select * from user where username='%1' and password='%2'").arg(user_name).arg(user_pass);
    QSqlQuery query(QSqlDatabase::database("USER"));
    if(!query.exec(usersql))
    {
        qDebug()<<QStringLiteral("查询数据库失败");
    }

    while(query.next())
    {
        return true;
    }
    return false;
}
//添加的好友是否存在
bool MainWindow::isAddFriend_Username(QString add_friend_name)
{
    QString usersql = QString("select * from user where username='%1'").arg(add_friend_name);
    QSqlQuery query(QSqlDatabase::database("USER"));
    query.exec(usersql);

    if(query.next())
    {
        //FRIEND_ID = query.value(0).toInt();
        //qDebug()<<"查询成功，用户存在，可以添加"<<FRIEND_ID;
        return true;
    }
    return false;
}

bool MainWindow::isAddGroup_Groupname(QString group_name)
{
    QString usersql = QString("select * from user_group where group_name='%1'").arg(group_name);
    QSqlQuery query(QSqlDatabase::database("USER"));
    if(!query.exec(usersql))
    {
        qDebug()<<QStringLiteral("查询群数据库失败")<<usersql;
    }
    while(query.next())
    {
        return true;
    }
    return false;
}
//保存用户信息到数据库
void MainWindow::Save_Userinfo_database(int userid, QString username, QString userpass)
{
      //插入保存注册数据
      QString sql = QString("insert into user(id,username,password) values('%1','%2','%3')").arg(userid).arg(username).arg(userpass);
      ui->informtext->append(sql);
      qDebug()<<sql;
      QSqlQuery query(QSqlDatabase::database("USER"));
      if(!query.exec(sql))
      {
          qDebug()<<"insert error";
      }
      else
      {
          qDebug()<<"insert ok";
          //插入成功
          //QMessageBox::information(this,QStringLiteral( "提示"),QStringLiteral("插入成功"));
      }
}

void MainWindow::Save_User_Group_database(int group_id, int user_id, QString group_name)
{
    //插入保存注册数据
    QString sql = QString("insert into user_group(group_id,user_id,group_name) values('%1','%2','%3')").arg(group_id).arg(user_id).arg(group_name);
    ui->informtext->append(sql);
    qDebug()<<sql;
    QSqlQuery query(QSqlDatabase::database("USER"));
    if(!query.exec(sql))
    {
        ui->informtext->append(QStringLiteral("insert user_group.db error"));
    }
    else
    {
        //插入成功
        ui->informtext->append(QStringLiteral("insert user_group.db ok"));
    }
}

QString MainWindow::Get_User_name(int userid)
{
    User_db = QSqlDatabase::addDatabase("QSQLITE","USER");
    User_db.setDatabaseName("user.db");

    if(!User_db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString usersql = QString("select * from user where id='%1'").arg(userid);
    QSqlQuery query(QSqlDatabase::database("USER"));
    query.exec(usersql);

    if(query.next())
    {
        QString username = query.value(1).toString();
        qDebug()<<"查询成功，用户存在，可以添加";
        return username;
    }
    return "";
}

int MainWindow::Get_User_ID(QString username)
{
    User_db = QSqlDatabase::addDatabase("QSQLITE","USER");
    User_db.setDatabaseName("user.db");

    if(!User_db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString usersql = QString("select * from user where username='%1'").arg(username);
    QSqlQuery query(QSqlDatabase::database("USER"));
    query.exec(usersql);

    if(query.next())
    {
        int userid = query.value(0).toInt();
        qDebug()<<"获取用户ID";
        return userid;
    }
    return -1;
}

int MainWindow::Get_Group_ID(QString group_name)
{
    User_db = QSqlDatabase::addDatabase("QSQLITE","USER");
    User_db.setDatabaseName("user.db");

    if(!User_db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }

    QString usersql = QString("select * from user_group where group_name='%1'").arg(group_name);
    QSqlQuery query(QSqlDatabase::database("USER"));
    query.exec(usersql);

    if(query.next())
    {
        int group_id = query.value(0).toInt();
        qDebug()<<"查询成功，用户存在，可以添加"<<group_id;
        return group_id;
    }
    return -1;
}

QList<int> MainWindow::Get_Group_UserID(int group_id,int user_id)
{
    User_db = QSqlDatabase::addDatabase("QSQLITE","USER");
    User_db.setDatabaseName("user.db");

    if(!User_db.open())
    {
        qDebug()<<"open user_group sql error";
    }
    else {
        qDebug()<<"open user_group ok"<<user_id;
    }

    QString usersql = QString("select * from user_group where group_id='%1'").arg(group_id);
    QSqlQuery query(QSqlDatabase::database("USER"));

    QList <int> on_group_userid;
    if(!query.exec(usersql))
        qDebug()<<QStringList("error");
    while(query.next())
    {
        if(query.value(1).toInt() != user_id)
        on_group_userid.append(query.value(1).toInt());
    }
    qDebug()<<on_group_userid;
    return on_group_userid;
}

void MainWindow::on_hostifobt_clicked()
{
    //获取主机用户名
    QString hostname = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(hostname);
    QList<QHostAddress> add = info.addresses();
    ui->textEdit->append(hostname);
    foreach(QHostAddress address,add)
    {
        ui->textEdit->append("**************");
        ui->textEdit->append(address.toString());
    }
}

void MainWindow::on_listenbt_clicked()
{
    if(ui->lineEdit->text().isEmpty())
        return ;
     numifo = ui->lineEdit->text().toInt();//获取端口号
     bool flag = Server->listen(QHostAddress::Any,numifo);
     if(flag)
     {
         QMessageBox::information(this,"提示","监听成功");
         //监听成功后，禁用监听按钮
         ui->listenbt->setEnabled(false);
         //将准备连接的客户端的套接字传过来
         connect(Server,&QTcpServer::newConnection,this,[=](){
             QTcpSocket *Writ_Read_socket = new QTcpSocket;
             Writ_Read_socket = Server->nextPendingConnection();
         //提示有客户端连接成功
         ui->informtext->append("********新客户端连接成功**********");
         connect_timer->stop();
         //若收到客户端连接，触发准备读取信息的信号
         connect(Writ_Read_socket,&QTcpSocket::readyRead,this,[=](){
                qDebug()<<"读取信息";
                RecvClient_Msg(Writ_Read_socket);
          });

         });
     }

     else
     {
         QMessageBox::information(this,"提示","监听失败");
     }

}

void MainWindow::on_sendbt_clicked()
{

}
