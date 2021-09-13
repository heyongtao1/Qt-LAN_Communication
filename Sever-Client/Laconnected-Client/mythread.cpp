/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "mythread.h"
#include <QDebug>
#include <QMessageBox>
MyThread::MyThread(QString _IP,int _prot,Tcpwid *tcpwid)
{
    udp_IP = _IP;
    udp_port = _prot;
    _tcpwid = tcpwid;
    qDebug()<<udp_IP<<udp_port;
}

MyThread::~MyThread()
{
    this->deleteLater();
}
//线程任务
void MyThread::run()
{
    //udp组播通信
    udp_socket = new QUdpSocket(this);
    udp_socket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
    groupaddress = QHostAddress(udp_IP);
    if(udp_socket->bind(QHostAddress::AnyIPv4,udp_port,QUdpSocket::ShareAddress))
    {
        bool join_success = udp_socket->joinMulticastGroup(groupaddress);
        qDebug()<<join_success;
        if(join_success)
        {
             emit join_SIGNAL();
             qDebug()<<"发射信号";

        }
        //
    }
    qDebug()<<QString(QStringLiteral("任务"));
}

void MyThread::thread_close()
{

}
