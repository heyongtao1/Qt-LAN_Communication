/********************************************************************************
** Form generated from reading UI file 'express.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPRESS_H
#define UI_EXPRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Express
{
public:
    QTableWidget *qTableWidget;

    void setupUi(QWidget *Express)
    {
        if (Express->objectName().isEmpty())
            Express->setObjectName(QStringLiteral("Express"));
        Express->resize(264, 264);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Express->setWindowIcon(icon);
        qTableWidget = new QTableWidget(Express);
        qTableWidget->setObjectName(QStringLiteral("qTableWidget"));
        qTableWidget->setGeometry(QRect(0, 0, 264, 264));

        retranslateUi(Express);

        QMetaObject::connectSlotsByName(Express);
    } // setupUi

    void retranslateUi(QWidget *Express)
    {
        Express->setWindowTitle(QApplication::translate("Express", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Express: public Ui_Express {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPRESS_H
