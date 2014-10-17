#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    ui->setupUi(this);
    ui->te->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbmore_clicked()
{
   if(ui->te->isHidden())
       ui->te->show();
   else
       ui->te->hide();
}
