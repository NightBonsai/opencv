#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

typedef struct data
{
    Mat img;                //图片数据
    vector<Point2f> points; //保存鼠标点击后的点坐标
}DATA;

void mouseHundle(int event,int x,int y,int flag,void* arg)
{
    DATA* pd = (DATA*)arg;
    if(event == EVENT_LBUTTONDOWN)
    {
        //画圆点，标出点击的位置
        circle(pd->img,Point(x,y),3,Scalar(0,0,255),3,CV_AA);

        //获取鼠标选择的四个点
        if(pd->points.size() < 4)
        {
            pd->points.push_back(Point2f(x,y));
        }
        imshow("image",pd->img);
    }

}

void process1()
{
    //Mat对象初始化
    Mat result = Mat::zeros(600,800,CV_8UC1);                   //进行透视变换宽高参数要反过来，镜像坐标
    Mat image = imread("book2.jpg");
    imshow("image",image);
    DATA d;
    d.img = image;

    //设置转化后图片的四个顶点坐标
    vector<Point2f> obj;
    obj.push_back(Point2f(0,0));
    obj.push_back(Point2f(800,0));
    obj.push_back(Point2f(800,600));
    obj.push_back(Point2f(0,600));

    //设置鼠标事件
    setMouseCallback("image",mouseHundle,&d);

    waitKey(0);     //等待键盘输入

    //获取转置矩阵
    Mat res = findHomography(d.points,obj,CV_RANSAC);
    imshow("res",res);

    //进行透视变换
    warpPerspective(image,result,res,result.size());
    imshow("result",result);

    waitKey(0);
}

int main()
{
    process1();

    return 0;
}
