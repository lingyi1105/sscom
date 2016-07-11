#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T14:34:50
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
qtHaveModule(printsupport): QT += printsupport
TARGET = Serial_qrencode
TEMPLATE = app

SOURCES += main.cpp\
        frmmain.cpp \
    api/iconhelper.cpp \
    api/app.cpp \
    api/appinit.cpp \
    usercontrol/frmmessagebox.cpp \
    usercontrol/frminputbox.cpp\
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrencode.c \
    qrencode/qrinput.c \
    qrencode/qrspec.c \
    qrencode/rscode.c \
    qrencode/split.c
	
HEADERS  += frmmain.h \
    api/iconhelper.h \
    api/myhelper.h \
    api/app.h \
    api/appinit.h \
    usercontrol/frmmessagebox.h \    
    usercontrol/frminputbox.h\
    qrencode/bitstream.h \
    qrencode/config.h \
    qrencode/mask.h \
    qrencode/mmask.h \
    qrencode/mqrspec.h \
    qrencode/qrencode_inner.h \
    qrencode/qrencode.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rscode.h \
    qrencode/split.h
	
FORMS    += frmmain.ui \
    usercontrol/frmmessagebox.ui \
    usercontrol/frminputbox.ui

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/usercontrol

MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin

win32:RC_FILE   = other/main.rc

RESOURCES += \
    other/rc.qrc
