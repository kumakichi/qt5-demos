#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include "sansdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_xxfile_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("xx select dir"), "/home");//, QFileDialog::ShowDirsOnly);
    if ( path.isNull() == false )
    {
        qDebug()<<path;
    } else {
        qDebug()<<"shit!";
    }
}

void MainWindow::on_xxfile_2_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,tr("san select file"),"/home",
                                                "xxtxt files (*.txt);;xxcpp ff (*.cpp);;qemu img files (*.img)");
    if ( file.isNull() == false )
    {
        qDebug()<<file;
    } else {
        qDebug()<<"holy!";
    }
}

void MainWindow::on_pushButton_clicked()
{
    QColor c = QColorDialog::getColor();
    if(c.isValid()) {
        ui->xxframe->setPalette(QPalette(c));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
        ui->xxle->setFont(f);
}

void MainWindow::on_pushButton_3_clicked()
{
    sansDialog hehe;
    hehe.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::Button xxoo = QMessageBox::information(this,tr("msgbox title"),"Hello World",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    switch(xxoo) {
    case QMessageBox::Ok:
        qDebug()<<"OK!";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"Cancel!";
        break;
    default:
        break;
    }
}
