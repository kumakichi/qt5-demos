#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tb_vol_down_clicked();

    void on_tb_vol_up_clicked();

    void on_tb_play_clicked();

    void on_tb_pause_clicked();

    void on_tb_stop_clicked();

    void on_tb_mon_brightness_up_clicked();

    void on_tb_brightness_down_clicked();

    void on_tb_prev_clicked();

    void on_tb_next_clicked();

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *proc;
};

#endif // MAINWINDOW_H
