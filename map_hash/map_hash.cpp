#include <QDebug>

int main (int argc, char *argv[])
{
    QMap<QString,QString> map;

    qDebug()<<"===== MAP =====";
    map.insert("sanye", "the best");
    map.insert("sans", "shadow hero");
    QMap<QString,QString>::const_iterator i;
    for(i=map.constBegin();i!=map.constEnd();i++)
        qDebug()<<" "<<i.key()<<" "<<i.value();

    qDebug()<<"===== HASH =====";
    QHash<QString,QString> hash; // QHash 更快一点

    hash.insert("sanye", "the best");
    hash.insert("sans", "shadow hero");
    QHash<QString,QString>::const_iterator h;
    for(h=hash.constBegin();h!=hash.constEnd();h++)
        qDebug()<<" "<<h.key()<<" "<<h.value();

    return 0;
}
