/*********************************************************
 * Copyright (C) 2021 - All Rights Reserved by
 *产品名称 : Laconnected
 *作 者    : 何永涛
 *编写日期 : 2021.1.10-2021.2.16
 *说 明   :  PC端通信软件
 *历史纪录 :
 *<作者>    <日期>        <版本>        <内容>
 *********************************************************/
#include "camera_play.h"
#include "ui_camera_play.h"
#include <QCameraInfo>
#include <QMessageBox>
#include <QUrl>
#include <QDir>
#include <QFileDialog>
//在windows下不支持摄像头录制视频
Camera_play::Camera_play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera_play)
{
    ui->setupUi(this);
    QList <QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.size() > 0)
    {
        iniCamera();
        iniImageCapture();
        iniVideoRecorder();
        curCamera->start();//打开摄像头
    }
}

Camera_play::~Camera_play()
{
    delete ui;
}
//摄像头初始化
void Camera_play::iniCamera()
{
    QCameraInfo curCamerainfo = QCameraInfo::defaultCamera();//获取缺省摄像头
    ui->comboCamera->addItem(curCamerainfo.description());
    ui->comboCamera->setCurrentIndex(0);

    curCamera = new QCamera(curCamerainfo,this);
    //QCameraViewfinderSettings viewfinderSettings;
    //viewfinderSettings.setResolution(640,680);
    //viewfinderSettings.setMinimumFrameRate(15.0);
    //viewfinderSettings.setMaximumFrameRate(30.0);
    //curCamera->setViewfinderSettings(viewfinderSettings);


    m_pViewfinder = new QCameraViewfinder(this);
    m_pViewfinder->setParent(ui->camera_widget);
    m_pViewfinder->setFixedSize(ui->camera_widget->size());
    m_pViewfinder->show();
    curCamera->setViewfinder(m_pViewfinder);//设置预览看

    curCamera->setCaptureMode(QCamera::CaptureViewfinder);

    //判断摄像头是否支持抓图、录像
    ui->capture_bt->setChecked(curCamera->isCaptureModeSupported(QCamera::CaptureStillImage));//抓图
    ui->start_video_bt->setChecked(curCamera->isCaptureModeSupported(QCamera::CaptureVideo));

    connect(curCamera,SIGNAL(stateChanged(QCamera::State)),this,SLOT(on_cameraStateChanged(QCamera::State)));
}

void Camera_play::on_cameraStateChanged(QCamera::State state)
{
    switch (state)
    {
    case QCamera::UnloadedState:
         ui->state_label->setText("UnloadedState");
         break;
    case QCamera::LoadedState:
         ui->state_label->setText("LoadedState");
         break;
    case QCamera::ActiveState:
         ui->state_label->setText("ActiveState");
         break;
    default:
        break;
    }
}

//开启摄像头
void Camera_play::on_open_camera_bt_clicked()
{
    curCamera->start();
}


//关闭摄像头
void Camera_play::on_close_camera_bt_clicked()
{
    curCamera->stop();
}
//抓图初始化
void Camera_play::iniImageCapture()
{
    imageCapture = new QCameraImageCapture(curCamera,this);
    imageCapture->setBufferFormat(QVideoFrame::Format_Jpeg);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);//保存目标

    connect(imageCapture,SIGNAL(readyForCaptureChanged(bool)),this,SLOT(on_imageReadyForCapture(bool)));
    connect(imageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT(on_imageCaptured(int,QImage)));
    connect(imageCapture,SIGNAL(imageSaved(int,QString)),this,SLOT(on_imageSaved(int,QString)));

}
//抓图
void Camera_play::on_capture_bt_clicked()
{
     if(curCamera->captureMode() != QCamera::CaptureStillImage)
     {
         curCamera->setCaptureMode(QCamera::CaptureStillImage);
     }
     imageCapture->capture();
}
void Camera_play::on_imageReadyForCapture(bool ready)
{
     ui->start_video_bt->setEnabled(ready);
}

void Camera_play::on_imageCaptured(int id, const QImage &preview)
{
     Q_UNUSED(id);
     QImage scaledimage = preview.scaled(ui->capture_label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
     ui->capture_label->setPixmap(QPixmap::fromImage( scaledimage));
}

void Camera_play::on_imageSaved(int id, const QString &fileName)
{
     Q_UNUSED(id);
    ui->pic_save_label->setText(fileName);
}
//录制视频初始化
void Camera_play::iniVideoRecorder()
{
     mediaRecorder = new QMediaRecorder(curCamera,this);
     ui->start_video_bt->setChecked(mediaRecorder->isMuted());
     connect(mediaRecorder,SIGNAL(stateChanged(QMediaRecorder::State)),this,SLOT(on_videStateChanged(QMediaRecorder::State)));
     connect(mediaRecorder,SIGNAL(durationChanged(qint64)),this,SLOT(on_videoDurationChanged(qint64)));
}

void Camera_play::on_videStateChanged(QMediaRecorder::State state)
{

}

void Camera_play::on_videoDurationChanged(qint64 duration)
{

}


//开启录制
void Camera_play::on_start_video_bt_clicked()
{
     //qDebug()<<QString(QStringList("开启录制视频"));
     if(!mediaRecorder->isAvailable())
     {
        //QMessageBox::critical(this,"错误","不支持视频录制 \n",mediaRecorder->isAvailable() == false);
        return ;
     }
     if(curCamera->captureMode() != QCamera::CaptureVideo)
         curCamera->setCaptureMode(QCamera::CaptureVideo);

     QString filepath = ui->save_picfile_pathEdit->text().trimmed();
     mediaRecorder->setOutputLocation(QUrl::fromLocalFile(filepath));
     //开始录制视频
     mediaRecorder->record();
}
//停止录制
void Camera_play::on_stop_capture_bt_clicked()
{
     //qDebug()<<QString(QStringList("停止录制视频"));
     mediaRecorder->stop();
}
//保存视频文件
void Camera_play::on_save_pic_file_bt_clicked()
{
    QString curpath = QDir::homePath();
    //QString dlgTitle = "选择音频文件";
    //QString filter = "音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
    QStringList filepath = QFileDialog::getOpenFileNames(this,nullptr,curpath,nullptr);
    ui->save_picfile_pathEdit->setText(filepath.at(0));
}
//退出
void Camera_play::on_exit_bt_clicked()
{
    emit exit_signal();
}
