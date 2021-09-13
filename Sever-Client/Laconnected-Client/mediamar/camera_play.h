#ifndef CAMERA_PLAY_H
#define CAMERA_PLAY_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QLabel>
#include <QCameraViewfinder>
namespace Ui {
class Camera_play;
}

class Camera_play : public QWidget
{
    Q_OBJECT

public:
    explicit Camera_play(QWidget *parent = 0);
    ~Camera_play();
    //初始化
    void iniCamera();
    void iniImageCapture();
    void iniVideoRecorder();

private slots:
    void on_close_camera_bt_clicked();
    void on_open_camera_bt_clicked();
    void on_capture_bt_clicked();
    //自定义
    void on_cameraStateChanged(QCamera::State state);

    //QCameraImageCapture
    void on_imageReadyForCapture(bool ready);
    void on_imageCaptured(int id,const QImage &preview);
    void on_imageSaved(int id,const QString &fileName);

    //QMediaRecorder
    void on_videStateChanged(QMediaRecorder::State state);
    void on_videoDurationChanged(qint64 duration);

    void on_start_video_bt_clicked();

    void on_stop_capture_bt_clicked();

    void on_save_pic_file_bt_clicked();

    void on_exit_bt_clicked();
signals:
    void exit_signal();
private:
    Ui::Camera_play *ui;
    QCamera *curCamera = Q_NULLPTR;//摄像头对象
    QCameraImageCapture *imageCapture;//抓取图片
    QMediaRecorder *mediaRecorder;//录像
    QCameraViewfinder *m_pViewfinder;
    //QLabel *LabCameraState;
    //QLabel *LabInfo;
    //QLabel *LabCameraMode;

};

#endif // CAMERA_PLAY_H
