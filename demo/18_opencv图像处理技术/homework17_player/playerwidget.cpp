#include "playerwidget.h"
#include "ui_playerwidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerWidget)
{
    ui->setupUi(this);
    this->playerWinInit("carMove2.mp4");
}

PlayerWidget::~PlayerWidget()
{
    delete ui;
    disconnect(this->playerThread,SIGNAL(send2UI(int,QImage)),this,SLOT(getFrame(int,QImage)));
    delete playerThread;
}

void PlayerWidget::playerWinInit(char* path)
{
    //播放线程初始化
    this->playerThread = new playThread(path);

    //进度条初始化
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(this->playerThread->getTotalFrameNum());

    //进度条拖动范围
    ui->horizontalSlider->setRange(0,this->playerThread->getTotalFrameNum());

    //进度条步长——进度条移动一步，往前一帧
    ui->horizontalSlider->setSingleStep(1);
    ui->horizontalSlider->setValue(0);

    //label控件初始化
    this->nowFrameNum = 0;
    ui->nowFrame->setText(QString::number(0));
    ui->totalFrame->setText(QString::number(this->playerThread->getTotalFrameNum()));

    //信号与槽
    connect(this->playerThread,SIGNAL(send2UI(int,QImage)),this,SLOT(getFrame(int,QImage)),Qt::BlockingQueuedConnection);
}

void PlayerWidget::paintEvent(QPaintEvent *arg)
{
    //播放当前图片帧
    ui->playFrame->setPixmap(QPixmap::fromImage(this->frame));
}

void PlayerWidget::getFrame(int nowFrameNum, QImage Frame)
{
    //接收数据信息
    this->nowFrameNum = nowFrameNum;
    this->frame = Frame;
    this->frame = this->frame.scaled(ui->playFrame->width(),ui->playFrame->height());

    //刷新进度条输出
    ui->nowFrame->setText(QString::number(nowFrameNum));
    ui->horizontalSlider->setValue(nowFrameNum);

    //调用重绘函数
    this->update();
}

void PlayerWidget::on_playButton_clicked()
{
    this->playerThread->setRunFlag(true);   //线程运行标志位
    this->playerThread->start();            //开启播放线程
    qDebug()<<"thread start";
}

void PlayerWidget::on_stopButton_clicked()
{
    //如果当前线程暂停
    if(this->playerThread->getRunFlag() == false)
    {
        //继续执行线程
        this->playerThread->resumeThread();
        ui->stopButton->setText("暂停播放");
    }
    else if(this->playerThread->getRunFlag() == true)
    {
        //暂停执行线程
        this->playerThread->pauseThread();
        ui->stopButton->setText("继续播放");
    }
}

void PlayerWidget::on_endButton_clicked()
{
    this->playerThread->stopThread();
    if(this->playerThread->isRunning() == false && this->playerThread != NULL)
    {
        //解除信号与槽绑定
        disconnect(this->playerThread,SIGNAL(send2UI(int,QImage)),this,SLOT(getFrame(int,QImage)));

        delete this->playerThread;  //释放线程内存
        this->playerThread = nullptr;
        ui->endButton->setEnabled(false);
    }
}

void PlayerWidget::on_restartButton_clicked()
{
    this->playerThread->stopThread();
    if(this->playerThread->isRunning() == false && this->playerThread != NULL)
    {
        //解除信号与槽绑定
        disconnect(this->playerThread,SIGNAL(send2UI(int,QImage)),this,SLOT(getFrame(int,QImage)));
        delete this->playerThread;

        //开启一个新播放线程
        this->playerWinInit("carMove2.mp4");
        this->playerThread->start();
        this->playerThread->setRunFlag(true);
    }
}

void PlayerWidget::on_recordButton_clicked()
{
    this->playerThread->setRecordFlag(true);
}

void PlayerWidget::on_finishRecordButton_clicked()
{
    this->playerThread->setRecordFlag(false);
}

void PlayerWidget::on_horizontalSlider_sliderPressed()
{
    //线程暂停
    this->playerThread->pauseThread();
}

void PlayerWidget::on_horizontalSlider_sliderReleased()
{
    //将拖动后的进度条数值传给线程中当前帧进行重新赋值
    this->playerThread->setNowFrameNum(ui->horizontalSlider->value());
    this->playerThread->resumeThread();
}
