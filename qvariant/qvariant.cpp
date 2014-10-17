#include <QDebug>
#include <QVariant>
#include <QColor>

int main (int argc, char *argv[])
{
    QMap<QString,QVariant> map;

    map["name"] = "sans";
    map["score"] = 100;
    map["color"] = QColor(255,0,0);

    qDebug()<<map["name"]<<map["name"].toString();
    qDebug()<<map["score"]<<map["score"].toInt();
    qDebug()<<map["color"]<<map["color"].value<QColor>();
    qDebug()<<qMax(2,3)<<qAbs(-3);

    return 0;
}
