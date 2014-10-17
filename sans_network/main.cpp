#include <QCoreApplication>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

    QString host_name = QHostInfo::localHostName();
    qDebug()<<host_name;

    QHostInfo host_info = QHostInfo::fromName(host_name);
    QList<QHostAddress> host_addrs = host_info.addresses();
#if 0
    if(!host_addrs.isEmpty())
        qDebug()<<host_addrs.first().toString();
#else
    QList<QHostAddress>::iterator iter;
    for(iter=host_addrs.begin();iter!=host_addrs.end();iter++)
        qDebug()<<(*iter).toString();
#endif

    QList<QNetworkInterface> host_inters = QNetworkInterface::allInterfaces();
    for(int i=0;i<host_inters.count();i++) {
        QNetworkInterface interface = host_inters.at(i);
        qDebug()<<"======================";
        qDebug()<<"Device:"<<interface.name()<<",Hardware:"<<interface.hardwareAddress();
        QList<QNetworkAddressEntry> ips = interface.addressEntries();
        for(int j=0;j<ips.count();j++) {
            QNetworkAddressEntry e = ips.at(j);
            qDebug()<<"IP:"<<e.ip().toString()<<",Netmask:"<<e.netmask().toString()
                   <<",Broadcast:"<<e.broadcast().toString();
        }
    }

    return 0;//a.exec();
}
