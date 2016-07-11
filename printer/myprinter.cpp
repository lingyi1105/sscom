#include "myprinter.h"
#include "ui_myprinter.h"

myPrinter::myPrinter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myPrinter)
{
    ui->setupUi(this);
}

myPrinter::~myPrinter()
{
    delete ui;
}
