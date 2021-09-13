/********************************************************************************
** Form generated from reading UI file 'multimedia.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIMEDIA_H
#define UI_MULTIMEDIA_H

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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multimedia
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QCommandLinkButton *back_combt;
    QFrame *line;
    QGroupBox *media_groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *music_play;
    QToolButton *video_play;
    QToolButton *audio_play;
    QToolButton *camera_play;
    QToolButton *other_play;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;

    void setupUi(QWidget *Multimedia)
    {
        if (Multimedia->objectName().isEmpty())
            Multimedia->setObjectName(QStringLiteral("Multimedia"));
        Multimedia->resize(650, 500);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Multimedia->sizePolicy().hasHeightForWidth());
        Multimedia->setSizePolicy(sizePolicy);
        Multimedia->setMinimumSize(QSize(650, 500));
        Multimedia->setMaximumSize(QSize(650, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/Multimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        Multimedia->setWindowIcon(icon);
        gridLayout = new QGridLayout(Multimedia);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Multimedia);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(650, 50));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        back_combt = new QCommandLinkButton(Multimedia);
        back_combt->setObjectName(QStringLiteral("back_combt"));
        back_combt->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(back_combt);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(Multimedia);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        media_groupBox = new QGroupBox(Multimedia);
        media_groupBox->setObjectName(QStringLiteral("media_groupBox"));
        media_groupBox->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(media_groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        music_play = new QToolButton(media_groupBox);
        music_play->setObjectName(QStringLiteral("music_play"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(music_play->sizePolicy().hasHeightForWidth());
        music_play->setSizePolicy(sizePolicy1);
        music_play->setMinimumSize(QSize(100, 80));
        music_play->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(music_play);

        video_play = new QToolButton(media_groupBox);
        video_play->setObjectName(QStringLiteral("video_play"));
        sizePolicy1.setHeightForWidth(video_play->sizePolicy().hasHeightForWidth());
        video_play->setSizePolicy(sizePolicy1);
        video_play->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(video_play);

        audio_play = new QToolButton(media_groupBox);
        audio_play->setObjectName(QStringLiteral("audio_play"));
        sizePolicy1.setHeightForWidth(audio_play->sizePolicy().hasHeightForWidth());
        audio_play->setSizePolicy(sizePolicy1);
        audio_play->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(audio_play);

        camera_play = new QToolButton(media_groupBox);
        camera_play->setObjectName(QStringLiteral("camera_play"));
        sizePolicy1.setHeightForWidth(camera_play->sizePolicy().hasHeightForWidth());
        camera_play->setSizePolicy(sizePolicy1);
        camera_play->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(camera_play);

        other_play = new QToolButton(media_groupBox);
        other_play->setObjectName(QStringLiteral("other_play"));
        sizePolicy1.setHeightForWidth(other_play->sizePolicy().hasHeightForWidth());
        other_play->setSizePolicy(sizePolicy1);
        other_play->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(other_play);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(media_groupBox);

        groupBox_2 = new QGroupBox(Multimedia);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Multimedia);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));

        verticalLayout->addWidget(groupBox_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Multimedia);

        QMetaObject::connectSlotsByName(Multimedia);
    } // setupUi

    void retranslateUi(QWidget *Multimedia)
    {
        Multimedia->setWindowTitle(QApplication::translate("Multimedia", "\345\272\224\347\224\250\347\256\241\347\220\206\345\231\250", Q_NULLPTR));
        label->setText(QApplication::translate("Multimedia", "\345\272\224\347\224\250\347\256\241\347\220\206\345\231\250", Q_NULLPTR));
        back_combt->setText(QString());
        media_groupBox->setTitle(QApplication::translate("Multimedia", "\345\244\232\345\252\222\344\275\223\345\267\245\345\205\267\347\261\273", Q_NULLPTR));
        music_play->setText(QApplication::translate("Multimedia", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
        video_play->setText(QApplication::translate("Multimedia", "\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
        audio_play->setText(QApplication::translate("Multimedia", "\345\275\225\345\210\266\351\237\263\351\242\221", Q_NULLPTR));
        camera_play->setText(QApplication::translate("Multimedia", "\346\221\204\345\203\217\345\244\264\346\216\247\345\210\266", Q_NULLPTR));
        other_play->setText(QApplication::translate("Multimedia", "\345\205\266\344\273\226", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Multimedia", "\345\250\261\344\271\220\344\274\221\351\227\262\347\261\273", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Multimedia", "\345\205\266\344\273\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Multimedia: public Ui_Multimedia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIMEDIA_H
