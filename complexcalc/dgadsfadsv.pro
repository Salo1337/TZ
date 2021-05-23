QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alg1.cpp \
    exp1.cpp \
    main.cpp \
    mainwindow.cpp \
    trig.cpp

HEADERS += \
    alg1.h \
    exp1.h \
    mainwindow.h \
    trig.h

FORMS += \
    alg1.ui \
    exp1.ui \
    mainwindow.ui \
    trig.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    blue1.qrc \
    clock1.qrc \
    fon.qrc \
    icon.qrc \
    icon1.qrc \
    icon2.qrc \
    orange.qrc \
    pixel.qrc \
    red.qrc
