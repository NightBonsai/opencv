#ifndef PLAYTHREAD_H
#define PLAYTHREAD_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QDateTime>
#include <QDebug>
#include <QString>
#include <QImage>

using namespace std;
using namespace cv;
class playThread:public QThread
{
    Q_OBJECT
public:
    playThread(char* path);
    ~playThread();

    void run();
    QImage Mat2QImage(Mat mat); //Mat转QImage

    int getTotalFrameNum() const;
    void setTotalFrameNum(int value);
    int getNowFrameNum() const;
    void setNowFrameNum(int value);
    bool getRunFlag() const;
    void setRunFlag(bool value);
    bool getStopFlag() const;
    void setStopFlag(bool value);
    bool getRecordFlag() const;
    void setRecordFlag(bool value);

    void pauseThread();     //暂停线程
    void resumeThread();    //继续线程
    void stopThread();      //停止线程
private:
    VideoCapture video;             //视频对象
    VideoWriter videoWriter;        //写视频对象
    Mat frame;                      //当前显示图片帧
    int totalFrameNum,nowFrameNum;  //视频总帧数，视频当前帧数
    int recordFrameNum;             //录制的视频帧数
    int frameWidth,frameHeight;     //帧高帧宽
    bool runFlag;                   //线程运行or暂停标志位
    bool stopFlag;                  //结束标志位
    bool recordFlag;                //录制标志位
signals:
    void send2UI(int nowFrame,QImage frame);
public slots:

};

#endif // PLAYTHREAD_H
