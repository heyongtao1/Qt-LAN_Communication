/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
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
#include <login/rotatingstackedwidget.h>
#include <rotatingstackedwidget.h>
QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    RotatingStackedWidget *stackedWidget;
    QWidget *page_3;
    QPushButton *logonBt;
    QLabel *label;
    QComboBox *log_otherBt;
    QPushButton *regBt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *head_bt;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *narrow_bt;
    QPushButton *set_bt;
    QPushButton *close_bt;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *QQlabel_4;
    QComboBox *stateBt_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *userlabel_4;
    QLineEdit *UserEdit_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *locklabel_4;
    QLineEdit *PasswordEdit_4;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *re_password_4;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *auto_log_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page_4;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_18;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *ser_setip_Edit;
    QLabel *label_4;
    QLineEdit *ser_setprot_Edit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cancel_bt;
    QPushButton *yes_bt;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(620, 500);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setMinimumSize(QSize(620, 500));
        Login->setMaximumSize(QSize(620, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new RotatingStackedWidget(Login);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setFocusPolicy(Qt::StrongFocus);
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        logonBt = new QPushButton(page_3);
        logonBt->setObjectName(QStringLiteral("logonBt"));
        logonBt->setGeometry(QRect(0, 440, 93, 28));
        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 600, 200));
        label->setStyleSheet(QStringLiteral("background-color: rgb(25, 202, 255);"));
        log_otherBt = new QComboBox(page_3);
        log_otherBt->setObjectName(QStringLiteral("log_otherBt"));
        log_otherBt->setGeometry(QRect(530, 440, 61, 28));
        log_otherBt->setCursor(QCursor(Qt::ArrowCursor));
        log_otherBt->setMouseTracking(false);
        log_otherBt->setFocusPolicy(Qt::WheelFocus);
        log_otherBt->setEditable(false);
        log_otherBt->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        regBt = new QPushButton(page_3);
        regBt->setObjectName(QStringLiteral("regBt"));
        regBt->setGeometry(QRect(250, 410, 240, 50));
        regBt->setMaximumSize(QSize(240, 50));
        QFont font;
        font.setPointSize(15);
        regBt->setFont(font);
        regBt->setStyleSheet(QStringLiteral("background-color:#24CBFE;"));
        layoutWidget = new QWidget(page_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 591, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        head_bt = new QPushButton(layoutWidget);
        head_bt->setObjectName(QStringLiteral("head_bt"));
        head_bt->setMaximumSize(QSize(24, 24));
        head_bt->setFocusPolicy(Qt::NoFocus);
        head_bt->setIcon(icon);
        head_bt->setCheckable(false);

        horizontalLayout->addWidget(head_bt);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        narrow_bt = new QPushButton(layoutWidget);
        narrow_bt->setObjectName(QStringLiteral("narrow_bt"));
        narrow_bt->setMaximumSize(QSize(24, 24));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/comicon/ic_min_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        narrow_bt->setIcon(icon1);

        horizontalLayout->addWidget(narrow_bt);

        set_bt = new QPushButton(layoutWidget);
        set_bt->setObjectName(QStringLiteral("set_bt"));
        set_bt->setMaximumSize(QSize(24, 24));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/comicon/ic_login_cfg.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_bt->setIcon(icon2);

        horizontalLayout->addWidget(set_bt);

        close_bt = new QPushButton(layoutWidget);
        close_bt->setObjectName(QStringLiteral("close_bt"));
        close_bt->setMaximumSize(QSize(24, 24));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/comicon/ic_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_bt->setIcon(icon3);

        horizontalLayout->addWidget(close_bt);

        layoutWidget1 = new QWidget(page_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 250, 591, 148));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        QQlabel_4 = new QLabel(layoutWidget1);
        QQlabel_4->setObjectName(QStringLiteral("QQlabel_4"));
        QQlabel_4->setMinimumSize(QSize(112, 100));

        verticalLayout_4->addWidget(QQlabel_4);

        stateBt_4 = new QComboBox(layoutWidget1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resource/\345\234\250\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        stateBt_4->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resource/Q\346\210\221\345\220\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        stateBt_4->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resource/\345\277\231\347\242\214.png"), QSize(), QIcon::Normal, QIcon::Off);
        stateBt_4->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resource/\345\213\277\346\211\223\346\211\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        stateBt_4->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resource/\347\246\273\345\274\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        stateBt_4->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resource/\351\232\220\350\272\253.png"), QSize(), QIcon::Normal, QIcon::Off);
        stateBt_4->addItem(icon9, QString());
        stateBt_4->setObjectName(QStringLiteral("stateBt_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stateBt_4->sizePolicy().hasHeightForWidth());
        stateBt_4->setSizePolicy(sizePolicy1);
        stateBt_4->setMaximumSize(QSize(112, 20));
        stateBt_4->setCursor(QCursor(Qt::ArrowCursor));
        stateBt_4->setMouseTracking(false);
        stateBt_4->setFocusPolicy(Qt::WheelFocus);
        stateBt_4->setEditable(false);
        stateBt_4->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        verticalLayout_4->addWidget(stateBt_4);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        userlabel_4 = new QLabel(layoutWidget1);
        userlabel_4->setObjectName(QStringLiteral("userlabel_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(userlabel_4->sizePolicy().hasHeightForWidth());
        userlabel_4->setSizePolicy(sizePolicy2);
        userlabel_4->setMaximumSize(QSize(22, 22));

        horizontalLayout_10->addWidget(userlabel_4);

        UserEdit_4 = new QLineEdit(layoutWidget1);
        UserEdit_4->setObjectName(QStringLiteral("UserEdit_4"));
        sizePolicy1.setHeightForWidth(UserEdit_4->sizePolicy().hasHeightForWidth());
        UserEdit_4->setSizePolicy(sizePolicy1);
        UserEdit_4->setMinimumSize(QSize(240, 50));
        UserEdit_4->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        UserEdit_4->setFont(font1);

        horizontalLayout_10->addWidget(UserEdit_4);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        locklabel_4 = new QLabel(layoutWidget1);
        locklabel_4->setObjectName(QStringLiteral("locklabel_4"));
        sizePolicy2.setHeightForWidth(locklabel_4->sizePolicy().hasHeightForWidth());
        locklabel_4->setSizePolicy(sizePolicy2);
        locklabel_4->setMaximumSize(QSize(22, 22));

        horizontalLayout_12->addWidget(locklabel_4);

        PasswordEdit_4 = new QLineEdit(layoutWidget1);
        PasswordEdit_4->setObjectName(QStringLiteral("PasswordEdit_4"));
        sizePolicy1.setHeightForWidth(PasswordEdit_4->sizePolicy().hasHeightForWidth());
        PasswordEdit_4->setSizePolicy(sizePolicy1);
        PasswordEdit_4->setMinimumSize(QSize(240, 50));
        PasswordEdit_4->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setUnderline(false);
        PasswordEdit_4->setFont(font2);
        PasswordEdit_4->setEchoMode(QLineEdit::Password);

        horizontalLayout_12->addWidget(PasswordEdit_4);


        verticalLayout->addLayout(horizontalLayout_12);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        re_password_4 = new QCheckBox(layoutWidget1);
        re_password_4->setObjectName(QStringLiteral("re_password_4"));

        horizontalLayout_11->addWidget(re_password_4);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        auto_log_4 = new QCheckBox(layoutWidget1);
        auto_log_4->setObjectName(QStringLiteral("auto_log_4"));

        horizontalLayout_11->addWidget(auto_log_4);


        verticalLayout_2->addLayout(horizontalLayout_11);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        gridLayout_2 = new QGridLayout(page_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(page_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_7 = new QVBoxLayout(groupBox_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(-1, -1, 0, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        ser_setip_Edit = new QLineEdit(groupBox_2);
        ser_setip_Edit->setObjectName(QStringLiteral("ser_setip_Edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ser_setip_Edit);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        ser_setprot_Edit = new QLineEdit(groupBox_2);
        ser_setprot_Edit->setObjectName(QStringLiteral("ser_setprot_Edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ser_setprot_Edit);


        horizontalLayout_18->addLayout(formLayout);


        verticalLayout_7->addLayout(horizontalLayout_18);

        verticalSpacer = new QSpacerItem(17, 317, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);

        cancel_bt = new QPushButton(groupBox_2);
        cancel_bt->setObjectName(QStringLiteral("cancel_bt"));

        horizontalLayout_17->addWidget(cancel_bt);

        yes_bt = new QPushButton(groupBox_2);
        yes_bt->setObjectName(QStringLiteral("yes_bt"));

        horizontalLayout_17->addWidget(yes_bt);


        verticalLayout_7->addLayout(horizontalLayout_17);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 2);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Laconnected", Q_NULLPTR));
        logonBt->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        label->setText(QString());
        log_otherBt->clear();
        log_otherBt->insertItems(0, QStringList()
         << QApplication::translate("Login", "\345\270\256\345\212\251", Q_NULLPTR)
         << QApplication::translate("Login", "\351\205\215\347\275\256", Q_NULLPTR)
        );
        regBt->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        head_bt->setText(QString());
        label_2->setText(QApplication::translate("Login", "Laconnected", Q_NULLPTR));
        narrow_bt->setText(QString());
        set_bt->setText(QString());
        close_bt->setText(QString());
        QQlabel_4->setText(QApplication::translate("Login", "TextLabel", Q_NULLPTR));
        stateBt_4->setItemText(0, QApplication::translate("Login", "\345\234\250\347\272\277", Q_NULLPTR));
        stateBt_4->setItemText(1, QApplication::translate("Login", "Q\346\210\221\345\220\247", Q_NULLPTR));
        stateBt_4->setItemText(2, QApplication::translate("Login", "\345\277\231\347\242\214", Q_NULLPTR));
        stateBt_4->setItemText(3, QApplication::translate("Login", "\350\257\267\345\213\277\346\211\223\346\211\260", Q_NULLPTR));
        stateBt_4->setItemText(4, QApplication::translate("Login", "\347\246\273\345\274\200", Q_NULLPTR));
        stateBt_4->setItemText(5, QApplication::translate("Login", "\351\232\220\350\272\253", Q_NULLPTR));

        userlabel_4->setText(QApplication::translate("Login", "TextLabel", Q_NULLPTR));
        UserEdit_4->setPlaceholderText(QApplication::translate("Login", "Laconnected\350\264\246\345\217\267/\346\211\213\346\234\272\345\217\267/\351\202\256\347\256\261", Q_NULLPTR));
        locklabel_4->setText(QApplication::translate("Login", "TextLabel", Q_NULLPTR));
        PasswordEdit_4->setPlaceholderText(QApplication::translate("Login", "\345\257\206\347\240\201", Q_NULLPTR));
        re_password_4->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        auto_log_4->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\351\205\215\347\275\256\357\274\232", Q_NULLPTR));
        ser_setip_Edit->setText(QApplication::translate("Login", "192.168.238.1", Q_NULLPTR));
        label_4->setText(QApplication::translate("Login", "\346\266\210\346\201\257\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        ser_setprot_Edit->setText(QApplication::translate("Login", "8800", Q_NULLPTR));
        cancel_bt->setText(QApplication::translate("Login", "\345\217\226\346\266\210", Q_NULLPTR));
        yes_bt->setText(QApplication::translate("Login", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
