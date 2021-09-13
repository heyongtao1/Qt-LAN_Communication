#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <QWidget>
#include "music_play.h"
#include "camera_play.h"
namespace Ui {
class Multimedia;
}

class Multimedia : public QWidget
{
    Q_OBJECT

public:
    explicit Multimedia(QWidget *parent = 0);
    ~Multimedia();

private slots:
    void on_music_play_clicked();
    //接收音乐播放器返回信号
    void recv_music_back_signal();
    //返回主界面信号
    void on_back_combt_clicked();
    //摄像头返回信号
    void recv_back_camera_signal();
    void on_camera_play_clicked();

    void on_video_play_clicked();

signals:
    void back_com_signal();

private:
    Ui::Multimedia *ui;
    //音乐播放器
    Music_play *music_play;
    //视频播放器
    Camera_play *camera;
};

#endif // MULTIMEDIA_H
