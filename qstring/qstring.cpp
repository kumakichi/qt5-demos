#include <QDebug>

int main (int argc, char *argv[])
{
    QString xxoo;

    xxoo.append(" World");
    qDebug()<<xxoo;
    xxoo.sprintf("%s %s", "san", "100%");
    qDebug()<<xxoo;
    xxoo=QString("  %1    is      %2 ").arg("sanye").arg("the best");
    qDebug()<<xxoo;
    xxoo=xxoo.trimmed();
    qDebug()<<"after trimmed, is %s"<<xxoo;
    xxoo=xxoo.simplified();
    qDebug()<<"then, simplified, got %s"<<xxoo;
    qDebug()<<"xxoo start with sanye,right?"<<xxoo.startsWith("sanye", Qt::CaseInsensitive)<<";contains Best?"<<xxoo.contains("Best",Qt::CaseSensitive);
    bool ok;
    int i = xxoo.toInt(&ok, 10);
    if(ok)
        qDebug()<<"Hehe:"<<i;
    else
        qDebug()<<"Convert string to int failed";
    QByteArray qba = xxoo.toLocal8Bit().constData();
    qDebug()<<qba[0];

    return 0;
}
