#include <QFileDialog>
#include "myimageview.h"

MyImageView::MyImageView(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	connect(ui.m_btn_Open, SIGNAL(clicked()), this, SLOT(on_OpenImage_clicked()));
}

void MyImageView::on_OpenImage_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
		this, "open image file",
		".",
		"Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
	if (fileName != "")
	{
		if (image.load(fileName))
		{
			recvShowPicSignal(image);
		}
	}
}

void MyImageView::recvShowPicSignal(QImage image)
{
	QPixmap ConvertPixmap = QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
	QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//Ҫ��QGraphicsView�ͱ���Ҫ��QGraphicsScene��������
	m_Image = new ImageWidget(&ConvertPixmap);//ʵ������ImageWidget�Ķ���m_Image������̳���QGraphicsItem�����Լ�д����
	int nwith = ui.ImageGraphic->width();//��ȡ����ؼ�Graphics View�Ŀ��
	int nheight = ui.ImageGraphic->height();//��ȡ����ؼ�Graphics View�ĸ߶�
	m_Image->setQGraphicsViewWH(nwith, nheight);//������ؼ�Graphics View��width��height������m_Image��
	qgraphicsScene->addItem(m_Image);//��QGraphicsItem�����Ž�QGraphicsScene��
	ui.ImageGraphic->setSceneRect(QRectF(-(nwith / 2), -(nheight / 2), nwith, nheight));//ʹ�Ӵ��Ĵ�С�̶���ԭʼ��С��������ͼƬ�ķŴ���Ŵ�Ĭ��״̬��ͼƬ�Ŵ��ʱ���Ӵ����߻��Զ����ֹ������������Ӵ��ڵ���Ұ���󣩣���ֹͼƬ�Ŵ��������С��ʱ���Ӵ�̫���������۲�ͼƬ
	ui.ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
	ui.ImageGraphic->setFocus();//������Ľ������õ���ǰGraphics View�ؼ�
}
