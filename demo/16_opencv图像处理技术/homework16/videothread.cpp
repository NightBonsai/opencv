#include "videothread.h"

videoThread::videoThread()
{
    //初始化
    this->count = 0;
    this->video.open("carMove2.mp4");    //视频文件初始化
}

videoThread::~videoThread()
{

}

void videoThread::run()
{
    Mat resFrame;   //保存处理后的图片帧

    //读取视频图片帧
    while(this->video.read(this->newFrame))
    {
        this->count++;
        if(1 == this->count)
        {
            resFrame = this->newFrame;
        }
        else
        {
            //处理图片帧
            resFrame = this->moveCatch(this->oldFrame,this->newFrame);
        }

        this->oldFrame = this->newFrame.clone();

        //发送处理后的图片帧给窗口界面
        this->oldFrameQt = this->Mat2QImage(oldFrame);
        this->newFrameQt = this->Mat2QImage(resFrame);
        emit sendFrame2Win(oldFrameQt,newFrameQt);

        msleep(20);
    }
}

QImage videoThread::Mat2QImage(Mat mat)
{
    //Mat转QImage 颜色
    cvtColor(mat,mat,COLOR_BGR2RGB);
    //Mat转QImage 像素
    QImage frame(mat.data,mat.cols,mat.rows,mat.step,QImage::Format_RGB888);
    return frame;
}

Mat videoThread::moveCatch(Mat &oldFrame, Mat &newFrame)
{
    Mat oldGray,newGray;
    Mat resFrame = newFrame.clone();

    //1.灰度处理——正常图片变为灰度图24位->8位，压缩内存提高运行效率
    cvtColor(oldFrame,oldGray,CV_BGR2GRAY);
    cvtColor(newFrame,newGray,CV_BGR2GRAY);

    //2.侦差处理——利用像素点绝对值查找两帧之间像素差异
    Mat diff;
    absdiff(oldGray,newGray,diff);

    //3.二值化处理——将灰度图二值化，利用阈值转置为黑白图，此时出现白色噪点
    threshold(diff,diff,25,255,CV_THRESH_BINARY);

    //4.降噪处理——开运算：开去外（去除物体外部噪点），先腐蚀再膨胀；闭运算：闭去内（去除物体内部噪点），先膨胀再腐蚀
        //4.1.腐蚀处理——消除多于白色小像素点；CNN：卷积神经网络
        Mat element1 = getStructuringElement(MORPH_RECT,Size(3,3));
        erode(diff,diff,element1);

        //4.2.膨胀处理——将白色像素点扩大；CNN：卷积神经网络
        Mat element2 = getStructuringElement(MORPH_RECT,Size(21,21));
        dilate(diff,diff,element2);

    //5.提取关键点
        //5.1.查找特征点
        vector<vector<Point>> contours;
        findContours(diff,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,Point(0,0));

        //5.2.提取关键点
        vector<vector<Point>> contours_poly(contours.size());
        vector<Rect> boundRect(contours.size());

        //5.3.确定四个点用于框选目标物体
        int x,y,w,h;
        int num = contours.size();
        for(int i = 0;i < num;i++)
        {
            approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);

            //多边拟合
            boundRect[i] = boundingRect(Mat(contours_poly[i]));
            x = boundRect[i].x;
            y = boundRect[i].y;
            w = boundRect[i].width;
            h = boundRect[i].height;

            //绘制矩形
            rectangle(resFrame,Point(x,y),Point(x+w,y+h),Scalar(0,255,0),4);
        }

    //返回处理完成的图片帧
    return resFrame;
}
