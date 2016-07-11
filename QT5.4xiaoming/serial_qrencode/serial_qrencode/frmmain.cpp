#include "frmmain.h"
#include "ui_frmmain.h"
#include "api/myhelper.h"
#include <QPainter>
#include <QByteArray>
#include "qrencode/qrencode.h"
#include <QSerialPortInfo>

frmMain::frmMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->InitStyle();
    this->InitForm();
    port_param_init();
    myHelper::FormInCenter(this);
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::InitStyle()
{
    this->max = false;
    this->location = this->geometry();
    this->setProperty("Form", true);
    this->setProperty("CanMove", true);
    this->setWindowTitle(ui->lab_Title->text());
    //设置窗体标题栏隐藏
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //安装事件监听器,让标题栏识别鼠标双击
    //ui->lab_Title->installEventFilter(this);

//    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d));
//    IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf096));
//    IconHelper::Instance()->SetIcon(ui->btnMenu_Min, QChar(0xf068));
//    IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015));

//    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
//    connect(ui->btnMenu_Min, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void frmMain::InitForm()
{
   //QString qssFile = ":/qss/dev.css";
   // myHelper::Sleep(300);
   //myHelper::SetStyle(qssFile);
   this->rencode_text = "hello world!";
   QRcode_Encode(this->rencode_text);
}

void frmMain::on_btnMenu_Max_clicked()
{
//    if (max) {
//        this->setGeometry(location);
//        IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf096));
//        ui->btnMenu_Max->setToolTip("最大化");
//        this->setProperty("CanMove", true);
//    } else {
//        location = this->geometry();
//        this->setGeometry(qApp->desktop()->availableGeometry());
//        IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf079));
//        ui->btnMenu_Max->setToolTip("还原");
//        this->setProperty("CanMove", false);
//    }
//    max = !max;
}

void frmMain::QRcode_Encode(QByteArray &text)
{
    int margin = 10;
    ui->rencode_lineEdit->setText(text);
    this->foreground = QColor("black");
    this->background = QColor("white");
    QRcode *qrcode = QRcode_encodeString(text.data(), 7, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if(NULL != qrcode) {
        QPixmap pixmap(400,400);//ui->rencode_view->width(), ui->rencode_view->height());
        QPainter painter;
        painter.begin(&pixmap);
        unsigned char *point = qrcode->data;
        painter.setPen(Qt::NoPen);
        painter.setBrush(this->background);
        painter.drawRect(0, 0, 400, 400);
        double scale = (400 - 2.0 * margin) / qrcode->width;
        painter.setBrush(this->foreground);
        for (int y = 0; y < qrcode->width; y ++) {
            for (int x = 0; x < qrcode->width; x ++) {
                if (*point & 1) {
                    QRectF r(margin + x * scale, margin + y * scale, scale, scale);
                    painter.drawRects(&r, 1);
                }
                point ++;
            }
        }
        ui->rencode_view->setPixmap(pixmap);
        painter.end();
        point = NULL;
        QRcode_free(qrcode);
//         draw icon
//         if (icon.isNull ()) {
//            painter.setBrush(this->background);
//            double icon_width = (this->width () - 2.0 * margin) * percent;
//            double icon_height = icon_width;
//            double wrap_x = (this->width () - icon_width) / 2.0;
//            double wrap_y = (this->width () - icon_height) / 2.0;
//            QRectF wrap(wrap_x - 5, wrap_y - 5, icon_width + 10, icon_height + 10);
//            painter.drawRoundRect(wrap, 50, 50);
//            QPixmap image(":/logo.png");
//            QRectF target(wrap_x, wrap_y, icon_width, icon_height);
//            QRectF source(0, 0, image.width (), image.height ());
//            painter.drawPixmap (target, image, source);
    }
}
void frmMain::port_param_init()
{
    //init com buadrate
    ui->buadrate_comboBox->addItem(QLatin1String("300"));
    ui->buadrate_comboBox->addItem(QLatin1String("600"));
    ui->buadrate_comboBox->addItem(QLatin1String("1200"));
    ui->buadrate_comboBox->addItem(QLatin1String("2400"));
    ui->buadrate_comboBox->addItem(QLatin1String("4800"));
    ui->buadrate_comboBox->addItem(QLatin1String("9600"));
    ui->buadrate_comboBox->addItem(QLatin1String("19200"));
    ui->buadrate_comboBox->addItem(QLatin1String("38400"));
    ui->buadrate_comboBox->addItem(QLatin1String("115200"));
    ui->buadrate_comboBox->setCurrentIndex(5);

    // fill data bits
    ui->databits_comboBox->addItem(QLatin1String("5"), QSerialPort::Data5);
    ui->databits_comboBox->addItem(QLatin1String("6"), QSerialPort::Data6);
    ui->databits_comboBox->addItem(QLatin1String("7"), QSerialPort::Data7);
    ui->databits_comboBox->addItem(QLatin1String("8"), QSerialPort::Data8);
    ui->databits_comboBox->setCurrentIndex(3);

     // fill parity
    ui->parity_comboBox->addItem(QLatin1String("None"), QSerialPort::NoParity);
    ui->parity_comboBox->addItem(QLatin1String("Even"), QSerialPort::EvenParity);
    ui->parity_comboBox->addItem(QLatin1String("Odd"), QSerialPort::OddParity);
    ui->parity_comboBox->addItem(QLatin1String("Mark"), QSerialPort::MarkParity);
    ui->parity_comboBox->addItem(QLatin1String("Space"), QSerialPort::SpaceParity);

    // fill stop bits
    ui->stopbits_comboBox->addItem(QLatin1String("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopbits_comboBox->addItem(QLatin1String("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopbits_comboBox->addItem(QLatin1String("2"), QSerialPort::TwoStop);

   check_serial_port();


  this->serialport = new QSerialPort(this);
  QObject::connect(this->serialport,SIGNAL(readyRead()),this,SLOT(serialport_recv()));


  QObject::connect(ui->check_port_Button,SIGNAL(clicked()),this,SLOT(check_serial_port()));
}
void frmMain::check_serial_port()
{
    ui->port_comboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        list << info.portName()
             << info.description()
             << info.manufacturer()
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString())
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : QString());

        ui->port_comboBox->addItem(list.first(), list);
    }
}
void frmMain::FrameParse(char c)
{
    switch (state) {
    case 0:
        if(c=='#')
         {
           this->recv_arr.clear();
           state++;
         }

        break;
    case 1:
        if(c=='#')
        {
            this->rencode_text.clear();
            this->rencode_text = this->recv_arr;
            if(rencode_text.isEmpty()==false)
            {
            QRcode_Encode(this->rencode_text);
            log_output(tr("解析成功"));
            }
            state = 0;
        }else
        {
           this->recv_arr.append(c);
        }

        break;
    default:
        state = 0;
        break;
    }

}
void frmMain::serialport_recv()
{
    QByteArray temp = this->serialport->readAll();
    if(temp.size() > 0)
    {
        for(int i = 0;i< temp.size();i++)
        {
            FrameParse(temp.at(i));
        }
    }
   // this->rx_array.insert(this->rx_array.size(),temp);
   // this->rx_count += temp.size();
    //ui->rx_count_label->setText(tr("%1").arg(this->rx_count));

}

void frmMain::open_serialport()
{

        QString portName = ui->port_comboBox->currentText();
        qint32 baudRate = ui->buadrate_comboBox->currentText().toInt();
        QSerialPort::DataBits dataBits = static_cast<QSerialPort::DataBits>(ui->databits_comboBox->itemData(ui->databits_comboBox->currentIndex()).toInt());
        QSerialPort::StopBits stopBits = static_cast<QSerialPort::StopBits>(ui->stopbits_comboBox->itemData(ui->stopbits_comboBox->currentIndex()).toInt());
        QSerialPort::Parity parity = static_cast<QSerialPort::Parity>(ui->parity_comboBox->itemData(ui->parity_comboBox->currentIndex()).toInt());
        this->serialport->setPortName(portName);
        this->serialport->setBaudRate(baudRate);
        this->serialport->setDataBits(dataBits);
        this->serialport->setStopBits(stopBits);
        this->serialport->setParity(parity);
        this->serialport->open(QIODevice::ReadWrite);
        ui->port_comboBox->setEnabled(false);
        ui->parity_comboBox->setEnabled(false);
        ui->stopbits_comboBox->setEnabled(false);
        ui->databits_comboBox->setEnabled(false);
        ui->buadrate_comboBox->setEnabled(false);


}
void frmMain::close_serialport()
{
        this->serialport->close();
        ui->port_comboBox->setEnabled(true);
        ui->parity_comboBox->setEnabled(true);
        ui->stopbits_comboBox->setEnabled(true);
        ui->databits_comboBox->setEnabled(true);
        ui->buadrate_comboBox->setEnabled(true);
}
void frmMain::on_open_port_Button_clicked()
{
    if(ui->open_port_Button->text()=="打开")
     {
        open_serialport();
        ui->open_port_Button->setText(tr("关闭"));
     }else
     {
        close_serialport();
        ui->open_port_Button->setText(tr("打开"));
    }
}
void frmMain::log_output(QString info)
{
    QString time= QDateTime::currentDateTime ().toString ("yyyy-MM-dd hh:mm:ss");
    ui->plainTextEdit->appendPlainText(tr("[%1] %2").arg (time).arg (info));
}
void frmMain::on_cboxStyle_currentIndexChanged(const QString &arg1)
{
//    QString qssName = ui->cboxStyle->currentText();
//    QString qssFile = ":/qss/lightgray.css";
//    if (qssName == "黑色") {
//        qssFile = ":/qss/black.css";
//    } else if (qssName == "灰黑色") {
//        qssFile = ":/qss/brown.css";
//    } else if (qssName == "灰色") {
//        qssFile = ":/qss/gray.css";
//    } else if (qssName == "浅灰色") {
//        qssFile = ":/qss/lightgray.css";
//    } else if (qssName == "深灰色") {
//        qssFile = ":/qss/darkgray.css";
//    } else if (qssName == "银色") {
//        qssFile = ":/qss/silvery.css";
//    } else if (qssName == "淡蓝色") {
//        qssFile = ":/qss/blue.css";
//    } else if (qssName == "蓝色") {
//        qssFile = ":/qss/dev.css";
//    }

//    myHelper::SetStyle(qssFile);
}


