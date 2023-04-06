#include "videowidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    videoWidget w;
    w.show();

    return a.exec();
}
