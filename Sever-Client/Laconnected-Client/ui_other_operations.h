/********************************************************************************
** Form generated from reading UI file 'other_operations.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHER_OPERATIONS_H
#define UI_OTHER_OPERATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Other_operations
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *exit_login_bt;

    void setupUi(QWidget *Other_operations)
    {
        if (Other_operations->objectName().isEmpty())
            Other_operations->setObjectName(QStringLiteral("Other_operations"));
        Other_operations->resize(117, 192);
        Other_operations->setStyleSheet(QStringLiteral("background-color: rgb(29, 203, 255);"));
        gridLayout = new QGridLayout(Other_operations);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(Other_operations);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Other_operations);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Other_operations);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(Other_operations);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        exit_login_bt = new QPushButton(Other_operations);
        exit_login_bt->setObjectName(QStringLiteral("exit_login_bt"));

        verticalLayout->addWidget(exit_login_bt);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Other_operations);

        QMetaObject::connectSlotsByName(Other_operations);
    } // setupUi

    void retranslateUi(QWidget *Other_operations)
    {
        Other_operations->setWindowTitle(QApplication::translate("Other_operations", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Other_operations", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Other_operations", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Other_operations", "\350\275\257\344\273\266\345\212\251\346\211\213", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Other_operations", "\346\266\210\346\201\257\347\256\241\347\220\206\345\231\250", Q_NULLPTR));
        exit_login_bt->setText(QApplication::translate("Other_operations", "\345\210\207\346\215\242\350\264\246\346\210\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Other_operations: public Ui_Other_operations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHER_OPERATIONS_H
