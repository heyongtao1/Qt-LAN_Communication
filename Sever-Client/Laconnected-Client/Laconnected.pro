#-------------------------------------------------
#
# Project created by QtCreator 2020-12-18T16:24:21
#
#-------------------------------------------------

QT       += core gui sql network multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Laconnected
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big
SOURCES += \
        main.cpp \
    mythread.cpp \
    mycpp.cpp

HEADERS += \
    sendfile.h \
    mythread.h \
    myinfo.h \
    mycpp.h


FORMS += \

# Default rules for deployment.

include($$PWD/login/login.pri)
include($$PWD/comm_widgets/comm_widgets.pri)
include($$PWD/mediamar/mediamar.pri)
include($$PWD/tcp_udp_socket/tcp_udp_socket.pri)

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
