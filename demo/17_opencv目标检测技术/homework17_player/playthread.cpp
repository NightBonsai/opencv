#include "playthread.h"

playThread::playThread(char* path)
{
    //打开视频
    if(this->video.open(path))
    {
        qDebug()<<"video open success";

        this->totalFrameNum = video.get(CV_CAP_PROP_FRAME_COUNT);  //获取视频总帧数
        qDebug()<<"video totalFrameNum = "<<this->totalFrameNum;

        this->frameWidth = video.get(CV_CAP_PROP_FRAME_WIDTH);      //获取帧宽高
        this->frameHeight = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    }

    //初始化
    this->nowFrameNum = 0;
    this->recordFrameNum = 0;
    this->runFlag = false;
    this->stopFlag = false;
    this->recordFlag = false;
}

playThread::~playThread()
{

}

void playThread::run()
{
    //控制线程结束
    while(this->stopFlag == false)
    {
        //控制线程暂停和继续
        if(this->runFlag == true)
        {
            //如果线程读到一帧
            if(video.read(frame))
            {
                this->nowFrameNum++;                       //当前帧数递增
                QImage Frame = this->Mat2QImage(frame);
                emit send2UI(this->nowFrameNum,Frame);     //当前帧发送给UI界面

                //视频录制业务
                if(this->recordFlag == true)
                {
                    cvtColor(frame,frame,CV_BGR2RGB);

                    //录制300ms
                    if(this->recordFrameNum < 300)
                    {
                        this->videoWriter.write(frame);     //图片帧写入写视频对象
                        this->recordFrameNum++;
                        qDebug()<<"recordFrameNum = "<<this->recordFrameNum;
                    }
                    else
                    {
                        //录制保存
                        this->videoWriter.release();

                        //释放置0
                        this->recordFrameNum = 0;
                        this->recordFlag = false;
                    }
                }
                else
                {
                    //录制保存
                    this->videoWriter.release();
                    this->recordFrameNum = 0;
                }
            }
        }

        msleep(2);
    }
    video.release();
    qDebug()<<"thread move away";
}

QImage playThread::Mat2QImage(Mat mat)
{
    //Mat转QImage 颜色
    cvtColor(mat,mat,COLOR_BGR2RGB);
    //Mat转QImage 像素
    QImage frame(mat.data,mat.cols,mat.rows,mat.step,QImage::Format_RGB888);
    return frame;
}

int playThread::getTotalFrameNum() const
{
    return totalFrameNum;
}

void playThread::setTotalFrameNum(int value)
{
    totalFrameNum = value;
}

int playThread::getNowFrameNum() const
{
    return nowFrameNum;
}

void playThread::setNowFrameNum(int value)
{
    nowFrameNum = value;

    //拖动进度条，改变画面：opencv跳帧操作
    this->video.set(CV_CAP_PROP_POS_FRAMES,this->nowFrameNum);
}

bool playThread::getRunFlag() const
{
    return runFlag;
}

void playThread::setRunFlag(bool value)
{
    runFlag = value;
}

bool playThread::getStopFlag() const
{
    return stopFlag;
}

void playThread::setStopFlag(bool value)
{
    stopFlag = value;
}

bool playThread::getRecordFlag() const
{
    return recordFlag;
}

void playThread::setRecordFlag(bool value)
{
    recordFlag = value;

    //录制业务
    if(this->recordFlag == true)
    {
        //拼接视频保存地址
        QDateTime currentTime = QDateTime::currentDateTime();
        QString fileName = "./video/";
        fileName = fileName + currentTime.toString("yyyy_MM_dd_hh_mm_ss");
        fileName = fileName + ".avi";
        qDebug()<<"fileName = "<<fileName;

        //写视频对象初始化
        this->videoWriter.open(
                                fileName.toStdString(),                     //保存路径
                                VideoWriter::fourcc('M','J','P','G'),       //编码类型
                                25,                                         //帧率
                                Size(this->frameWidth,this->frameHeight),   //尺寸大小
                                true                                        //彩色为true，灰度为false
                                );
    }
}

void playThread::pauseThread()
{
    qDebug()<<"pause thread";

    //如果当前线程正在运行
    if(QThread::isRunning() && this->runFlag == true)
    {
        this->runFlag = false;
    }
}

void playThread::resumeThread()
{
    qDebug()<<"resume thread";

    //如果当前线程暂停中
    if(QThread::isRunning() && this->runFlag == false)
    {
        this->runFlag = true;
    }
}

void playThread::stopThread()
{
    qDebug()<<"stop thread";

    if(QThread::isRunning() && this->stopFlag == false)
    {
        this->stopFlag = true;
        QThread::quit();
        QThread::wait();
        QThread::exit();
//        this->terminate();
    }
}


