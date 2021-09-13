/********************************************************************************
** Form generated from reading UI file 'log_tabel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_TABEL_H
#define UI_LOG_TABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log_tabel
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *UserEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *PasswordEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *PasswordEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *PasswordEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *PasswordEdit_4;
    QPushButton *logbt;

    void setupUi(QWidget *Log_tabel)
    {
        if (Log_tabel->objectName().isEmpty())
            Log_tabel->setObjectName(QStringLiteral("Log_tabel"));
        Log_tabel->resize(600, 500);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Log_tabel->sizePolicy().hasHeightForWidth());
        Log_tabel->setSizePolicy(sizePolicy);
        Log_tabel->setMinimumSize(QSize(300, 150));
        Log_tabel->setMaximumSize(QSize(600, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/1.gif"), QSize(), QIcon::Normal, QIcon::Off);
        Log_tabel->setWindowIcon(icon);
        Log_tabel->setStyleSheet(QLatin1String("\n"
"background-image: url(:/resource/2.bmp);"));
        gridLayout = new QGridLayout(Log_tabel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(Log_tabel);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Log_tabel);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        UserEdit = new QLineEdit(Log_tabel);
        UserEdit->setObjectName(QStringLiteral("UserEdit"));
        sizePolicy2.setHeightForWidth(UserEdit->sizePolicy().hasHeightForWidth());
        UserEdit->setSizePolicy(sizePolicy2);
        UserEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(UserEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Log_tabel);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        PasswordEdit = new QLineEdit(Log_tabel);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        sizePolicy2.setHeightForWidth(PasswordEdit->sizePolicy().hasHeightForWidth());
        PasswordEdit->setSizePolicy(sizePolicy2);
        PasswordEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(PasswordEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(Log_tabel);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        PasswordEdit_2 = new QLineEdit(Log_tabel);
        PasswordEdit_2->setObjectName(QStringLiteral("PasswordEdit_2"));
        sizePolicy2.setHeightForWidth(PasswordEdit_2->sizePolicy().hasHeightForWidth());
        PasswordEdit_2->setSizePolicy(sizePolicy2);
        PasswordEdit_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(PasswordEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(Log_tabel);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMaximumSize(QSize(16777215, 16777215));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        PasswordEdit_3 = new QLineEdit(Log_tabel);
        PasswordEdit_3->setObjectName(QStringLiteral("PasswordEdit_3"));
        sizePolicy2.setHeightForWidth(PasswordEdit_3->sizePolicy().hasHeightForWidth());
        PasswordEdit_3->setSizePolicy(sizePolicy2);
        PasswordEdit_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(PasswordEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(Log_tabel);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        comboBox = new QComboBox(Log_tabel);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(89, 134, 200);"));

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(Log_tabel);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        PasswordEdit_4 = new QLineEdit(Log_tabel);
        PasswordEdit_4->setObjectName(QStringLiteral("PasswordEdit_4"));
        sizePolicy2.setHeightForWidth(PasswordEdit_4->sizePolicy().hasHeightForWidth());
        PasswordEdit_4->setSizePolicy(sizePolicy2);
        PasswordEdit_4->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(PasswordEdit_4);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        logbt = new QPushButton(Log_tabel);
        logbt->setObjectName(QStringLiteral("logbt"));
        logbt->setMinimumSize(QSize(50, 0));
        logbt->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(logbt);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Log_tabel);

        QMetaObject::connectSlotsByName(Log_tabel);
    } // setupUi

    void retranslateUi(QWidget *Log_tabel)
    {
        Log_tabel->setWindowTitle(QApplication::translate("Log_tabel", "\346\263\250\345\206\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("Log_tabel", "\346\226\260\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Log_tabel", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Log_tabel", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Log_tabel", "\351\202\256\347\256\261\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Log_tabel", "\346\211\213\346\234\272\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Log_tabel", "\345\257\206\344\277\235\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Log_tabel", "\344\275\240\346\257\215\344\272\262\347\232\204\345\220\215\345\255\227", Q_NULLPTR)
         << QApplication::translate("Log_tabel", "\344\275\240\347\210\266\344\272\262\347\232\204\345\220\215\345\255\227", Q_NULLPTR)
         << QApplication::translate("Log_tabel", "\344\275\240\345\256\266\347\232\204\345\256\240\347\211\251\346\230\257\344\273\200\344\271\210", Q_NULLPTR)
         << QApplication::translate("Log_tabel", "\344\275\240\347\232\204\345\210\235\346\201\213\346\230\257\350\260\201", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("Log_tabel", "\345\241\253\345\206\231\357\274\232", Q_NULLPTR));
        logbt->setText(QApplication::translate("Log_tabel", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Log_tabel: public Ui_Log_tabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_TABEL_H
