/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "mycpp.h"

int      Mycpp::USERID                  = -1;
QString  Mycpp::USERNAME                = "heyongtao";
QString  Mycpp::USERPASS                = "123456";
int      Mycpp::FRIEND_NUM              = 0;
int      Mycpp::FRIEND_ONLINE           = 0;
QString  Mycpp::QStringspilt            = "@@";
QString  Mycpp::M_QString_Spilt_My      = "&&" ;
QString  Mycpp::M_QString_Spilt_Friend  = "##" ;

QString  Server::Server_IP              = "192.168.238.1";
int      Server::Server_sendmsg_port    = 8800;
Mycpp::Mycpp()
{

}

Server::Server()
{

}
