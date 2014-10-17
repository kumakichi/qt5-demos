#ifndef SANSDIALOG_H
#define SANSDIALOG_H

#include <QDialog>

namespace Ui {
class sansDialog;
}

class sansDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sansDialog(QWidget *parent = 0);
    ~sansDialog();

private slots:
    void on_psex_clicked();

    void on_page_clicked();

private:
    Ui::sansDialog *ui;
};

#endif // SANSDIALOG_H
