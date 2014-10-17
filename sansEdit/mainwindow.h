#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFontComboBox>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadFile(QString filename);

private slots:
    void on_action_open_triggered();
    void on_action_exit_triggered();
    void on_action_new_triggered();
    void on_action_print_text_triggered();
    void on_action_print_img_triggered();
    void on_action_about_triggered();
    void on_action_scroll_up_triggered();
    void on_action_scroll_down_triggered();
    void on_action_bold_triggered();
    void on_action_Italic_triggered();
    void on_action_Underline_triggered();
    void on_action_Fc_triggered();
    void on_action_left_align_triggered();
    void on_action_right_align_triggered();
    void on_action_center_align_triggered();
    void on_action_two_side_triggered();
    void RotatePixmap(int angle);
    void on_action_rotate_90_triggered();
    void on_action_rotate_180_triggered();
    void on_action_rotate_270_triggered();

    void ShowSort(int index);
    void TextSetFont(QString comboStr);
    void TextSetSize(QString sizeStr);

private:
    Ui::MainWindow *ui;

    QLabel *fontNameLbl;
    QFontComboBox *fontComboBox;
    QLabel *fontSizeLbl;
    QComboBox *sizeComboBox;

    QLabel *sortLbl;
    QComboBox *sortComboBox;
};

#endif // MAINWINDOW_H
