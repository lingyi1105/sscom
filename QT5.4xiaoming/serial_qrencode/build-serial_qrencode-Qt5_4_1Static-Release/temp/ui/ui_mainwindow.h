/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_5;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *rencode_view;
    QLabel *rencode_view_2;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QComboBox *port_comboBox;
    QComboBox *buadrate_comboBox;
    QComboBox *databits_comboBox;
    QComboBox *parity_comboBox;
    QComboBox *stopbits_comboBox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *open_port_Button;
    QPushButton *check_port_Button;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *rencode_lineEdit;
    QLineEdit *rencode_lineEdit_2;
    QPushButton *print_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(762, 499);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget_main = new QWidget(centralwidget);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setStyleSheet(QStringLiteral(""));
        verticalLayout_9 = new QVBoxLayout(widget_main);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        groupBox_3 = new QGroupBox(widget_main);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(230, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(true);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMinimumSize(QSize(50, 0));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 16, 5, 5);
        checkBox = new QCheckBox(groupBox_4);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        checkBox->setFont(font);
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 3, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(true);

        gridLayout->addWidget(plainTextEdit, 4, 1, 1, 2);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy3);
        groupBox_5->setMinimumSize(QSize(0, 97));
        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 191, 32));
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMaximumSize(QSize(16777215, 32));
        textEdit_2 = new QTextEdit(groupBox_5);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 60, 61, 31));
        textEdit_3 = new QTextEdit(groupBox_5);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(90, 60, 111, 31));

        gridLayout->addWidget(groupBox_5, 0, 1, 2, 1);


        verticalLayout_4->addWidget(groupBox_4);


        horizontalLayout_5->addWidget(widget);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rencode_view = new QLabel(groupBox);
        rencode_view->setObjectName(QStringLiteral("rencode_view"));
        rencode_view->setEnabled(true);
        sizePolicy1.setHeightForWidth(rencode_view->sizePolicy().hasHeightForWidth());
        rencode_view->setSizePolicy(sizePolicy1);
        rencode_view->setScaledContents(false);
        rencode_view->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rencode_view);

        rencode_view_2 = new QLabel(groupBox);
        rencode_view_2->setObjectName(QStringLiteral("rencode_view_2"));
        sizePolicy1.setHeightForWidth(rencode_view_2->sizePolicy().hasHeightForWidth());
        rencode_view_2->setSizePolicy(sizePolicy1);
        rencode_view_2->setTextFormat(Qt::RichText);
        rencode_view_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rencode_view_2);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(50, 219));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 20, 131, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        port_comboBox = new QComboBox(layoutWidget);
        port_comboBox->setObjectName(QStringLiteral("port_comboBox"));
        sizePolicy2.setHeightForWidth(port_comboBox->sizePolicy().hasHeightForWidth());
        port_comboBox->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(port_comboBox);

        buadrate_comboBox = new QComboBox(layoutWidget);
        buadrate_comboBox->setObjectName(QStringLiteral("buadrate_comboBox"));
        sizePolicy2.setHeightForWidth(buadrate_comboBox->sizePolicy().hasHeightForWidth());
        buadrate_comboBox->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(buadrate_comboBox);

        databits_comboBox = new QComboBox(layoutWidget);
        databits_comboBox->setObjectName(QStringLiteral("databits_comboBox"));
        sizePolicy2.setHeightForWidth(databits_comboBox->sizePolicy().hasHeightForWidth());
        databits_comboBox->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(databits_comboBox);

        parity_comboBox = new QComboBox(layoutWidget);
        parity_comboBox->setObjectName(QStringLiteral("parity_comboBox"));
        sizePolicy2.setHeightForWidth(parity_comboBox->sizePolicy().hasHeightForWidth());
        parity_comboBox->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(parity_comboBox);

        stopbits_comboBox = new QComboBox(layoutWidget);
        stopbits_comboBox->setObjectName(QStringLiteral("stopbits_comboBox"));
        sizePolicy2.setHeightForWidth(stopbits_comboBox->sizePolicy().hasHeightForWidth());
        stopbits_comboBox->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(stopbits_comboBox);

        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 50, 141));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_5);

        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 160, 181, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        open_port_Button = new QPushButton(layoutWidget_3);
        open_port_Button->setObjectName(QStringLiteral("open_port_Button"));
        sizePolicy2.setHeightForWidth(open_port_Button->sizePolicy().hasHeightForWidth());
        open_port_Button->setSizePolicy(sizePolicy2);
        open_port_Button->setMinimumSize(QSize(50, 32));

        horizontalLayout_4->addWidget(open_port_Button);

        check_port_Button = new QPushButton(layoutWidget_3);
        check_port_Button->setObjectName(QStringLiteral("check_port_Button"));
        check_port_Button->setEnabled(true);
        sizePolicy2.setHeightForWidth(check_port_Button->sizePolicy().hasHeightForWidth());
        check_port_Button->setSizePolicy(sizePolicy2);
        check_port_Button->setMinimumSize(QSize(80, 32));
        check_port_Button->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(check_port_Button);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rencode_lineEdit = new QLineEdit(groupBox);
        rencode_lineEdit->setObjectName(QStringLiteral("rencode_lineEdit"));
        rencode_lineEdit->setEnabled(false);

        horizontalLayout_2->addWidget(rencode_lineEdit);

        rencode_lineEdit_2 = new QLineEdit(groupBox);
        rencode_lineEdit_2->setObjectName(QStringLiteral("rencode_lineEdit_2"));
        rencode_lineEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(rencode_lineEdit_2->sizePolicy().hasHeightForWidth());
        rencode_lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(rencode_lineEdit_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        print_button = new QPushButton(groupBox);
        print_button->setObjectName(QStringLiteral("print_button"));
        print_button->setMinimumSize(QSize(0, 40));

        verticalLayout_5->addWidget(print_button);


        horizontalLayout_5->addWidget(groupBox);


        verticalLayout_9->addWidget(groupBox_3);


        gridLayout_2->addWidget(widget_main, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225\344\277\241\346\201\257", 0));
        checkBox->setText(QApplication::translate("MainWindow", "\345\220\214\346\227\266\346\211\223\345\215\260\344\270\244\345\274\240\344\272\214\347\273\264\347\240\201", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lucida Grande,\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; color:#333333; background-color:#ffffff;\">11300001</span></p></body></html>", 0));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">1</span></p></body></html>", 0));
        textEdit_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\272\214\347\273\264\347\240\201\346\230\276\347\244\272", 0));
        rencode_view->setText(QApplication::translate("MainWindow", "Image1", 0));
        rencode_view_2->setText(QApplication::translate("MainWindow", "Image2", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", 0));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", 0));
        open_port_Button->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        check_port_Button->setText(QApplication::translate("MainWindow", "\346\243\200\346\265\213", 0));
        print_button->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
