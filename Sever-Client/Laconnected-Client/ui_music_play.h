/********************************************************************************
** Form generated from reading UI file 'music_play.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_PLAY_H
#define UI_MUSIC_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Music_play
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QCommandLinkButton *backbt;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_music_bt;
    QPushButton *remove_music_bt;
    QPushButton *clear_music_bt;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playbt;
    QPushButton *pausebt;
    QPushButton *stopbt;
    QPushButton *before_bt;
    QPushButton *next_bt;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sound_bt;
    QSlider *sound_Slider;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *curMedia_label;
    QSlider *sliderPosition;
    QLabel *lratio_label;

    void setupUi(QWidget *Music_play)
    {
        if (Music_play->objectName().isEmpty())
            Music_play->setObjectName(QStringLiteral("Music_play"));
        Music_play->resize(531, 519);
        QIcon icon;
        icon.addFile(QStringLiteral(":/media/music.png"), QSize(), QIcon::Normal, QIcon::Off);
        Music_play->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Music_play);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        backbt = new QCommandLinkButton(Music_play);
        backbt->setObjectName(QStringLiteral("backbt"));
        backbt->setMaximumSize(QSize(50, 30));

        horizontalLayout_6->addWidget(backbt);


        verticalLayout->addLayout(horizontalLayout_6);

        groupBox = new QGroupBox(Music_play);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        add_music_bt = new QPushButton(groupBox);
        add_music_bt->setObjectName(QStringLiteral("add_music_bt"));

        horizontalLayout->addWidget(add_music_bt);

        remove_music_bt = new QPushButton(groupBox);
        remove_music_bt->setObjectName(QStringLiteral("remove_music_bt"));

        horizontalLayout->addWidget(remove_music_bt);

        clear_music_bt = new QPushButton(groupBox);
        clear_music_bt->setObjectName(QStringLiteral("clear_music_bt"));

        horizontalLayout->addWidget(clear_music_bt);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        playbt = new QPushButton(Music_play);
        playbt->setObjectName(QStringLiteral("playbt"));
        playbt->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(playbt);

        pausebt = new QPushButton(Music_play);
        pausebt->setObjectName(QStringLiteral("pausebt"));
        pausebt->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(pausebt);

        stopbt = new QPushButton(Music_play);
        stopbt->setObjectName(QStringLiteral("stopbt"));
        stopbt->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(stopbt);

        before_bt = new QPushButton(Music_play);
        before_bt->setObjectName(QStringLiteral("before_bt"));
        before_bt->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setPointSize(7);
        before_bt->setFont(font);

        horizontalLayout_2->addWidget(before_bt);

        next_bt = new QPushButton(Music_play);
        next_bt->setObjectName(QStringLiteral("next_bt"));
        next_bt->setMaximumSize(QSize(40, 16777215));
        next_bt->setFont(font);

        horizontalLayout_2->addWidget(next_bt);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        sound_bt = new QPushButton(Music_play);
        sound_bt->setObjectName(QStringLiteral("sound_bt"));
        sound_bt->setMinimumSize(QSize(40, 0));
        sound_bt->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(sound_bt);

        sound_Slider = new QSlider(Music_play);
        sound_Slider->setObjectName(QStringLiteral("sound_Slider"));
        sound_Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sound_Slider);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        line = new QFrame(Music_play);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        curMedia_label = new QLabel(Music_play);
        curMedia_label->setObjectName(QStringLiteral("curMedia_label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(curMedia_label->sizePolicy().hasHeightForWidth());
        curMedia_label->setSizePolicy(sizePolicy);
        curMedia_label->setMinimumSize(QSize(200, 0));
        curMedia_label->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(curMedia_label);

        sliderPosition = new QSlider(Music_play);
        sliderPosition->setObjectName(QStringLiteral("sliderPosition"));
        sliderPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderPosition);

        lratio_label = new QLabel(Music_play);
        lratio_label->setObjectName(QStringLiteral("lratio_label"));
        sizePolicy.setHeightForWidth(lratio_label->sizePolicy().hasHeightForWidth());
        lratio_label->setSizePolicy(sizePolicy);
        lratio_label->setMinimumSize(QSize(100, 0));
        lratio_label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(lratio_label);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Music_play);

        QMetaObject::connectSlotsByName(Music_play);
    } // setupUi

    void retranslateUi(QWidget *Music_play)
    {
        Music_play->setWindowTitle(QApplication::translate("Music_play", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
        backbt->setText(QString());
        groupBox->setTitle(QApplication::translate("Music_play", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        add_music_bt->setText(QApplication::translate("Music_play", "\346\267\273\345\212\240", Q_NULLPTR));
        remove_music_bt->setText(QApplication::translate("Music_play", "\347\247\273\351\231\244", Q_NULLPTR));
        clear_music_bt->setText(QApplication::translate("Music_play", "\346\270\205\347\251\272", Q_NULLPTR));
        playbt->setText(QApplication::translate("Music_play", "\346\222\255\346\224\276", Q_NULLPTR));
        pausebt->setText(QApplication::translate("Music_play", "\346\232\202\345\201\234", Q_NULLPTR));
        stopbt->setText(QApplication::translate("Music_play", "\345\201\234\346\255\242", Q_NULLPTR));
        before_bt->setText(QApplication::translate("Music_play", "\344\270\212\344\270\200\351\246\226", Q_NULLPTR));
        next_bt->setText(QApplication::translate("Music_play", "\344\270\213\344\270\200\351\246\226", Q_NULLPTR));
        sound_bt->setText(QApplication::translate("Music_play", "\351\235\231\351\237\263", Q_NULLPTR));
        curMedia_label->setText(QString());
        lratio_label->setText(QApplication::translate("Music_play", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Music_play: public Ui_Music_play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_PLAY_H
