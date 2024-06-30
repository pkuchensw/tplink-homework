QT       += core gui
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    creature.cpp \
    data_cache.cpp \
    data_loader.cpp \
    decision.cpp \
    fun.cpp \
    gifthread.cpp \
    group.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    mymove.cpp \
    network.cpp \
    read.cpp \
    resourceloader.cpp \
    setting.cpp

HEADERS += \
    add.h \
    creature.h \
    gifthread.h \
    group.h \
    home.h \
    mainwindow.h \
    mymove.h \
    network.h \
    read.h \
    resourceloader.h \
    setting.h

FORMS += \
    add.ui \
    group.ui \
    home.ui \
    mainwindow.ui \
    read.ui \
    setting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    image/ocean_p3.webp \
    image/rabbit.gif \
    resource

RESOURCES += \
    image.qrc

