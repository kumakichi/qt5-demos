#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTextCodec>
#include <QScrollBar>

namespace Ui {
class QProcess;

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void cmd_show();

private:
    Ui::MainWindow *ui;
    QProcess *q;
    QString str;
    QTextCodec *pCodec;
};

#endif // MAINWINDOW_H
