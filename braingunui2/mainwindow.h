#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "cvimagewidget.h"

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

signals:
    void launchSys();

private:
    Ui::MainWindow *ui;
    CVImageWidget *imageWidget;
};

#endif // MAINWINDOW_H
