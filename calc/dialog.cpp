#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    QString xxoo = "Hello";

    float a = ui->lineEditA->text().toFloat();
    float b = ui->lineEditB->text().toFloat();
    float c = a * b;
    ui->lineEditC->setText(QString::number(c));

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
}
