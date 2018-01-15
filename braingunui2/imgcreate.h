#ifndef IMGCREATE_H
#define IMGCREATE_H

#include <QObject>
#include <opencv2/opencv.hpp>

class ImgCreate : public QObject
{
    Q_OBJECT
public:
    explicit ImgCreate(QObject *parent = 0);

signals:
    void sendImg(const cv::Mat&);

public slots:
    void launch();

private:

};

#endif // IMGCREATE_H
