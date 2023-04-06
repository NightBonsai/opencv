#include "videowidget.h"
#include "ui_videowidget.h"

videoWidget::videoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::videoWidget)
{
    ui->setupUi(this);

    //初始化
    this->pthread = new videoThread();

    //信号与槽绑定
    connect(this->pthread,SIGNAL(sendFrame2Win(QImage,QImage)),this,SLOT(getFrame(QImage,QImage)),Qt::BlockingQueuedConnection);
}

videoWidget::~videoWidget()
{
    delete ui;
}

void videoWidget::on_pushButton_clicked()
{
    //开启视频播放线程
    this->pthread->start();
}

void videoWidget::getFrame(QImage frame1,QImage frame2)
{
    //设置输出图片帧
    ui->label->setPixmap(QPixmap::fromImage(frame1).scaled(ui->label->width(),ui->label->height()));
    ui->label_2->setPixmap(QPixmap::fromImage(frame2).scaled(ui->label_2->width(),ui->label_2->height()));
}
