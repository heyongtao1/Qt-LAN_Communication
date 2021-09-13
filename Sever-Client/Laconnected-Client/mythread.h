#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QHostAddress>
#include <QUdpSocket>
#include <tcp_udp_socket/tcpwid.h>

class MyThread :public QThread
{
    Q_OBJECT
public:
    MyThread(QString _IP,int _prot,Tcpwid *);
    ~MyThread();
protected:
    void run();
    void thread_close();
signals:
    void join_SIGNAL();
private:
    QString udp_IP;
    int udp_port;
    QHostAddress groupaddress;
    QUdpSocket *udp_socket;
    Tcpwid *_tcpwid ;
};

#endif // MYTHREAD_H
