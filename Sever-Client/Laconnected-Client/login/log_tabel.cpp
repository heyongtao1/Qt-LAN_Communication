/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "log_tabel.h"
#include "ui_log_tabel.h"
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QHostAddress>
#include <QDebug>
#include "login.h"
#include <myinfo.h>
Log_tabel::Log_tabel(QTcpSocket *m_socket):
    ui(new Ui::Log_tabel)
{
    write_socket = m_socket;
    ui->setupUi(this);
    connect(write_socket,&QTcpSocket::readyRead,this,&Log_tabel::Deal_typeMsg);
    connect(this,&Log_tabel::Deal_typeMsg_Signals,this,&Log_tabel::Deal_typeMsg_Switch);
}
/**@处理服务器信息
 *
 *
 **************/
//解析服务器返回的注册各种信息
void Log_tabel::Deal_typeMsg()
{
    QByteArray bytearray = write_socket->readAll();
    QJsonParseError jsonerror ;
    QJsonDocument document = QJsonDocument::fromJson(bytearray,&jsonerror);
    if(!document.isNull() && (jsonerror.error == QJsonParseError::NoError))
    {
        if(document.isObject())
        {
            QJsonObject jsonObj = document.object();
            QJsonValue data_json = jsonObj.value("data");
            int M_type_State = jsonObj.value("type").toInt();
            emit Deal_typeMsg_Signals(M_type_State,data_json);
        }
    }
}

void Log_tabel::Deal_typeMsg_Switch(int State_type,QJsonValue &data_json)
{
        switch(State_type)
        {
            case USER_REGIN_SUCCESS:
                 Deal_regMsg_SUCCESS(data_json);break;
            case USER_REGIN_NO:
                 Deal_regMsg_NO(data_json);break;
        }
}


//解析返回注册成功的信息，保存分配的ID
void Log_tabel::Deal_regMsg_SUCCESS(QJsonValue &data_json)
{
    QJsonObject jsonObj = data_json.toObject();
    QJsonValue json_Data = jsonObj.value("data");
    QJsonObject data = json_Data.toObject();
    Mycpp::USERID = data.value("id").toInt();//保存分配的ID

}
//解析返回注册失败的信息，保存分配的ID
void Log_tabel::Deal_regMsg_NO(QJsonValue &data_json)
{
      QMessageBox::information(this,QStringLiteral("注册"),QStringLiteral("注册失败"));
}
Log_tabel::~Log_tabel()
{
    delete ui;
}
//注册消息发送到服务器
void Log_tabel::SendMsg_to_Server()
{
    if(!ui->UserEdit->text().isEmpty() && !ui->PasswordEdit->text().isEmpty())
    {
        Mycpp::USERNAME = ui->UserEdit->text();
        Mycpp::USERPASS = ui->PasswordEdit->text();
        //生成JSON
        QJsonObject userinfo_json;

        QJsonObject data;
        data.insert("username" , Mycpp::USERNAME);
        data.insert("userpass" , Mycpp::USERPASS);
        data.insert("userid",Mycpp::USERID);
        data.insert("text","");

        userinfo_json.insert("data",QJsonValue(data));

        userinfo_json.insert("from_id" , Mycpp::USERID);
        userinfo_json.insert("type",USER_REGIN);

        QJsonDocument document;
        document.setObject(userinfo_json);
        QByteArray bytearray = document.toJson(QJsonDocument::Compact);
        QString strjson(bytearray);
        qDebug()<<strjson;
        //发送JSON
        write_socket->write(bytearray);
        QMessageBox::information(this,QStringLiteral("发送注册信息"),QStringLiteral("发送成功"));
    }

    else
    {
        qDebug()<<"用户名或密码不能为空";
        QMessageBox::information(this,QStringLiteral("发送注册信息"),QStringLiteral("发送失败"));
    }
}

//注册
void Log_tabel::on_logbt_clicked()
{
    SendMsg_to_Server();
}

