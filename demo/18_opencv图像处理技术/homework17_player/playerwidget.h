#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "playthread.h"

using namespace cv;
using namespace std;
namespace Ui {
class PlayerWidget;
}

class PlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerWidget(QWidget *parent = nullptr);
    ~PlayerWidget();

    void playerWinInit(char* path);     //界面初始化

    void paintEvent(QPaintEvent *arg);  //重绘函数
private:
    Ui::PlayerWidget *ui;

    QImage frame;               //当前播放帧
    int nowFrameNum;            //当前播放帧数
    playThread* playerThread;   //播放线程
signals:
public slots:
    void getFrame(int nowFrameNum,QImage Frame);   //接收当前播放帧
private slots:
    void on_playButton_clicked();               //开始播放
    void on_stopButton_clicked();               //暂停播放
    void on_endButton_clicked();                //结束播放
    void on_restartButton_clicked();            //重新播放
    void on_recordButton_clicked();             //开始录制
    void on_finishRecordButton_clicked();       //结束录制
    void on_horizontalSlider_sliderPressed();   //进度条按下
    void on_horizontalSlider_sliderReleased();  //进度条释放
};

#endif // PLAYERWIDGET_H
