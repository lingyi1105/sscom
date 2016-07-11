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

    QPrintPreviewDialog preview(&printer,0);    /* ��ӡԤ�� */

    /**
     * QPrintPreviewDialog���ṩ��һ����ӡԤ���Ի������湦�ܱȽ�ȫ��
     * paintRequested(QPrinter *printer)��ϵͳ�ṩ�ģ�
     * ��preview.exec()ִ��ʱ���źű�������
     * plotPic(QPrinter *printer)���û��Զ���Ĳۺ�����ͼ��Ļ��ƾ�����������
     */
    connect(&preview, SIGNAL(paintRequested(QPrinter *)),this,SLOT(plotPic(QPrinter *)));

    preview.exec(); /* �ȴ�Ԥ�������˳� */

}

void Widget::plotPic(QPrinter *printer)
{
    QDialog *myForm = myprinter;

    QPainter painter(printer);
    QPixmap image;

    image=image.grabWidget(myForm,0,0,400,300); /* ���ƴ��������� */
    QRect rect = painter.viewport();
    QSize size = image.size();
    size.scale(rect.size(), Qt::KeepAspectRatio);     //�˴���֤ͼƬ��ʾ����
    painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
    painter.setWindow(image.rect());

    painter.drawPixmap(0,0,image); /* ������ʾ��Ԥ������ */
}
