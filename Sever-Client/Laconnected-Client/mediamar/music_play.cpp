/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "music_play.h"
#include "ui_music_play.h"
#include <QDir>
#include <QFileDialog>
#include <QDebug>
Music_play::Music_play(QWidget *parent) :
    ui(new Ui::Music_play)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);//设置循环播放
    player->setPlaylist(playlist);

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(onStateChanged(QMediaPlayer::State)));
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));
    //connect(player,SIGNAL(currentIndexChanged(int)),this,SLOT(onPlaylistChanged(int)));
    //Init();
}

Music_play::~Music_play()
{
    player->stop();
    playlist->deleteLater();
    player->deleteLater();
    delete ui;
}

void Music_play::Init()
{
    QStringList fileList;
    fileList<<"://music/1.mp3"<<"://music/home.mp3"<<"://music/xiao.mp3";
    if(fileList.count() < 1)
        return;
    for(int i=0;i<fileList.count();i++)
    {
        qDebug()<<fileList.at(i);
        QString aFile = fileList.at(i);
        playlist->addMedia(QUrl(aFile));//添加文件
        QFileInfo fileinfo(aFile);
        ui->listWidget->addItem(fileinfo.fileName());
    }
    if(player->state() != QMediaPlayer::PlayingState)
        playlist->setCurrentIndex(0);
    player->play();
}

void Music_play::onStateChanged(QMediaPlayer::State state)
{
    //ui->playbt->setEnabled(!(state == QMediaPlayer::PlayingState));
    //ui->pausebt->setEnabled(state == QMediaPlayer::PausedState);
    //ui->stopbt->setEnabled(state == QMediaPlayer::StoppedState);
}

void Music_play::onPlaylistChanged(int position)
{
    ui->listWidget->setCurrentRow(position);
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(item)
        ui->curMedia_label->setText(item->text());
}

void Music_play::onDurationChanged(qint64 duration)
{
    ui->sliderPosition->setMaximum(duration);
    int secs = duration/1000;
    int mins = secs/60;
    secs = secs%60;
    durationTime = QString::asprintf("%d:%d",mins,secs);
    ui->lratio_label->setText(positionTime + "/" + durationTime);
}

void Music_play::onPositionChanged(qint64 position)
{
    if(ui->sliderPosition->isSliderDown())
    {
        return;
    }
    ui->sliderPosition->setSliderPosition(position);
    int secs = position/1000;
    int mins = secs/60;
    secs = secs%60;
    positionTime = QString::asprintf("%d:%d",mins,secs);
    ui->lratio_label->setText(positionTime + "/" + durationTime);
}
//添加歌曲
void Music_play::on_add_music_bt_clicked()
{
    QString curpath = QDir::homePath();
    QString dlgTitle = "选择音频文件";
    QString filter = "音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
    QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curpath,filter);

    qDebug()<<fileList;
    if(fileList.count() < 1)
        return;
    for(int i=0;i<fileList.count();i++)
    {
        qDebug()<<fileList.at(i);
        QString aFile = fileList.at(i);
        playlist->addMedia(QUrl::fromLocalFile(aFile));//添加文件
        QFileInfo fileinfo(aFile);
        ui->listWidget->addItem(fileinfo.fileName());
    }
    if(player->state() != QMediaPlayer::PlayingState)
        playlist->setCurrentIndex(0);
    player->play();
}
//删除歌曲
void Music_play::on_remove_music_bt_clicked()
{
    int pos = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->takeItem(pos);
    delete item;
    playlist->removeMedia(pos);
}
//清空歌单
void Music_play::on_clear_music_bt_clicked()
{
    playlist->clear();
    ui->listWidget->clear();
    player->stop();
}

//双击歌曲响应槽函数
void Music_play::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int rowNo = index.row();
    playlist->setCurrentIndex(rowNo);
    player->play();
    ui->curMedia_label->setText(ui->listWidget->currentItem()->text());
}
//播放
void Music_play::on_playbt_clicked()
{
    if(playlist->currentIndex()<0)
        playlist->setCurrentIndex(0);
    player->play();
}
//暂停
void Music_play::on_pausebt_clicked()
{
    player->pause();
}
//停止
void Music_play::on_stopbt_clicked()
{
    player->stop();
}
//上一首
void Music_play::on_before_bt_clicked()
{
    int currow = playlist->currentIndex();
    if(currow == 0)
    {
        playlist->setCurrentIndex(playlist->mediaCount());
        ui->listWidget->setCurrentRow(playlist->mediaCount());
    }
    else
    {
        playlist->setCurrentIndex(currow-1);
        ui->listWidget->setCurrentRow(currow-1);
    }

    player->play();
}
//下一首
void Music_play::on_next_bt_clicked()
{
    int currow = playlist->currentIndex();
    if(currow == playlist->mediaCount())
    {
        playlist->setCurrentIndex(0);
        ui->listWidget->setCurrentRow(0);
    }

    else
    {
        playlist->setCurrentIndex(currow+1);
        ui->listWidget->setCurrentRow(currow+1);
    }

    player->play();
}
//静音
void Music_play::on_sound_bt_clicked()
{
    bool mute = player->isMuted();
    player->setMuted(!mute);
    ui->sound_bt->setEnabled(false);
}
//调整音量
void Music_play::on_sound_Slider_valueChanged(int value)
{
    player->setVolume(value);
    player->setMuted(false);
    ui->sound_bt->setEnabled(true);
}

void Music_play::on_backbt_clicked()
{
    emit back_signals();
}
