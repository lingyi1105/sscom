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

    void on_rencode_lineEdit_2_textChanged(const QString &arg1);

    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    void InitStyle();   //初始化无边框窗体
    void InitForm();    //初始化窗体数据
    void port_param_init();
    void open_serialport();
    void close_serialport();
    void QRcode_Encode(QByteArray &text);
    void QRcode_Encode_2(QByteArray &text);
    void QBarcode_ts102(QByteArray &text);//条形码显示
    void QPcode(QPrinter *printer,QPainter *painter,QByteArray &text);//单张二维码打印
    void QPcode_2(QPrinter *printer,QPainter *painter,QByteArray &text,QByteArray &text_2);//两张二维码打印

    QRect location;     //鼠标移动窗体后的坐标位置
    QColor foreground;
    QColor background;
    QByteArray rencode_text;//记录MAC地址
    QByteArray rencode_text_2;//记录第一个MAC地址
    quint8 state=0;
    QByteArray recv_arr;
    void log_output(QString info);
    void FrameParse(char c);
    QSerialPort *serialport;
    #define DPI 25.5 //毫米和像素的转换
    #define PARAMETER 2.8
    #define TWODIMENSION_SIZE 13*PARAMETER //定义打印二维码图像大小
    #define IMAGE_SIZE 200 //定义在上位机显示二维码大小
    #define MARGIN_VALUE 0
    #define LEFT_MARGIN 2.29*PARAMETER  //左边距2.29mm
    #define UP_MARGIN 1.89*PARAMETER
    #define TWODIMENSION_INTERVAL 3.58*PARAMETER
};

#endif // MAINWINDOW_H
