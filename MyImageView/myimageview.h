#pragma once

#include <QtWidgets/QMainWindow>
#include <QImage>
#include "ui_myimageview.h"
#include "imagewidget.h"

class MyImageView : public QMainWindow
{
    Q_OBJECT

public:
    MyImageView(QWidget *parent = Q_NULLPTR);

private slots:
	void on_OpenImage_clicked();
private:
    Ui::MyImageViewClass ui;
	ImageWidget *m_Image;
	QImage image;
public:
	void recvShowPicSignal(QImage image);//接收并显示图片的函数

};
