#include <QDebug>

int main (int argc, char *argv[])
{
    QList<QString> slist;
    QList<int> ilist;

    QString str("Hello World!");
    slist<<str;
    qDebug()<<slist[0];

    ilist<<1<<2<<3<<4<<5;

    qDebug()<<"Java Style:";
    QListIterator<int> i(ilist); //java style
    for(;i.hasNext();)
        qDebug()<<i.next();

    qDebug()<<"STL Style:";
    QList<int>::iterator o; //stl style
    for(o=ilist.begin();o!=ilist.end();o++)
        qDebug()<<*o;

    return 0;
}
