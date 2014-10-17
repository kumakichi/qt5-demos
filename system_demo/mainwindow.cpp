#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    q =new QProcess();
    connect(q,SIGNAL(readyRead()),this,SLOT(cmd_show()));

    ui->show_edit->setReadOnly(true);

       // 关键是这句
   pCodec = QTextCodec::codecForLocale();
}

MainWindow::~MainWindow()
{
    delete q;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    str ="";
    ui->show_edit->setText(str);

    QString str =ui->cmd_program->text();
    q->start(str);
}

void MainWindow::cmd_show()
{
    QByteArray processStdOutInfo = q->readAll();
    str += pCodec->toUnicode(processStdOutInfo,processStdOutInfo.length());
    ui->show_edit->setText(str);
    ui->show_edit->verticalScrollBar()->setValue(ui->show_edit->verticalScrollBar()->maximumHeight());


}


