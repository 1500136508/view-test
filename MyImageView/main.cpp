#include "myimageview.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyImageView w;
    w.show();
    return a.exec();
}
