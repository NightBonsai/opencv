/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoWidget
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *videoWidget)
    {
        if (videoWidget->objectName().isEmpty())
            videoWidget->setObjectName(QStringLiteral("videoWidget"));
        videoWidget->resize(1066, 571);
        pushButton = new QPushButton(videoWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 500, 92, 28));
        label = new QLabel(videoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 501, 441));
        label_2 = new QLabel(videoWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 20, 501, 441));

        retranslateUi(videoWidget);

        QMetaObject::connectSlotsByName(videoWidget);
    } // setupUi

    void retranslateUi(QWidget *videoWidget)
    {
        videoWidget->setWindowTitle(QApplication::translate("videoWidget", "videoWidget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("videoWidget", "\347\272\277\347\250\213\345\220\257\345\212\250", Q_NULLPTR));
        label->setText(QApplication::translate("videoWidget", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("videoWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videoWidget: public Ui_videoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
