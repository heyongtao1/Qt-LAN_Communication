#ifndef MYCPP_H
#define MYCPP_H

#include <QObject>

//#define  Server_IP              "192.168.238.1"
//#define  Server_sendmsg_port    8800
//默认服务器配置
class Server
{
public:
     Server();
     static QString Server_IP;
     static int Server_sendmsg_port;

};

//用户信息
class Mycpp
{
public:
    Mycpp();
    static QString    USERNAME;
    static QString    USERPASS;
    static int        USERID;
    static int        FRIEND_NUM;
    static int        FRIEND_ONLINE;
    static QString    QStringspilt;
    static QString    M_QString_Spilt_My;
    static QString    M_QString_Spilt_Friend;
    /**@
     * 对多个对象来说，静态数据成员只存储一处，供所有对象共用。
     * 静态数据成员的值对每个对象都是一样，但它的值是可以更新的。
     * 只要对静态数据成员的值更新一次，保证所有对象存取更新后
     * 的相同的值，这样可以提高时间效率。
     */
};

#endif // MYCPP_H
