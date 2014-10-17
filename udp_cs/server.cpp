#include <QCoreApplication>
#include <QTimer>
#include <QUdpSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    int port = 5555;

    udpSocket = new QUdpSocket(this);
    QTimer timer = new QTimer(this);


    return 0;//a.exec();
}
