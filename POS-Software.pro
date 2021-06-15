QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# INCLUDEPATH += "C:/Program Files/PostgreSQL/13/include"
# LIBS += "C:/Program Files/PostgreSQL/13/lib/libpq.dll"


SOURCES += \
    authentication.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    authentication.h \
    loginform.h \
    mainwindow.h

FORMS += \
    loginform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
