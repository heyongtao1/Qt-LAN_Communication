/********************************************************************************
** Form generated from reading UI file 'communication.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATION_H
#define UI_COMMUNICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <login/rotatingstackedwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Communication
{
public:
    QAction *actionAdd;
    QAction *actionRemove;
    QFrame *line;
    QFrame *line_2;
    RotatingStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *User_Head_Bt_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *User_Name_label_2;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *User_uniName_label_2;
    QFrame *line_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *friend_bt;
    QPushButton *group_bt;
    QPushButton *chart_bt;
    QPushButton *media_bt;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *other_operations_bt;
    QSpacerItem *horizontalSpacer;
    QPushButton *Multimedia_Bt;
    QPushButton *addBt;

    void setupUi(QWidget *Communication)
    {
        if (Communication->objectName().isEmpty())
            Communication->setObjectName(QStringLiteral("Communication"));
        Communication->resize(380, 640);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Communication->setWindowIcon(icon);
        Communication->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        actionAdd = new QAction(Communication);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionRemove = new QAction(Communication);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        line = new QFrame(Communication);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 580, 380, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Communication);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-1, 150, 381, 10));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        stackedWidget = new RotatingStackedWidget(Communication);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 391, 150));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        User_Head_Bt_2 = new QPushButton(page_2);
        User_Head_Bt_2->setObjectName(QStringLiteral("User_Head_Bt_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(User_Head_Bt_2->sizePolicy().hasHeightForWidth());
        User_Head_Bt_2->setSizePolicy(sizePolicy);
        User_Head_Bt_2->setMinimumSize(QSize(90, 90));
        User_Head_Bt_2->setMaximumSize(QSize(90, 90));

        horizontalLayout_3->addWidget(User_Head_Bt_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(60, 40));
        label_7->setMaximumSize(QSize(60, 40));

        horizontalLayout_5->addWidget(label_7);

        User_Name_label_2 = new QLabel(page_2);
        User_Name_label_2->setObjectName(QStringLiteral("User_Name_label_2"));

        horizontalLayout_5->addWidget(User_Name_label_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(80, 40));
        label_8->setMaximumSize(QSize(80, 40));

        horizontalLayout_6->addWidget(label_8);

        User_uniName_label_2 = new QLabel(page_2);
        User_uniName_label_2->setObjectName(QStringLiteral("User_uniName_label_2"));
        User_uniName_label_2->setMinimumSize(QSize(200, 40));
        User_uniName_label_2->setMaximumSize(QSize(200, 40));

        horizontalLayout_6->addWidget(User_uniName_label_2);


        gridLayout_4->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        line_3 = new QFrame(Communication);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 510, 380, 10));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(Communication);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 520, 361, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        friend_bt = new QPushButton(layoutWidget);
        friend_bt->setObjectName(QStringLiteral("friend_bt"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(friend_bt->sizePolicy().hasHeightForWidth());
        friend_bt->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(friend_bt);

        group_bt = new QPushButton(layoutWidget);
        group_bt->setObjectName(QStringLiteral("group_bt"));
        sizePolicy1.setHeightForWidth(group_bt->sizePolicy().hasHeightForWidth());
        group_bt->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(group_bt);

        chart_bt = new QPushButton(layoutWidget);
        chart_bt->setObjectName(QStringLiteral("chart_bt"));
        sizePolicy1.setHeightForWidth(chart_bt->sizePolicy().hasHeightForWidth());
        chart_bt->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(chart_bt);

        media_bt = new QPushButton(layoutWidget);
        media_bt->setObjectName(QStringLiteral("media_bt"));
        sizePolicy1.setHeightForWidth(media_bt->sizePolicy().hasHeightForWidth());
        media_bt->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(media_bt);

        layoutWidget1 = new QWidget(Communication);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 590, 361, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        other_operations_bt = new QPushButton(layoutWidget1);
        other_operations_bt->setObjectName(QStringLiteral("other_operations_bt"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/comicon/ic_sysmen.png"), QSize(), QIcon::Normal, QIcon::Off);
        other_operations_bt->setIcon(icon1);
        other_operations_bt->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(other_operations_bt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Multimedia_Bt = new QPushButton(layoutWidget1);
        Multimedia_Bt->setObjectName(QStringLiteral("Multimedia_Bt"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/comicon/applay.png"), QSize(), QIcon::Normal, QIcon::Off);
        Multimedia_Bt->setIcon(icon2);
        Multimedia_Bt->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(Multimedia_Bt);

        addBt = new QPushButton(layoutWidget1);
        addBt->setObjectName(QStringLiteral("addBt"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/comicon/ic_user_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addBt->setIcon(icon3);
        addBt->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(addBt);


        retranslateUi(Communication);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Communication);
    } // setupUi

    void retranslateUi(QWidget *Communication)
    {
        Communication->setWindowTitle(QApplication::translate("Communication", "Laconnected", Q_NULLPTR));
        actionAdd->setText(QApplication::translate("Communication", "\346\267\273\345\212\240", Q_NULLPTR));
        actionRemove->setText(QApplication::translate("Communication", "\345\210\240\351\231\244", Q_NULLPTR));
        User_Head_Bt_2->setText(QString());
        label_7->setText(QApplication::translate("Communication", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        User_Name_label_2->setText(QApplication::translate("Communication", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("Communication", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", Q_NULLPTR));
        User_uniName_label_2->setText(QApplication::translate("Communication", "TextLabel", Q_NULLPTR));
        friend_bt->setText(QApplication::translate("Communication", "\345\245\275\345\217\213", Q_NULLPTR));
        group_bt->setText(QApplication::translate("Communication", "\347\276\244\350\201\212", Q_NULLPTR));
        chart_bt->setText(QApplication::translate("Communication", "\344\274\232\350\257\235", Q_NULLPTR));
        media_bt->setText(QApplication::translate("Communication", "\345\272\224\347\224\250", Q_NULLPTR));
        other_operations_bt->setText(QString());
        Multimedia_Bt->setText(QString());
        addBt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Communication: public Ui_Communication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATION_H
