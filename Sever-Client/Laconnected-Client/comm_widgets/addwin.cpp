/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "addwin.h"
#include "ui_addwin.h"

#include <QSqlQuery>
#include <QDebug>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QJsonObject>
#include "mycpp.h"
#include "myinfo.h"
#include <QTimer>
Addwin::Addwin() :
    ui(new Ui::Addwin)
{
    ui->setupUi(this);
    add_friend_database();
    add_group_database();
}
Addwin::~Addwin()
{
    delete ui;
}

//创建好友列表数据库
void Addwin::add_friend_database()
{
    friend_db = QSqlDatabase::addDatabase("QSQLITE");
    friend_db.setDatabaseName("friend.db");

    if(!friend_db.open())
    {
        qDebug()<<"open sql error";
    }
    else {
        qDebug()<<"open ok";
    }
    qDebug()<<QStringLiteral("创建表格");
    QString createname = "create table if not exists friend(friend_id int not NULL,user_id int not NULL,friend_name text not NULL)";
    QSqlQuery query(createname);
    if(!query.exec())
    {
        qDebug()<<"create error";
    }
    else {
        qDebug()<<"create ok";
    }
}

//创建讨论组/群聊列表数据库
void Addwin::add_group_database()
{
    group_db = QSqlDatabase::addDatabase("QSQLITE");
    group_db.setDatabaseName("user_group.db");

    if(!group_db.open())
    {
    qDebug()<<"open sql error";
    }
    else {
    qDebug()<<"open group ok";
    }
    QString createtabel = "create table if not exists user_group(group_id int not NULL,user_id int not NULL,group_name text not NULL)";
    QSqlQuery query(createtabel);
    if(!query.exec())
    {
    qDebug()<<QStringLiteral("创建表格")<< "create group error"<<createtabel;
    }
    else {
    qDebug()<<"create ok";
    }
}
