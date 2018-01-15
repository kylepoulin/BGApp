#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageWidget = new CVImageWidget();
    setCentralWidget(imageWidget);

}

void MainWindow::imageShow(const cv::Mat& image)
{
    imageWidget->showImage(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStart_triggered()
{
    emit launchSys();
}
