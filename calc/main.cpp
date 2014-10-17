#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    Qt::WindowFlags flags = Qt::WindowStaysOnTopHint;
    flags |= Qt::FramelessWindowHint;
    w.setWindowFlags(flags);
    w.show();

    return a.exec();
}
