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
    //������Ƶ�Ŀ�Ⱥ͸߶�
    Size s(320, 240);
    //���� writer����ָ�� FOURCC �� FPS �Ȳ���
    VideoWriter writer = VideoWriter("myvideo.mp4",
        CV_FOURCC('M','P','4','V'), 25, s);
    //����Ƿ�ɹ�����
    if (!writer.isOpened())
    {
        cerr << "Can not create video file.\n" << endl;
        return -1;
    }
    //��Ƶ֡
    Mat frame(s, CV_8UC3);
    for (int i = 0; i < 100; i++)
    {
        //��ͼ����Ϊ��ɫ
        frame = Scalar::all(0);
        //������ i תΪ i �ַ�������
        char text[128];
        snprintf(text, sizeof(text), "%d", i);
        //�����ֻ浽������
        putText(frame, text, Point(s.width / 3, s.height / 3),
            FONT_HERSHEY_SCRIPT_SIMPLEX, 3,
            Scalar(0, 0, 255), 3, 8);
        //��ͼ��д����Ƶ
        writer << frame;
    }
    //�˳�����ʱ���Զ��ر���Ƶ�ļ�
    return 0;
}
int test(int argc, char** argv)
{
    //������Ƶ�Ŀ�Ⱥ͸߶�
    Size s(320, 240);
    //���� writer����ָ�� FOURCC �� FPS �Ȳ���
    VideoWriter writer = VideoWriter("myvideo.mp4",
        CV_FOURCC('M', 'P', '4', 'V'), 25, s);
    //����Ƿ�ɹ�����
    if (!writer.isOpened())
    {
        cerr << "Can not create video file.\n" << endl;
        return -1;
    }
    cv::VideoCapture cap("1.out");
    if (!cap.isOpened())
    {
        //cerr << "�޷����ӵ����" << endl;
        printf("Unable to connect to camera");
        return 1;
    }

    cv::Mat frame;
    for (int i = 0; i < 50; i++)
    {
        cap >> frame;
        //��ͼ��д����Ƶ
        writer << frame;
    }
    //�˳�����ʱ���Զ��ر���Ƶ�ļ�
    return 0;
}
