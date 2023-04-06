#ifndef OPENCVWIDGET_H
#define OPENCVWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <opencv2/opencv.hpp>   //opencv头文件

using namespace cv;             //opencv命名空间
namespace Ui {
class OpencvWidget;
}

class OpencvWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OpencvWidget(QWidget *parent = nullptr);
    ~OpencvWidget();

    QImage Mat2QImage(Mat &mat);    //Mat转QImage

    void showGetImg();              //输出处理前的图片
    void showOutputImg();           //输出处理后的图片
private:
    Ui::OpencvWidget *ui;

    Mat getImg,outputImg;           //获取的图片-输出的图片-opencv
    QImage getImgQt,outputImgQt;    //获取的图片-输出的图片-Qt
signals:
public slots:
    void snowProcess();             //雪花屏
    void GaussBlurProcess();        //高斯模糊
    void medianBlurProcess();       //中值滤波
    void glassProcess();            //毛玻璃特效
    void grayProcess();             //灰度处理
    void blurProcess();             //xy方向模糊
    void erodeProcess();            //腐蚀
};

#endif // OPENCVWIDGET_H
