#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPrinter>
#include "myprinter.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void printImage();

private slots:
    void on_pushButton_clicked();
    void plotPic(QPrinter *);
private:
    Ui::Widget *ui;

    myPrinter * myprinter;
    QPrinter *printer;

//    QPrinter printer;
};

#endif // WIDGET_H
