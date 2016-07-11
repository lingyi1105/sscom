#include "widget.h"
#include "ui_widget.h"
#include <QPrintDialog>
#include <QTableWidget>
#include <QPainter>
#include <QPrintPreviewDialog>
#include <QMessageBox>
#include <QDialog>
#include <QtDebug>
#include <QTextDocument>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myprinter = new myPrinter(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QPrinter printer(QPrinter::HighResolution);

    QPrintPreviewDialog preview(&printer,0);    /* 打印预览 */

    /**
     * QPrintPreviewDialog类提供了一个打印预览对话框，里面功能比较全，
     * paintRequested(QPrinter *printer)是系统提供的，
     * 当preview.exec()执行时该信号被触发，
     * plotPic(QPrinter *printer)是用户自定义的槽函数，图像的绘制就在这个函数里。
     */
    connect(&preview, SIGNAL(paintRequested(QPrinter *)),this,SLOT(plotPic(QPrinter *)));

    preview.exec(); /* 等待预览界面退出 */

}

void Widget::plotPic(QPrinter *printer)
{
    QDialog *myForm = myprinter;

    QPainter painter(printer);
    QPixmap image;

    image=image.grabWidget(myForm,0,0,400,300); /* 绘制窗口至画布 */
    QRect rect = painter.viewport();
    QSize size = image.size();
    size.scale(rect.size(), Qt::KeepAspectRatio);     //此处保证图片显示完整
    painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
    painter.setWindow(image.rect());

    painter.drawPixmap(0,0,image); /* 数据显示至预览界面 */
}
