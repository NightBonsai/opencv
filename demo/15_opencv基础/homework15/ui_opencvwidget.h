/********************************************************************************
** Form generated from reading UI file 'opencvwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCVWIDGET_H
#define UI_OPENCVWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpencvWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *OpencvWidget)
    {
        if (OpencvWidget->objectName().isEmpty())
            OpencvWidget->setObjectName(QStringLiteral("OpencvWidget"));
        OpencvWidget->resize(843, 542);
        pushButton = new QPushButton(OpencvWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 500, 92, 28));
        pushButton_2 = new QPushButton(OpencvWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 500, 92, 28));
        pushButton_3 = new QPushButton(OpencvWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 500, 92, 28));
        pushButton_4 = new QPushButton(OpencvWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 500, 92, 28));
        pushButton_5 = new QPushButton(OpencvWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(480, 500, 92, 28));
        pushButton_6 = new QPushButton(OpencvWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(590, 500, 92, 28));
        pushButton_7 = new QPushButton(OpencvWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(700, 500, 92, 28));
        label = new QLabel(OpencvWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 359, 480));
        label_2 = new QLabel(OpencvWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 10, 359, 480));

        retranslateUi(OpencvWidget);

        QMetaObject::connectSlotsByName(OpencvWidget);
    } // setupUi

    void retranslateUi(QWidget *OpencvWidget)
    {
        OpencvWidget->setWindowTitle(QApplication::translate("OpencvWidget", "OpencvWidget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("OpencvWidget", "\351\233\252\350\212\261\345\261\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("OpencvWidget", "\351\253\230\346\226\257\346\250\241\347\263\212", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("OpencvWidget", "\344\270\255\345\200\274\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("OpencvWidget", "\346\257\233\347\216\273\347\222\203", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("OpencvWidget", "\347\201\260\345\272\246", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("OpencvWidget", "xy\346\226\271\345\220\221\346\250\241\347\263\212", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("OpencvWidget", "\350\205\220\350\232\200", Q_NULLPTR));
        label->setText(QApplication::translate("OpencvWidget", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("OpencvWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OpencvWidget: public Ui_OpencvWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCVWIDGET_H
