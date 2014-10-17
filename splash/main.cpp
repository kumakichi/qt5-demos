#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 0
    QSplashScreen splash(QPixmap(":/img/swd3e.png"));
    splash.show();
    a.processEvents(); // respond to mouse,keyborad while in splashing

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash.showMessage(QObject::tr("Setting up the main window ... "),topRight,Qt::red);
    QThread::sleep(3);

    splash.showMessage(QObject::tr("Loading modules ... "),topRight,Qt::red);
    QThread::sleep(3);

    MainWindow w;
    w.show();
    splash.finish(&w);
#else
    QSplashScreen *splash = new QSplashScreen();
    splash->setPixmap(QPixmap(":/img/swd3e.png"));
    splash->show();
    a.processEvents();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window ... "),topRight,Qt::red);
    QThread::sleep(3);

    splash->showMessage(QObject::tr("Loading modules ... "),topRight,Qt::red);
    QThread::sleep(3);

    MainWindow w;
    w.show();
    splash->finish(&w);
    delete(splash);

#endif
    
    return a.exec();
}
