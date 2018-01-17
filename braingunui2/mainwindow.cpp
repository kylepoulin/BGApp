#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageWidget = new CVImageWidget();
    setCentralWidget(imageWidget);
    workerThread = new QThread;
    imgcreate = new ImgCreate();
    imgcreate->moveToThread(workerThread);
    QObject::connect(workerThread, SIGNAL(finished()), imgcreate, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(operate()), imgcreate, SLOT(doWork()));
    QObject::connect(imgcreate, SIGNAL(resultReady()), this, SLOT(handleResults()));

    QObject::connect(imgcreate,SIGNAL(sendImg(const cv::Mat&)), this, SLOT(imageShow(const cv::Mat&)));
}

void MainWindow::imageShow(const cv::Mat& image)
{
    imageWidget->showImage(image);
}

MainWindow::~MainWindow()
{
    workerThread->quit();
    workerThread->wait(100);
    delete workerThread;
    delete imageWidget;
    delete ui;
}

void MainWindow::on_actionStart_triggered()
{
    workerThread->start();
    emit operate();
}

void MainWindow::handleResults()
{

}
