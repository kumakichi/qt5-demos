#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Virtual Fn");
    w.setWindowIcon(QIcon(":/img/Fn.png"));
    w.show();

    return a.exec();
}
