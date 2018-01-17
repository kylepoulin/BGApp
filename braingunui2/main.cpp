#include "mainwindow.h"
#include "imgcreate.h"
#include <QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType< cv::Mat >("cv::Mat");
    MainWindow w;
//    ImgCreate c;

    w.show();

    return a.exec();
}
