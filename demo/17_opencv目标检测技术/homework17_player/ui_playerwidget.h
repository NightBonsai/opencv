/********************************************************************************
** Form generated from reading UI file 'playerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERWIDGET_H
#define UI_PLAYERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerWidget
{
public:
    QLabel *playFrame;
    QSlider *horizontalSlider;
    QLabel *nowFrame;
    QLabel *label_3;
    QLabel *totalFrame;
    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *endButton;
    QPushButton *restartButton;
    QPushButton *recordButton;
    QPushButton *finishRecordButton;

    void setupUi(QWidget *PlayerWidget)
    {
        if (PlayerWidget->objectName().isEmpty())
            PlayerWidget->setObjectName(QStringLiteral("PlayerWidget"));
        PlayerWidget->resize(1280, 720);
        playFrame = new QLabel(PlayerWidget);
        playFrame->setObjectName(QStringLiteral("playFrame"));
        playFrame->setGeometry(QRect(20, 10, 1241, 591));
        horizontalSlider = new QSlider(PlayerWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 630, 1241, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        nowFrame = new QLabel(PlayerWidget);
        nowFrame->setObjectName(QStringLiteral("nowFrame"));
        nowFrame->setGeometry(QRect(30, 610, 72, 15));
        label_3 = new QLabel(PlayerWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 610, 72, 15));
        totalFrame = new QLabel(PlayerWidget);
        totalFrame->setObjectName(QStringLiteral("totalFrame"));
        totalFrame->setGeometry(QRect(150, 610, 72, 15));
        playButton = new QPushButton(PlayerWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(50, 680, 92, 28));
        stopButton = new QPushButton(PlayerWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(170, 680, 92, 28));
        endButton = new QPushButton(PlayerWidget);
        endButton->setObjectName(QStringLiteral("endButton"));
        endButton->setGeometry(QRect(290, 680, 92, 28));
        restartButton = new QPushButton(PlayerWidget);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setGeometry(QRect(410, 680, 92, 28));
        recordButton = new QPushButton(PlayerWidget);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setGeometry(QRect(530, 680, 92, 28));
        finishRecordButton = new QPushButton(PlayerWidget);
        finishRecordButton->setObjectName(QStringLiteral("finishRecordButton"));
        finishRecordButton->setGeometry(QRect(650, 680, 92, 28));

        retranslateUi(PlayerWidget);

        QMetaObject::connectSlotsByName(PlayerWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayerWidget)
    {
        PlayerWidget->setWindowTitle(QApplication::translate("PlayerWidget", "PlayerWidget", Q_NULLPTR));
        playFrame->setText(QApplication::translate("PlayerWidget", "TextLabel", Q_NULLPTR));
        nowFrame->setText(QApplication::translate("PlayerWidget", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("PlayerWidget", "/", Q_NULLPTR));
        totalFrame->setText(QApplication::translate("PlayerWidget", "TextLabel", Q_NULLPTR));
        playButton->setText(QApplication::translate("PlayerWidget", "\345\274\200\345\247\213\346\222\255\346\224\276", Q_NULLPTR));
        stopButton->setText(QApplication::translate("PlayerWidget", "\346\232\202\345\201\234\346\222\255\346\224\276", Q_NULLPTR));
        endButton->setText(QApplication::translate("PlayerWidget", "\347\273\223\346\235\237\346\222\255\346\224\276", Q_NULLPTR));
        restartButton->setText(QApplication::translate("PlayerWidget", "\351\207\215\346\226\260\346\222\255\346\224\276", Q_NULLPTR));
        recordButton->setText(QApplication::translate("PlayerWidget", "\345\274\200\345\247\213\345\275\225\345\210\266", Q_NULLPTR));
        finishRecordButton->setText(QApplication::translate("PlayerWidget", "\347\273\223\346\235\237\345\275\225\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayerWidget: public Ui_PlayerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERWIDGET_H
