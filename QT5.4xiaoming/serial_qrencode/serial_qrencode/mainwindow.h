#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QSerialPort>
#include <QPrinter>

class BarCode;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    BarCode *barcode;
private slots:
    void check_serial_port();
    void serialport_recv();

    void on_open_port_Button_clicked();

    void on_print_button_clicked();
    void plotPic(QPrinter *printer);

private:
    Ui::MainWindow *ui;

    void InitStyle();   //初始化无边框窗体
    void InitForm();    //初始化窗体数据
    void port_param_init();
    void open_serialport();
    void close_serialport();
    void QRcode_Encode(QByteArray &text);
    void QBarcode_ts102(QByteArray &text);//条形码显示
    void QPcode(QPrinter *printer,QPainter *painter,QByteArray &text);

    QRect location;     //鼠标移动窗体后的坐标位置
    QColor foreground;
    QColor background;
    QByteArray rencode_text;
    quint8 state=0;
    QByteArray recv_arr;
    void log_output(QString info);
    void FrameParse(char c);
    QSerialPort *serialport;
    #define TWODIMENSION_SIZE 30 //定义二维码图像大小

};

#endif // MAINWINDOW_H
