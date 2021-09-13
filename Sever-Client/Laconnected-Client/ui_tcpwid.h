/********************************************************************************
** Form generated from reading UI file 'tcpwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPWID_H
#define UI_TCPWID_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tcpwid
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBt;
    QPushButton *closeBt;
    QLabel *otherlabel;
    QLabel *label;
    QTextEdit *sendEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *expreBt;
    QPushButton *GIFBt;
    QPushButton *shotBt;
    QPushButton *send_fileBt;
    QPushButton *send_picBt;
    QPushButton *otherBt;
    QListWidget *recordEdit;

    void setupUi(QWidget *Tcpwid)
    {
        if (Tcpwid->objectName().isEmpty())
            Tcpwid->setObjectName(QStringLiteral("Tcpwid"));
        Tcpwid->resize(800, 570);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Tcpwid->sizePolicy().hasHeightForWidth());
        Tcpwid->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Tcpwid->setWindowIcon(icon);
        layoutWidget = new QWidget(Tcpwid);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(420, 530, 201, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBt = new QPushButton(layoutWidget);
        sendBt->setObjectName(QStringLiteral("sendBt"));

        horizontalLayout->addWidget(sendBt);

        closeBt = new QPushButton(layoutWidget);
        closeBt->setObjectName(QStringLiteral("closeBt"));

        horizontalLayout->addWidget(closeBt);

        otherlabel = new QLabel(Tcpwid);
        otherlabel->setObjectName(QStringLiteral("otherlabel"));
        otherlabel->setGeometry(QRect(630, 0, 170, 570));
        otherlabel->setStyleSheet(QStringLiteral("background-color: rgb(201, 255, 235);"));
        otherlabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/leftshow.png")));
        label = new QLabel(Tcpwid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 400, 630, 50));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        sendEdit = new QTextEdit(Tcpwid);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(0, 450, 630, 81));
        sendEdit->setStyleSheet(QStringLiteral("image: url(:/express/1.png);"));
        layoutWidget1 = new QWidget(Tcpwid);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 410, 283, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        expreBt = new QPushButton(layoutWidget1);
        expreBt->setObjectName(QStringLiteral("expreBt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(expreBt->sizePolicy().hasHeightForWidth());
        expreBt->setSizePolicy(sizePolicy1);
        expreBt->setMinimumSize(QSize(30, 30));
        expreBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(expreBt);

        GIFBt = new QPushButton(layoutWidget1);
        GIFBt->setObjectName(QStringLiteral("GIFBt"));
        sizePolicy1.setHeightForWidth(GIFBt->sizePolicy().hasHeightForWidth());
        GIFBt->setSizePolicy(sizePolicy1);
        GIFBt->setMinimumSize(QSize(30, 30));
        GIFBt->setMaximumSize(QSize(30, 30));
        GIFBt->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(GIFBt);

        shotBt = new QPushButton(layoutWidget1);
        shotBt->setObjectName(QStringLiteral("shotBt"));
        sizePolicy1.setHeightForWidth(shotBt->sizePolicy().hasHeightForWidth());
        shotBt->setSizePolicy(sizePolicy1);
        shotBt->setMinimumSize(QSize(30, 30));
        shotBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(shotBt);

        send_fileBt = new QPushButton(layoutWidget1);
        send_fileBt->setObjectName(QStringLiteral("send_fileBt"));
        sizePolicy1.setHeightForWidth(send_fileBt->sizePolicy().hasHeightForWidth());
        send_fileBt->setSizePolicy(sizePolicy1);
        send_fileBt->setMinimumSize(QSize(30, 30));
        send_fileBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(send_fileBt);

        send_picBt = new QPushButton(layoutWidget1);
        send_picBt->setObjectName(QStringLiteral("send_picBt"));
        sizePolicy1.setHeightForWidth(send_picBt->sizePolicy().hasHeightForWidth());
        send_picBt->setSizePolicy(sizePolicy1);
        send_picBt->setMinimumSize(QSize(30, 30));
        send_picBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(send_picBt);

        otherBt = new QPushButton(layoutWidget1);
        otherBt->setObjectName(QStringLiteral("otherBt"));
        sizePolicy1.setHeightForWidth(otherBt->sizePolicy().hasHeightForWidth());
        otherBt->setSizePolicy(sizePolicy1);
        otherBt->setMinimumSize(QSize(30, 30));
        otherBt->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(otherBt);

        recordEdit = new QListWidget(Tcpwid);
        recordEdit->setObjectName(QStringLiteral("recordEdit"));
        recordEdit->setGeometry(QRect(0, 0, 631, 400));

        retranslateUi(Tcpwid);

        QMetaObject::connectSlotsByName(Tcpwid);
    } // setupUi

    void retranslateUi(QWidget *Tcpwid)
    {
        Tcpwid->setWindowTitle(QApplication::translate("Tcpwid", "\350\201\212\345\244\251", Q_NULLPTR));
        sendBt->setText(QApplication::translate("Tcpwid", "\345\217\221\351\200\201", Q_NULLPTR));
        closeBt->setText(QApplication::translate("Tcpwid", "\345\205\263\351\227\255", Q_NULLPTR));
        otherlabel->setText(QString());
        label->setText(QString());
        expreBt->setText(QString());
        GIFBt->setText(QString());
        shotBt->setText(QString());
        send_fileBt->setText(QString());
        send_picBt->setText(QString());
        otherBt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tcpwid: public Ui_Tcpwid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPWID_H
