/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "multimedia.h"
#include "ui_multimedia.h"
#include "music_play.h"
#include "camera_play.h"
Multimedia::Multimedia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multimedia)
{
    ui->setupUi(this);
}

Multimedia::~Multimedia()
{
    delete ui;
}
//音乐播放器
void Multimedia::on_music_play_clicked()
{
    music_play = new Music_play();
    music_play->show();
    connect(music_play,SIGNAL(back_signals()),this,SLOT(recv_music_back_signal()));

    this->hide();
    //禁用按钮
    ui->music_play->setEnabled(false);
}

void Multimedia::recv_music_back_signal()
{
    this->show();
    music_play->close();
    //激活按钮
    ui->music_play->setEnabled(true);
}

//摄像头控制
void Multimedia::on_camera_play_clicked()
{
    camera = new Camera_play();
    camera->show();
    connect(camera,SIGNAL(exit_signal()),this,SLOT(recv_back_camera_signal()));
}
//发射返回信号
void Multimedia::on_back_combt_clicked()
{
    emit back_com_signal();
}
//摄像头返回槽函数
void Multimedia::recv_back_camera_signal()
{
    this->show();
    camera->hide();
}
//视频播放器
void Multimedia::on_video_play_clicked()
{

}
