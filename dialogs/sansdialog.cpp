#include "sansdialog.h"
#include "ui_sansdialog.h"
#include <QDebug>
#include <QDialog>
#include <QInputDialog>

sansDialog::sansDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sansDialog)
{
    ui->setupUi(this);
}

sansDialog::~sansDialog()
{
    qDebug()<<ui->te2->toPlainText();
    qDebug()<<"bye from sansdialog.cpp, ~sansDialog()!";
    delete ui;
}

void sansDialog::on_psex_clicked()
{
    QStringList sexItems;
    sexItems<<"male"<<"female";

    bool ok;
    QString sexItem = QInputDialog::getItem(this,tr("please choose sex"),tr("what the hell"),sexItems,0,false,&ok);
    if(ok)
        ui->lesex->setText(sexItem);
}

void sansDialog::on_page_clicked()
{
   bool ok;

   int age = QInputDialog::getInt(this,tr("input xx age"),tr("aage"),15,0,180,1,&ok);
   if(ok)
       ui->leage->setText(QString::number(age));
}
