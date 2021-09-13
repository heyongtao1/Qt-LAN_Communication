/********************************************************************************
** Form generated from reading UI file 'camera_play.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_PLAY_H
#define UI_CAMERA_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcameraviewfinder.h>

QT_BEGIN_NAMESPACE

class Ui_Camera_play
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *open_camera_bt;
    QPushButton *close_camera_bt;
    QPushButton *capture_bt;
    QPushButton *start_video_bt;
    QPushButton *stop_capture_bt;
    QPushButton *exit_bt;
    QFrame *line;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboCamera;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *save_pic_file_bt;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *save_picfile_pathEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QCameraViewfinder *camera_widget;
    QGroupBox *groupBox_3;
    QLabel *capture_label;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLabel *state_label;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *capture_mode_label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLabel *pic_save_label;

    void setupUi(QWidget *Camera_play)
    {
        if (Camera_play->objectName().isEmpty())
            Camera_play->setObjectName(QStringLiteral("Camera_play"));
        Camera_play->resize(700, 541);
        Camera_play->setMinimumSize(QSize(700, 541));
        Camera_play->setMaximumSize(QSize(700, 541));
        gridLayout = new QGridLayout(Camera_play);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        open_camera_bt = new QPushButton(Camera_play);
        open_camera_bt->setObjectName(QStringLiteral("open_camera_bt"));
        open_camera_bt->setMinimumSize(QSize(0, 60));
        open_camera_bt->setMaximumSize(QSize(80, 60));

        horizontalLayout->addWidget(open_camera_bt);

        close_camera_bt = new QPushButton(Camera_play);
        close_camera_bt->setObjectName(QStringLiteral("close_camera_bt"));
        close_camera_bt->setMinimumSize(QSize(0, 60));
        close_camera_bt->setMaximumSize(QSize(80, 60));

        horizontalLayout->addWidget(close_camera_bt);

        capture_bt = new QPushButton(Camera_play);
        capture_bt->setObjectName(QStringLiteral("capture_bt"));
        capture_bt->setMinimumSize(QSize(0, 60));
        capture_bt->setMaximumSize(QSize(80, 60));

        horizontalLayout->addWidget(capture_bt);

        start_video_bt = new QPushButton(Camera_play);
        start_video_bt->setObjectName(QStringLiteral("start_video_bt"));
        start_video_bt->setMinimumSize(QSize(0, 60));
        start_video_bt->setMaximumSize(QSize(80, 60));

        horizontalLayout->addWidget(start_video_bt);

        stop_capture_bt = new QPushButton(Camera_play);
        stop_capture_bt->setObjectName(QStringLiteral("stop_capture_bt"));
        stop_capture_bt->setMinimumSize(QSize(0, 60));
        stop_capture_bt->setMaximumSize(QSize(80, 60));

        horizontalLayout->addWidget(stop_capture_bt);

        exit_bt = new QPushButton(Camera_play);
        exit_bt->setObjectName(QStringLiteral("exit_bt"));
        exit_bt->setMinimumSize(QSize(0, 60));
        exit_bt->setMaximumSize(QSize(80, 60));

        horizontalLayout->addWidget(exit_bt);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(Camera_play);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        groupBox = new QGroupBox(Camera_play);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 100));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 321, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label);

        comboCamera = new QComboBox(layoutWidget);
        comboCamera->setObjectName(QStringLiteral("comboCamera"));
        comboCamera->setMinimumSize(QSize(0, 29));
        comboCamera->setMaximumSize(QSize(16777215, 29));

        horizontalLayout_2->addWidget(comboCamera);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 60, 541, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        save_pic_file_bt = new QPushButton(layoutWidget1);
        save_pic_file_bt->setObjectName(QStringLiteral("save_pic_file_bt"));
        save_pic_file_bt->setMinimumSize(QSize(212, 29));
        save_pic_file_bt->setMaximumSize(QSize(212, 16777215));

        horizontalLayout_4->addWidget(save_pic_file_bt);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        save_picfile_pathEdit = new QLineEdit(layoutWidget1);
        save_picfile_pathEdit->setObjectName(QStringLiteral("save_picfile_pathEdit"));
        save_picfile_pathEdit->setMinimumSize(QSize(0, 29));
        save_picfile_pathEdit->setMaximumSize(QSize(16777215, 29));

        horizontalLayout_3->addWidget(save_picfile_pathEdit);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_2 = new QGroupBox(Camera_play);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 230));
        camera_widget = new QCameraViewfinder(groupBox_2);
        camera_widget->setObjectName(QStringLiteral("camera_widget"));
        camera_widget->setGeometry(QRect(12, 17, 321, 271));

        horizontalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Camera_play);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 300));
        capture_label = new QLabel(groupBox_3);
        capture_label->setObjectName(QStringLiteral("capture_label"));
        capture_label->setGeometry(QRect(10, 20, 321, 271));

        horizontalLayout_5->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(Camera_play);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_6->addWidget(label_3);

        state_label = new QLabel(Camera_play);
        state_label->setObjectName(QStringLiteral("state_label"));
        state_label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_6->addWidget(state_label);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(Camera_play);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(65, 20));

        horizontalLayout_7->addWidget(label_5);

        capture_mode_label = new QLabel(Camera_play);
        capture_mode_label->setObjectName(QStringLiteral("capture_mode_label"));
        capture_mode_label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(capture_mode_label);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(Camera_play);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(80, 20));

        horizontalLayout_8->addWidget(label_7);

        pic_save_label = new QLabel(Camera_play);
        pic_save_label->setObjectName(QStringLiteral("pic_save_label"));
        pic_save_label->setMinimumSize(QSize(200, 0));
        pic_save_label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_8->addWidget(pic_save_label);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        gridLayout->addLayout(horizontalLayout_9, 1, 0, 1, 1);


        retranslateUi(Camera_play);

        QMetaObject::connectSlotsByName(Camera_play);
    } // setupUi

    void retranslateUi(QWidget *Camera_play)
    {
        Camera_play->setWindowTitle(QApplication::translate("Camera_play", "\346\221\204\345\203\217\345\244\264\347\233\221\346\216\247\345\222\214\346\213\215\347\205\247", Q_NULLPTR));
        open_camera_bt->setText(QApplication::translate("Camera_play", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        close_camera_bt->setText(QApplication::translate("Camera_play", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        capture_bt->setText(QApplication::translate("Camera_play", "\346\212\223\345\233\276", Q_NULLPTR));
        start_video_bt->setText(QApplication::translate("Camera_play", "\345\274\200\345\247\213\345\275\225\345\203\217", Q_NULLPTR));
        stop_capture_bt->setText(QApplication::translate("Camera_play", "\345\201\234\346\255\242\345\275\225\345\203\217", Q_NULLPTR));
        exit_bt->setText(QApplication::translate("Camera_play", "\351\200\200\345\207\272", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Camera_play", "\346\221\204\345\203\217\345\244\264\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("Camera_play", "\346\221\204\345\203\217\345\244\264\350\256\276\345\244\207", Q_NULLPTR));
        save_pic_file_bt->setText(QApplication::translate("Camera_play", "\350\247\206\351\242\221\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("Camera_play", "\345\275\225\345\210\266\346\227\266\351\227\264", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Camera_play", "\346\221\204\345\203\217\345\244\264\351\242\204\350\247\210", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Camera_play", "\346\212\223\345\217\226\345\233\276\347\211\207", Q_NULLPTR));
        capture_label->setText(QApplication::translate("Camera_play", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Camera_play", "\346\221\204\345\203\217\345\244\264\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        state_label->setText(QApplication::translate("Camera_play", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("Camera_play", "\346\212\223\345\217\226\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        capture_mode_label->setText(QApplication::translate("Camera_play", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("Camera_play", "\345\233\276\347\211\207\344\277\235\345\255\230\344\270\272\357\274\232", Q_NULLPTR));
        pic_save_label->setText(QApplication::translate("Camera_play", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Camera_play: public Ui_Camera_play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_PLAY_H
