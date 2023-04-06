#include "opencvwidget.h"
#include "ui_opencvwidget.h"

OpencvWidget::OpencvWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpencvWidget)
{
    ui->setupUi(this);

    //获取图片
    this->getImg = cv::imread("20230301155544.jpg");
    this->outputImg = cv::imread("20230301155544.jpg");

    //输出图片
    this->showGetImg();
    this->showOutputImg();

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(snowProcess()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(GaussBlurProcess()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(medianBlurProcess()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(glassProcess()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(grayProcess()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(blurProcess()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(erodeProcess()));
}

OpencvWidget::~OpencvWidget()
{
    delete ui;
}

QImage OpencvWidget::Mat2QImage(Mat &mat)
{
    //Mat转QImage 颜色
    cvtColor(mat, mat, COLOR_BGR2RGB);
    //Mat转QImage 像素
    QImage qim((const unsigned char*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return qim;
}

void OpencvWidget::showGetImg()
{
    this->getImgQt = Mat2QImage(getImg);               //Mat转QImage
    ui->label->setPixmap(QPixmap::fromImage(this->getImgQt).scaled(ui->label->width(),ui->label->height()));   //QLabel输出图片
}

void OpencvWidget::showOutputImg()
{
    this->outputImgQt = Mat2QImage(outputImg);               //Mat转QImage
    ui->label_2->setPixmap(QPixmap::fromImage(this->outputImgQt).scaled(ui->label->width(),ui->label->height()));   //QLabel输出图片
}

void OpencvWidget::snowProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    int row = this->outputImg.rows;                                 //像素二维矩阵函数
    int col = this->outputImg.cols * this->outputImg.channels();    //像素二维矩阵列数
    for (int i = 0;i < row;i++)
    {
        uchar* data = this->outputImg.ptr<uchar>(i);
        for(int j = 0;j < col;j++)
        {
            //雪花屏特效
            int q = rand() % col;
            data[q] = 155;          //某些通道随机改成155
            //色彩反转
//            data[j] = data[j] - 50;
            //图像变暗处理
//            data[j] = data[j] / 2;
        }
    }

    //输出图片
    this->showGetImg();
    this->showOutputImg();
}

void OpencvWidget::GaussBlurProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    cv::GaussianBlur(this->outputImg,this->outputImg,Size(9,9),0);

    //输出图片
    this->showGetImg();
    this->showOutputImg();
}

void OpencvWidget::medianBlurProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    cv::medianBlur(this->outputImg,this->outputImg,7);

    //输出图片
    this->showGetImg();
    this->showOutputImg();
}

void OpencvWidget::glassProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    RNG rng;
    int random = 0;
    int num = 5;

    for (int i = 0;i < this->outputImg.rows-num;i++)
    {
        for(int j = 0;j < this->outputImg.cols-num;j++)
        {
            random = rng.uniform(0,num);
            this->outputImg.at<Vec3b>(i,j)[0] = this->outputImg.at<Vec3b>(i+random,j+random)[0];
            this->outputImg.at<Vec3b>(i,j)[1] = this->outputImg.at<Vec3b>(i+random,j+random)[1];
            this->outputImg.at<Vec3b>(i,j)[2] = this->outputImg.at<Vec3b>(i+random,j+random)[2];
        }
    }

    //输出图片
    this->showGetImg();
    this->showOutputImg();
}

void OpencvWidget::grayProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    //灰度处理 灰度是单通道8位 QImage是24位三通道
    cvtColor(this->outputImg,this->outputImg,COLOR_BGR2GRAY);
    cvtColor(this->outputImg,this->outputImg,COLOR_GRAY2BGR);


    //输出图片
    this->showGetImg();
    this->showOutputImg();
}

void OpencvWidget::blurProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    cv::blur(this->outputImg,this->outputImg,Size(10,10));

    //输出图片
    this->showGetImg();
    this->showOutputImg();
}

void OpencvWidget::erodeProcess()
{
    //初始化
    this->outputImg = cv::imread("20230301155544.jpg");

    //腐蚀
    Mat element = cv::getStructuringElement(MORPH_RECT,Size(5,5));
    cv::erode(this->outputImg,this->outputImg,element);

    //输出图片
    this->showGetImg();
    this->showOutputImg();
}
