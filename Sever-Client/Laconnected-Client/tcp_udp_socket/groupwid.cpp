/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "groupwid.h"
#include "ui_groupwid.h"

Groupwid::Groupwid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Groupwid)
{
    ui->setupUi(this);
    expre_stat = 0;
    m_curwidth = 80;
}

Groupwid::~Groupwid()
{
    delete ui;
}

void Groupwid::on_expreBt_2_clicked()
{
    //用点击表情按钮的次数来控制显示和关闭，偶数关闭，奇数显示
    expre_stat++;
    if(expre_stat%2 != 0)
    {
        exprewid= new Express(nullptr,this);
        exprewid->setParent(this);
        exprewid->move(0,136);
        exprewid->show();
    }
    if(expre_stat%2 == 0)
    {
        exprewid->close();
    }
}

void Groupwid::Recv_Send_Group_express_signals()
{
    foreach(auto item,Send_express_List)
    {
        Send_express_List.removeOne(item);
    }
    qDebug()<<QStringLiteral("发送表情完毕，清空表情列表")<<Send_express_List.size()<<Send_express_List;
}

void Groupwid::getitem_expre(QUrl url)
{
    //将表情添加到发送信息框里
    ui->sendEdit_2->insertHtml("<img src='" + url.toString() + "'/>");
    QString express_path = url.toString().split("file:").at(1);
    Send_express_List.append(express_path);
    qDebug()<<express_path;
}
