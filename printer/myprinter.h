#ifndef MYPRINTER_H
#define MYPRINTER_H

#include <QDialog>

namespace Ui {
class myPrinter;
}

class myPrinter : public QDialog
{
    Q_OBJECT
    
public:
    explicit myPrinter(QWidget *parent = 0);
    ~myPrinter();
    
private:
    Ui::myPrinter *ui;
};

#endif // MYPRINTER_H
