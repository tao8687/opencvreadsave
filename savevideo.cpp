#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using namespace cv;
int test1() {

    VideoCapture capture;
    Mat frame;
    frame = capture.open("rtsp://admin:a12345678@192.168.1.103:554/Streaming/Channels/101");
    if (!capture.isOpened())
    {
        printf("can not open ...\n");
        return -1;
    }
    namedWindow("output", CV_WINDOW_AUTOSIZE);

    while (capture.read(frame))
    {
        imshow("output", frame);
        waitKey(10);
    }
    capture.release();
    return 0;
}
int main(int argc, char** argv)
{
    //定义视频的宽度和高度
    Size s(320, 240);
    //创建 writer，并指定 FOURCC 及 FPS 等参数
    VideoWriter writer = VideoWriter("myvideo.mp4",
        CV_FOURCC('M','P','4','V'), 25, s);
    //检查是否成功创建
    if (!writer.isOpened())
    {
        cerr << "Can not create video file.\n" << endl;
        return -1;
    }
    //视频帧
    Mat frame(s, CV_8UC3);
    for (int i = 0; i < 100; i++)
    {
        //将图像置为黑色
        frame = Scalar::all(0);
        //将整数 i 转为 i 字符串类型
        char text[128];
        snprintf(text, sizeof(text), "%d", i);
        //将数字绘到画面上
        putText(frame, text, Point(s.width / 3, s.height / 3),
            FONT_HERSHEY_SCRIPT_SIMPLEX, 3,
            Scalar(0, 0, 255), 3, 8);
        //将图像写入视频
        writer << frame;
    }
    //退出程序时会自动关闭视频文件
    return 0;
}
int test(int argc, char** argv)
{
    //定义视频的宽度和高度
    Size s(320, 240);
    //创建 writer，并指定 FOURCC 及 FPS 等参数
    VideoWriter writer = VideoWriter("myvideo.mp4",
        CV_FOURCC('M', 'P', '4', 'V'), 25, s);
    //检查是否成功创建
    if (!writer.isOpened())
    {
        cerr << "Can not create video file.\n" << endl;
        return -1;
    }
    cv::VideoCapture cap("1.out");
    if (!cap.isOpened())
    {
        //cerr << "无法连接到相机" << endl;
        printf("Unable to connect to camera");
        return 1;
    }

    cv::Mat frame;
    for (int i = 0; i < 50; i++)
    {
        cap >> frame;
        //将图像写入视频
        writer << frame;
    }
    //退出程序时会自动关闭视频文件
    return 0;
}
