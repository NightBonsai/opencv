#include "opencvwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    OpencvWidget w;
    w.show();

    return a.exec();
}
