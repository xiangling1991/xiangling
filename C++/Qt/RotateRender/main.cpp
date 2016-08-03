#include "RotateRender.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RotateRender w;
    w.show();

    return a.exec();
}
