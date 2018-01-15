#include "mainwindow.h"
#include "imgcreate.h"
#include <QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ImgCreate c;

    QObject::connect(&c,SIGNAL(sendImg(const cv::Mat&)), &w, SLOT(imageShow(const cv::Mat&)));
    QObject::connect(&w,SIGNAL(launchSys()), &c, SLOT(launch()));
    w.show();

    return a.exec();
}
