#ifndef MUSIC_PLAY_H
#define MUSIC_PLAY_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class Music_play;
}

class Music_play : public QWidget
{
    Q_OBJECT

public:
    explicit Music_play(QWidget *parent = 0);
    ~Music_play();
    void Init();
private slots:
    void onStateChanged(QMediaPlayer::State state);
    void onPlaylistChanged(int position);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void on_add_music_bt_clicked();

    void on_remove_music_bt_clicked();

    void on_clear_music_bt_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_playbt_clicked();

    void on_pausebt_clicked();

    void on_stopbt_clicked();

    void on_before_bt_clicked();

    void on_next_bt_clicked();

    void on_sound_bt_clicked();

    void on_sound_Slider_valueChanged(int value);

    void on_backbt_clicked();
signals:
    //返回应用管理器信号
    void back_signals();
private:
    Ui::Music_play *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QString durationTime;
    QString positionTime;

};

#endif // MUSIC_PLAY_H
