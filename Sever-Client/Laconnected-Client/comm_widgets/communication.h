#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QWidget>
#include <QListWidgetItem>
#include <QTreeWidget>
#include <mediamar/multimedia.h>
#include <QTcpSocket>
#include <QList>
#include <QDateTime>
#include <tcp_udp_socket/groupwid.h>
#include "tcp_udp_socket/tcpwid.h"
#include "addwin.h"
#include "otheroperations.h"

class Treewidget;
namespace Ui {
class Communication;
}

class Communication : public QWidget
{
    Q_OBJECT

public:
    explicit Communication(QTcpSocket *socket);

    ~Communication();

    void acquiesce();//用户默认

    void open_friend_database_show();

    void open_groupbase_show();

    void Create_Friend_Msg_DataBase();

    void Open_Friend_Msg_database();

    int Get_Friend_Count();

    void Get_Friend_State_from_Server(QString name);

    int Get_Friend_ID(QString name);

    int Get_Group_ID(QString name);

    QString Get_Group_Name(int group_id);

    QString Get_Friend_name(int friend_id);

    Tcpwid *Get_TcpwidList_One(int);

    int Get_Tcpwid_FriendID_One(Tcpwid *);

    Groupwid *Get_GroupwidList_One(int);

    int Get_GroupID_One(Groupwid *);

    void Get_Chart_Send_express(QUrl);

    QStringList Get_Friend_Msg_Ten(int friend_id,int user_id);

    int Get_Friend_Msg_Num(int friend_id ,int user_id);

    void Save_Friend_Msg_One(int friend_id,int user_id,QString Msg_text,QString Curr_Time);

    bool is_Have_Ten_Msg(int friend_id,int user_id);

    bool is_Have_Msg(int friend_id,int user_id);

    bool is_Have_Group_Name(QString group_name);

    void Delete_First_Msg(int friend_id,int user_id);

    void TCPWIN_SIGNAL_CONNECTED(Tcpwid *);

    void UDPWID_SIGNAL_CONNECTED(Groupwid *,int);

    void ADD_FRIEND_SIGNAL_CONNECTED(Addwin *);

    void Add_Friend_database_insert(int ,int ,QString);

    void Add_Group_database_insert(int ,int ,QString);

    void M_Recv_Add_Friend_Success(QJsonValue &);

    void M_Recv_Add_Friend_No(QJsonValue &);

    void M_Recv_Add_Friend_Widget(QJsonValue &);

    void M_Recv_Add_Group_Succsee(QJsonValue &);

    void M_Recv_Add_Group_No(QJsonValue &);

    void M_Recv_Msg();

    void M_Recv_Friend_Msg(QJsonValue &);

    void M_Recv_Group_Msg(QJsonValue &);

    void M_Recv_Group_Join_Newfriend(QJsonValue &);

    void M_Send_Friend_Msg(Tcpwid *);

    void M_Send_Group_Msg(Groupwid *,int);

    void M_Recv_User_Online(QJsonValue &);

    void M_Recv_User_Disconnected(QJsonValue &);

    int M_Recv_User_State(QJsonValue &);

    bool is_Open_QWidget_Tcp(int);

    bool is_Open_QWidget_Group(int);

    void is_Socket_State_Read();

    void Add_Friend_SendJson_to_Server(Addwin *addwin);

    void Add_Group_SendJson_to_Sever(Addwin *addwin);

    void Loat_Group_Friend_List(QTreeWidget *);

    void Create_Widgets();

    void Set_Widget(int Index);

    QWidget *Get_Widget(int Index);

    void Set_Friend_Widget();

    void Set_Group_Widget();

    void Show_Chat_Currtime(Tcpwid *,Groupwid *groupwid);

    void Show_Self_Chat_Currtext(QString text,Tcpwid *);

    void Show_Friend_Chat_Currtext(QString text,Tcpwid *);

    void Show_Self_Group_Chat_Currtext(QString text,Groupwid *);

    void Show_Friend_Group_Chat_Currtext(QString text,Groupwid *);

    //void Show_Friend_Chat_Currtext(QString text,Tcpwid *);
public slots:
    void TCPchat(QString friend_name);

    void Group_Chat(QString group_name);

    //接收从应用管理器返回的信号
    void recv_from_mult_back();

private slots:
    void on_addBt_clicked();

    //自定义头像更换
    void headBt_event();

    //void tcp_state_signal(QTreeWidgetItem*, bool);

    void on_Multimedia_Bt_clicked();
    void on_friend_bt_clicked();

    void on_group_bt_clicked();

    void on_other_operations_bt_clicked();

    void exit_login();
signals:
    void login_widget_show_signals();

    void Send_express_success_singals();

    void Send_express_Group_singals();
public:
    Ui::Communication *ui;

private:
    QTreeWidgetItem *friend_item;

    QTreeWidgetItem *group_item;

    Treewidget *tree;

    Treewidget *group_tree;

    //应用管理器
    Multimedia *mul_play;

    QTcpSocket *m_socket;

    Express *exprewid;

    qint32 expre_stat;

    //聊天窗口列表
    QList <Tcpwid *> TcpwidList;

    //聊天窗口好友ID列表
    QList <int > Tcpwid_friendID_List;

    QList <Groupwid *> groupwid_List;

    QList <int > group_ID_List;

    QDateTime current_date_time;

    QList <QWidget *> Widgets_List;

    QList <int > Widgets_Index_List;

    QWidget *Curr_Widget;

    int Curr_index;

    bool is_other_operations;

    OtherOperations *other_widget;

};

#endif // COMMUNICATION_H
