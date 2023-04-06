#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "videothread.h"

namespace Ui {
class videoWidget;
}

class videoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit videoWidget(QWidget *parent = nullptr);
    ~videoWidget();

private:
    Ui::videoWidget *ui;

    videoThread *pthread;             //视频播放类
signals:
private slots:
    void on_pushButton_clicked();   //线程开启
    void getFrame(QImage frame1,QImage frame2);
};

#endif // VIDEOWIDGET_H
