QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/

SOURCES += \
    src/buydialog.cpp \
    src/goodsmodel.cpp \
    src/listusersitem.cpp \
    src/client.cpp \
    src/administrator.cpp \
    src/authentication.cpp \
    src/listgoodsitem.cpp \
    src/loginform.cpp \
    src/main.cpp \
    src/query_command.cpp \

HEADERS += \
    include/authentication.h \
    include/client.h \
    include/goodsmodel.h \
    include/listusersitem.h \
    include/loginform.h \
    include/administrator.h \
    include/listgoodsitem.h \
    include/buydialog.h \
    include/query_command.h \

FORMS += \
    forms/loginform.ui \
    forms/administrator.ui \
    forms/client.ui \
    forms/buydialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    .gitignore \
    databases/goods.db \
    databases/histories.db \
    databases/users.db \
    sql/goods.sql \
    sql/history.sql \
    sql/sample_goods.sql \
    sql/sample_users.sql \
    sql/users.sql

