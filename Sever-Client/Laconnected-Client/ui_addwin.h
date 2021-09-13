/********************************************************************************
** Form generated from reading UI file 'addwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIN_H
#define UI_ADDWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addwin
{
public:
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *add_NameEdit;
    QPushButton *addBt;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *UDPname_addproEdit;
    QTextEdit *textEdit_2;
    QPushButton *UDP_addBt;

    void setupUi(QWidget *Addwin)
    {
        if (Addwin->objectName().isEmpty())
            Addwin->setObjectName(QStringLiteral("Addwin"));
        Addwin->resize(450, 195);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Addwin->setWindowIcon(icon);
        gridLayout_5 = new QGridLayout(Addwin);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tabWidget = new QTabWidget(Addwin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        add_NameEdit = new QLineEdit(tab);
        add_NameEdit->setObjectName(QStringLiteral("add_NameEdit"));

        horizontalLayout->addWidget(add_NameEdit);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        addBt = new QPushButton(tab);
        addBt->setObjectName(QStringLiteral("addBt"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addBt->sizePolicy().hasHeightForWidth());
        addBt->setSizePolicy(sizePolicy);

        gridLayout->addWidget(addBt, 0, 1, 1, 1);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        UDPname_addproEdit = new QLineEdit(tab_2);
        UDPname_addproEdit->setObjectName(QStringLiteral("UDPname_addproEdit"));

        horizontalLayout_2->addWidget(UDPname_addproEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(textEdit_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        UDP_addBt = new QPushButton(tab_2);
        UDP_addBt->setObjectName(QStringLiteral("UDP_addBt"));
        sizePolicy.setHeightForWidth(UDP_addBt->sizePolicy().hasHeightForWidth());
        UDP_addBt->setSizePolicy(sizePolicy);
        UDP_addBt->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(UDP_addBt);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Addwin);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Addwin);
    } // setupUi

    void retranslateUi(QWidget *Addwin)
    {
        Addwin->setWindowTitle(QApplication::translate("Addwin", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        label->setText(QApplication::translate("Addwin", "\350\264\246\345\217\267/\345\221\242\347\247\260", Q_NULLPTR));
        add_NameEdit->setText(QString());
        addBt->setText(QApplication::translate("Addwin", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        textEdit->setPlaceholderText(QApplication::translate("Addwin", "\351\231\204\345\212\240\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Addwin", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        label_5->setText(QApplication::translate("Addwin", "\347\276\244\350\201\212  \345\220\215\347\247\260", Q_NULLPTR));
        textEdit_2->setPlaceholderText(QApplication::translate("Addwin", "\351\231\204\345\212\240\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        UDP_addBt->setText(QApplication::translate("Addwin", "\345\210\233\345\273\272\350\256\250\350\256\272\n"
"\347\273\204/\347\276\244\350\201\212", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Addwin", "\345\210\233\345\273\272\350\256\250\350\256\272\347\273\204/\347\276\244\350\201\212", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Addwin: public Ui_Addwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIN_H
