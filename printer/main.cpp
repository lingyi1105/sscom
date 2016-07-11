#include <QtGui/QApplication>
#include <QTextCodec>//ʹ�ܽ���QTextCodec���ñ��뷽ʽ��֧������

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
