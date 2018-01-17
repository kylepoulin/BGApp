#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "cvimagewidget.h"
#include "imgcreate.h"
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void imageShow(const cv::Mat&);

private slots:
    void on_actionStart_triggered();
    void handleResults();

signals:
    void operate();

private:
    Ui::MainWindow *ui;
    CVImageWidget *imageWidget;
    ImgCreate *imgcreate;
    QThread *workerThread;
};

#endif // MAINWINDOW_H
