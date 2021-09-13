#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

   void New_Client_Connected();

   void adddatabase();

   void Create_Group_DataBase();

   void Loat_DataBase();//加载数据库

   void RecvClient_Msg(QTcpSocket *);

   QJsonDocument JSON_BACK_MSG(int id,QString name,QString passwd,QString text,int type);

   void M_USER_REGIN(QJsonValue &,QTcpSocket *);//用户注册发送的信息

   void M_USER_CHAR_MSG(QJsonValue &);//用户聊天发送的信息

   void M_USER_GROUP_MSG(QJsonValue &);

   void M_USER_LOGIN(QJsonValue &,QTcpSocket *);

   void M_USER_ADDFRIEND(QJsonValue &,QTcpSocket *,int from_id);

   void M_USER_GROUP(QJsonValue &,QTcpSocket *);

   void M_USER_DICONNECTED(QJsonValue &);

   void Save_Userinfo_database(int ,QString ,QString);

   void Save_User_Group_database(int,int,QString);

   QString Get_User_name(int userid);

   int Get_User_ID(QString username);

   int Get_Group_ID(QString group_name);

   QList <int> Get_Group_UserID(int group_id,int user_id);

   bool isReg_Username(QString);

   bool isLogin_User(QString,QString);

   bool isAddFriend_Username(QString );

   bool isAddGroup_Groupname(QString);

   void Send_User_Disconnected_Msg(int id, QString name, QString passwd, QString text, int type,QTcpSocket *);

   void Updata_User_Database_State(QString name,int state);

   QList <int> Get_Group_Other_Userid(int group_id);
private slots:
    void on_hostifobt_clicked();

    void on_listenbt_clicked();

    void on_sendbt_clicked();

    void Client_disconnect();

private:
    Ui::MainWindow *ui;

    QTcpServer *Server;

    int numifo;
    /**@
     * 客户端登录验证成功后保存套接字
     * 根据ID搜索相对应的客户端套接字
     * */
    //在线的客户端列表
    QList<QTcpSocket *> tcpClientSocketList;

    //在线的客户端的IP列表
    QList<int > Client_ID;

    //判断是否是第一次接收信息
    bool recv_first_list[100] = {0};

    //需要转发信息到对方的IP
    QString send_IP;

    //用户数据库
    QSqlDatabase User_db;

    QTimer *connect_timer;
};

#endif // MAINWINDOW_H
