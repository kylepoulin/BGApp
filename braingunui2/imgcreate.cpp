#include "imgcreate.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <QThread>
#include <opencv2/opencv.hpp>


ImgCreate::ImgCreate(QObject *parent) : QObject(parent)
{

}

ImgCreate::~ImgCreate()
{

}

void ImgCreate::doWork()
{
    //cv::Mat image = cv::imread("/home/braingun/Downloads/test.jpg",true);

    //inserting from previous test

    int g;
        char *inname = "/home/braingun/Downloads/SineWaveCaptureValues.txt";
        std::ifstream infile(inname);

        cv::Mat image = cv::Mat(500,500,CV_8UC3, cv::Scalar(0,0,200));
        while(infile >> g){
            for(int i=0; i<image.rows; i++){
                for(int j=0; j<image.cols; j++){
                    image.at<cv::Vec3b>(i,j)[0]= floor((g-98.0)/511*255);
                    image.at<cv::Vec3b>(i,j)[2]= (floor((1-((g-98.0)/511))*255));
                }
            }
            emit sendImg(image);
            QThread::msleep(10);
        }
}
