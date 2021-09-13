/********************************************************************************
** Form generated from reading UI file 'groupwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPWID_H
#define UI_GROUPWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Groupwid
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *expreBt;
    QPushButton *GIFBt;
    QPushButton *shotBt;
    QPushButton *send_fileBt;
    QPushButton *send_picBt;
    QPushButton *otherBt;
    QLabel *label;
    QTextEdit *sendEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBt;
    QPushButton *closeBt;
    QLabel *otherlabel;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *expreBt_2;
    QPushButton *GIFBt_2;
    QPushButton *shotBt_2;
    QPushButton *send_fileBt_2;
    QPushButton *send_picBt_2;
    QPushButton *otherBt_2;
    QLabel *label_2;
    QTextEdit *sendEdit_2;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sendBt_2;
    QPushButton *closeBt_2;
    QTreeWidget *treeWidget;
    QListWidget *recordEdit;

    void setupUi(QWidget *Groupwid)
    {
        if (Groupwid->objectName().isEmpty())
            Groupwid->setObjectName(QStringLiteral("Groupwid"));
        Groupwid->resize(800, 570);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Groupwid->setWindowIcon(icon);
        layoutWidget = new QWidget(Groupwid);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 770, 283, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        expreBt = new QPushButton(layoutWidget);
        expreBt->setObjectName(QStringLiteral("expreBt"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(expreBt->sizePolicy().hasHeightForWidth());
        expreBt->setSizePolicy(sizePolicy);
        expreBt->setMinimumSize(QSize(30, 30));
        expreBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(expreBt);

        GIFBt = new QPushButton(layoutWidget);
        GIFBt->setObjectName(QStringLiteral("GIFBt"));
        sizePolicy.setHeightForWidth(GIFBt->sizePolicy().hasHeightForWidth());
        GIFBt->setSizePolicy(sizePolicy);
        GIFBt->setMinimumSize(QSize(30, 30));
        GIFBt->setMaximumSize(QSize(30, 30));
        GIFBt->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(GIFBt);

        shotBt = new QPushButton(layoutWidget);
        shotBt->setObjectName(QStringLiteral("shotBt"));
        sizePolicy.setHeightForWidth(shotBt->sizePolicy().hasHeightForWidth());
        shotBt->setSizePolicy(sizePolicy);
        shotBt->setMinimumSize(QSize(30, 30));
        shotBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(shotBt);

        send_fileBt = new QPushButton(layoutWidget);
        send_fileBt->setObjectName(QStringLiteral("send_fileBt"));
        sizePolicy.setHeightForWidth(send_fileBt->sizePolicy().hasHeightForWidth());
        send_fileBt->setSizePolicy(sizePolicy);
        send_fileBt->setMinimumSize(QSize(30, 30));
        send_fileBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(send_fileBt);

        send_picBt = new QPushButton(layoutWidget);
        send_picBt->setObjectName(QStringLiteral("send_picBt"));
        sizePolicy.setHeightForWidth(send_picBt->sizePolicy().hasHeightForWidth());
        send_picBt->setSizePolicy(sizePolicy);
        send_picBt->setMinimumSize(QSize(30, 30));
        send_picBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(send_picBt);

        otherBt = new QPushButton(layoutWidget);
        otherBt->setObjectName(QStringLiteral("otherBt"));
        sizePolicy.setHeightForWidth(otherBt->sizePolicy().hasHeightForWidth());
        otherBt->setSizePolicy(sizePolicy);
        otherBt->setMinimumSize(QSize(30, 30));
        otherBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(otherBt);

        label = new QLabel(Groupwid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 760, 630, 50));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        sendEdit = new QTextEdit(Groupwid);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(420, 810, 630, 81));
        sendEdit->setStyleSheet(QStringLiteral("image: url(:/express/1.png);"));
        layoutWidget_2 = new QWidget(Groupwid);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(840, 890, 201, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBt = new QPushButton(layoutWidget_2);
        sendBt->setObjectName(QStringLiteral("sendBt"));

        horizontalLayout->addWidget(sendBt);

        closeBt = new QPushButton(layoutWidget_2);
        closeBt->setObjectName(QStringLiteral("closeBt"));

        horizontalLayout->addWidget(closeBt);

        otherlabel = new QLabel(Groupwid);
        otherlabel->setObjectName(QStringLiteral("otherlabel"));
        otherlabel->setGeometry(QRect(1050, 360, 170, 570));
        otherlabel->setStyleSheet(QStringLiteral("background-color: rgb(201, 255, 235);"));
        otherlabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/leftshow.png")));
        layoutWidget_3 = new QWidget(Groupwid);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 410, 283, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        expreBt_2 = new QPushButton(layoutWidget_3);
        expreBt_2->setObjectName(QStringLiteral("expreBt_2"));
        sizePolicy.setHeightForWidth(expreBt_2->sizePolicy().hasHeightForWidth());
        expreBt_2->setSizePolicy(sizePolicy);
        expreBt_2->setMinimumSize(QSize(30, 30));
        expreBt_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(expreBt_2);

        GIFBt_2 = new QPushButton(layoutWidget_3);
        GIFBt_2->setObjectName(QStringLiteral("GIFBt_2"));
        sizePolicy.setHeightForWidth(GIFBt_2->sizePolicy().hasHeightForWidth());
        GIFBt_2->setSizePolicy(sizePolicy);
        GIFBt_2->setMinimumSize(QSize(30, 30));
        GIFBt_2->setMaximumSize(QSize(30, 30));
        GIFBt_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(GIFBt_2);

        shotBt_2 = new QPushButton(layoutWidget_3);
        shotBt_2->setObjectName(QStringLiteral("shotBt_2"));
        sizePolicy.setHeightForWidth(shotBt_2->sizePolicy().hasHeightForWidth());
        shotBt_2->setSizePolicy(sizePolicy);
        shotBt_2->setMinimumSize(QSize(30, 30));
        shotBt_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(shotBt_2);

        send_fileBt_2 = new QPushButton(layoutWidget_3);
        send_fileBt_2->setObjectName(QStringLiteral("send_fileBt_2"));
        sizePolicy.setHeightForWidth(send_fileBt_2->sizePolicy().hasHeightForWidth());
        send_fileBt_2->setSizePolicy(sizePolicy);
        send_fileBt_2->setMinimumSize(QSize(30, 30));
        send_fileBt_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(send_fileBt_2);

        send_picBt_2 = new QPushButton(layoutWidget_3);
        send_picBt_2->setObjectName(QStringLiteral("send_picBt_2"));
        sizePolicy.setHeightForWidth(send_picBt_2->sizePolicy().hasHeightForWidth());
        send_picBt_2->setSizePolicy(sizePolicy);
        send_picBt_2->setMinimumSize(QSize(30, 30));
        send_picBt_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(send_picBt_2);

        otherBt_2 = new QPushButton(layoutWidget_3);
        otherBt_2->setObjectName(QStringLiteral("otherBt_2"));
        sizePolicy.setHeightForWidth(otherBt_2->sizePolicy().hasHeightForWidth());
        otherBt_2->setSizePolicy(sizePolicy);
        otherBt_2->setMinimumSize(QSize(30, 30));
        otherBt_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(otherBt_2);

        label_2 = new QLabel(Groupwid);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 400, 630, 50));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        sendEdit_2 = new QTextEdit(Groupwid);
        sendEdit_2->setObjectName(QStringLiteral("sendEdit_2"));
        sendEdit_2->setGeometry(QRect(0, 450, 630, 81));
        sendEdit_2->setStyleSheet(QStringLiteral("image: url(:/express/1.png);"));
        layoutWidget_4 = new QWidget(Groupwid);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(430, 530, 201, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        sendBt_2 = new QPushButton(layoutWidget_4);
        sendBt_2->setObjectName(QStringLiteral("sendBt_2"));

        horizontalLayout_4->addWidget(sendBt_2);

        closeBt_2 = new QPushButton(layoutWidget_4);
        closeBt_2->setObjectName(QStringLiteral("closeBt_2"));

        horizontalLayout_4->addWidget(closeBt_2);

        treeWidget = new QTreeWidget(Groupwid);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(630, 0, 171, 561));
        recordEdit = new QListWidget(Groupwid);
        recordEdit->setObjectName(QStringLiteral("recordEdit"));
        recordEdit->setGeometry(QRect(0, 0, 631, 400));
        label_2->raise();
        layoutWidget->raise();
        label->raise();
        sendEdit->raise();
        layoutWidget_2->raise();
        otherlabel->raise();
        layoutWidget_3->raise();
        sendEdit_2->raise();
        layoutWidget_4->raise();
        treeWidget->raise();
        recordEdit->raise();

        retranslateUi(Groupwid);

        QMetaObject::connectSlotsByName(Groupwid);
    } // setupUi

    void retranslateUi(QWidget *Groupwid)
    {
        Groupwid->setWindowTitle(QApplication::translate("Groupwid", "\347\276\244\350\201\212", Q_NULLPTR));
        expreBt->setText(QString());
        GIFBt->setText(QString());
        shotBt->setText(QString());
        send_fileBt->setText(QString());
        send_picBt->setText(QString());
        otherBt->setText(QString());
        label->setText(QString());
        sendBt->setText(QApplication::translate("Groupwid", "\345\217\221\351\200\201", Q_NULLPTR));
        closeBt->setText(QApplication::translate("Groupwid", "\345\205\263\351\227\255", Q_NULLPTR));
        otherlabel->setText(QString());
        expreBt_2->setText(QString());
        GIFBt_2->setText(QString());
        shotBt_2->setText(QString());
        send_fileBt_2->setText(QString());
        send_picBt_2->setText(QString());
        otherBt_2->setText(QString());
        label_2->setText(QString());
        sendBt_2->setText(QApplication::translate("Groupwid", "\345\217\221\351\200\201", Q_NULLPTR));
        closeBt_2->setText(QApplication::translate("Groupwid", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Groupwid: public Ui_Groupwid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPWID_H
