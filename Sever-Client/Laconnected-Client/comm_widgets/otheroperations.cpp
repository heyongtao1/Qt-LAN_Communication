/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "otheroperations.h"
#include "ui_otheroperations.h"

OtherOperations::OtherOperations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtherOperations())
{
    ui->setupUi(this);
}

OtherOperations::~OtherOperations()
{
    delete ui;
}

/**@切换账户
 *
 * */
void OtherOperations::on_exit_login_bt_clicked()
{
    emit exit_login_signal();
}
