#include <QtGui/QApplication>
#include <QTextCodec>//使能进行QTextCodec设置编码方式而支持中文

#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    Widget w;
    w.show();
    
    return a.exec();
}
