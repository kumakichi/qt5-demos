#include <QApplication>
#include "mapwidget.h"
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MapWidget mapWidget;
    mapWidget.show();
    
    return a.exec();
}
