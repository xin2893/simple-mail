#-------------------------------------------------
#
# Project created by QtCreator 2013-06-26T22:53:19
#
#-------------------------------------------------

QT       += core gui
QT      +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = simple-mail
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    readmail.cpp \
    contact.cpp \
    sendmail.cpp

HEADERS  += mainwindow.h \
    readmail.h \
    contact.h \
    sendmail.h \
    ui_contact.h

FORMS    += mainwindow.ui \
    sendmail.ui \
    Contact.ui
