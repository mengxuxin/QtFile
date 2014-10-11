#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T14:23:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFileServer
TEMPLATE = app
TARGET += ../QFileServer/Bin

SOURCES += main.cpp\
        Widget.cpp \
    MyTcpServer.cpp \
    FortuneThread.cpp

HEADERS  += Widget.h \
    MyTcpServer.h \
    FortuneThread.h
