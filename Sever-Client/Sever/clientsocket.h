#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QJsonValue>
#include <QObject>
#include <QTcpSocket>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = nullptr);
    void RecvClient_Msg();

    void M_USER_REGIN(QJsonValue &);//用户注册发送的信息
    void M_USER_CHAR_MSG(QJsonValue &);//用户聊天发送的信息
    void M_USER_LOGIN(QJsonValue &);

    bool isReg_Username(QString);
    bool isLogin_User(QString,QString);
signals:

public slots:
    void Client_disconnect();
private:
    QTcpSocket *socket;
};

#endif // CLIENTSOCKET_H
