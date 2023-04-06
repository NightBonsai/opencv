#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QWidget>
#include <vector>

using namespace cv;
using namespace std;
class videoThread:public QThread
{
    Q_OBJECT
public:
    videoThread();
    ~videoThread();

    void run();                                     //线程run函数重载
    QImage Mat2QImage(Mat mat);                     //Mat转QImage
    Mat moveCatch(Mat &oldFrame,Mat &newFrame);    //识别移动车辆
private:
    Mat oldFrame,newFrame;          //视频前后帧
    QImage oldFrameQt,newFrameQt;
    int count;                      //视频当前播放帧数量
    VideoCapture video;             //视频
signals:
    void sendFrame2Win(QImage frame1,QImage frame2);
public slots:
};

#endif // VIDEOTHREAD_H
