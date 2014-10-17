#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(0);
    proc = new QProcess();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tb_vol_down_clicked()
{
    proc->start("xdotool key XF86AudioLowerVolume");
}

void MainWindow::on_tb_vol_up_clicked()
{
    proc->start("xdotool key XF86AudioRaiseVolume");
}

void MainWindow::on_tb_play_clicked()
{
    proc->start("xdotool key XF86AudioPlay");
}

void MainWindow::on_tb_pause_clicked()
{
    proc->start("xdotool key XF86AudioPause");
}

void MainWindow::on_tb_stop_clicked()
{
    proc->start("xdotool key XF86AudioStop");
}

void MainWindow::on_tb_mon_brightness_up_clicked()
{
    proc->start("xdotool key XF86MonBrightnessUp");
}

void MainWindow::on_tb_brightness_down_clicked()
{
    proc->start("xdotool key XF86MonBrightnessDown");
}

void MainWindow::on_tb_prev_clicked()
{
    proc->start("xdotool key XF86AudioPrev");
}

void MainWindow::on_tb_next_clicked()
{
    proc->start("xdotool key XF86AudioNext");
}

void MainWindow::on_toolButton_clicked()
{
    proc->start("xdotool key XF86AudioMedia");
}
