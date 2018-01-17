#ifndef IMGCREATE_H
#define IMGCREATE_H

#include <QObject>
#include <opencv2/opencv.hpp>

class ImgCreate : public QObject
{
    Q_OBJECT
public:
    explicit ImgCreate(QObject *parent = 0);
    ~ImgCreate();

signals:
    void sendImg(const cv::Mat&);
    void resultReady();

public slots:
    void doWork();

private:

};

#endif // IMGCREATE_H
