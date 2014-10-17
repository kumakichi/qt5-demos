#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QMatrix>
#include <QColorDialog>
#include <QTextList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sans_img->setPixmap(QPixmap(":/images/image.png"));

    fontNameLbl = new QLabel(tr("字体:"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontSizeLbl = new QLabel(tr("字号:"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach (int size, db.standardSizes()) {
        sizeComboBox->addItem(QString::number(size));
    }

    QAction *atmp;
    //全部反向添+
    atmp = ui->toolBar_font->insertSeparator(ui->action_bold);
    atmp = ui->toolBar_font->insertWidget(atmp,sizeComboBox);
    atmp = ui->toolBar_font->insertWidget(atmp,fontSizeLbl);
    atmp = ui->toolBar_font->insertWidget(atmp,fontComboBox);
    atmp = ui->toolBar_font->insertWidget(atmp,fontNameLbl);
    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(TextSetFont(QString)));
    connect(sizeComboBox,SIGNAL(activated(QString)),this,SLOT(TextSetSize(QString)));

    sortLbl = new QLabel(tr("排序:"));
    sortComboBox = new QComboBox;
    sortComboBox->addItem("Standard");
    sortComboBox->addItem("QTextListFormat::ListDisc");
    sortComboBox->addItem("QTextListFormat::ListCircle");
    sortComboBox->addItem("QTextListFormat::ListSquare");
    sortComboBox->addItem("QTextListFormat::ListDecimal");
    sortComboBox->addItem("QTextListFormat::ListLowerAlpha");
    sortComboBox->addItem("QTextListFormat::ListUpperAlpha");
    sortComboBox->addItem("QTextListFormat::ListLowerRoman");
    sortComboBox->addItem("QTextListFormat::ListUpperRoman");

    atmp = ui->toolBar_sort->insertSeparator(ui->action_left_align);
    atmp = ui->toolBar_sort->insertWidget(atmp,sortComboBox);
    ui->toolBar_sort->insertWidget(atmp,sortLbl);
    connect(sortComboBox,SIGNAL(activated(int)),this,SLOT(ShowSort(int)));
}

void MainWindow::TextSetSize(QString sizeStr)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(sizeStr.toFloat());
    ui->sans_text->mergeCurrentCharFormat(fmt);
}

void MainWindow::TextSetFont(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);

    QTextCursor cursor = ui->sans_text->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
    ui->sans_text->mergeCurrentCharFormat(fmt);
}

void MainWindow::ShowSort(int index)
{
    QTextCursor cursor=ui->sans_text->textCursor();

    if(index!=0)
    {
        QTextListFormat::Style style=QTextListFormat::ListDisc;
        switch(index)                           //设置style属性值
        {
        default:
        case 1:
            style=QTextListFormat::ListDisc; break;
        case 2:
            style=QTextListFormat::ListCircle; break;
        case 3:
            style=QTextListFormat::ListSquare; break;
        case 4:
            style=QTextListFormat::ListDecimal; break;
        case 5:
            style=QTextListFormat::ListLowerAlpha; break;
        case 6:
            style=QTextListFormat::ListUpperAlpha; break;
        case 7:
            style=QTextListFormat::ListLowerRoman; break;
        case 8:
            style=QTextListFormat::ListUpperRoman; break;
        }
        cursor.beginEditBlock();                //设置缩进值

        QTextBlockFormat blockFmt=cursor.blockFormat();
        QTextListFormat listFmt;

        if(cursor.currentList())
        {
            listFmt= cursor.currentList()->format();
        }
        else
        {
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    } else {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFile(QString path)
{
    QFile fp(path);
    if(fp.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream textStream(&fp);
        while(!textStream.atEnd())
        {
            ui->sans_text->append(textStream.readAll());
        }
    }
}

void MainWindow::on_action_open_triggered()
{
    QString fileName =QFileDialog::getOpenFileName(this,"打开");
    if(!fileName.isEmpty())
    {
        if(ui->sans_text->document()->isEmpty())
        {
            loadFile(fileName);
        }
    }
}

void MainWindow::on_action_exit_triggered()
{
    close();
}

void MainWindow::on_action_new_triggered()
{
    MainWindow *main = new MainWindow;
    main->show();
}

void MainWindow::on_action_print_text_triggered()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QTextDocument *doc =ui->sans_text->document();
        doc->print(&printer);
    }
}

void MainWindow::on_action_print_img_triggered()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect =painter.viewport();
        QImage img = ui->sans_img->pixmap()->toImage();
        QSize size = img.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);

        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);
    }
}

void MainWindow::on_action_about_triggered()
{
    ::QApplication::aboutQt();
}

void MainWindow::on_action_scroll_up_triggered()
{
    QImage img = ui->sans_img->pixmap()->toImage();
    QMatrix martix;
    martix.scale(2,2);
    img = img.transformed(martix);
    ui->sans_img->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_action_scroll_down_triggered()
{
    QImage img = ui->sans_img->pixmap()->toImage();
    QMatrix martix;
    martix.scale(0.5,0.5);
    img = img.transformed(martix);
    ui->sans_img->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_action_bold_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->action_bold->isChecked()?QFont::Bold:QFont::Normal);
    ui->sans_text->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_action_Italic_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->action_Italic->isChecked());
    ui->sans_text->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_action_Underline_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->action_Underline->isChecked());
    ui->sans_text->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_action_Fc_triggered()
{
    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        ui->sans_text->mergeCurrentCharFormat(fmt);
    }
}

void MainWindow::on_action_left_align_triggered()
{
    ui->sans_text->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_action_right_align_triggered()
{
    ui->sans_text->setAlignment(Qt::AlignRight);
}

void MainWindow::on_action_center_align_triggered()
{
    ui->sans_text->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_action_two_side_triggered()
{
    ui->sans_text->setAlignment(Qt::AlignJustify);
}

void MainWindow::on_action_rotate_90_triggered()
{
    RotatePixmap(90);
}

void MainWindow::on_action_rotate_180_triggered()
{
    RotatePixmap(180);
}

void MainWindow::on_action_rotate_270_triggered()
{
    RotatePixmap(270);
}

void MainWindow::RotatePixmap(int angle)
{
    QMatrix matrix;
    QImage img = ui->sans_img->pixmap()->toImage();

    matrix.rotate(angle);
    img = img.transformed(matrix);

    ui->sans_img->setPixmap(QPixmap::fromImage(img));
}
