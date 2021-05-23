QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GL.cpp \
    MainWindow.cpp \
    add.cpp \
    del.cpp \
    drawner.cpp \
    komi.cpp \
    main.cpp \
    route.cpp

HEADERS += \
    GL.h \
    MainWindow.h \
    add.h \
    del.h \
    drawner.h \
    komi.h \
    route.h

FORMS += \
    MainWindow.ui \
    add.ui \
    del.ui \
    route.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Matrix.txt \
    MatrixSize.txt \
    run.bat

RESOURCES += \
    del.qrc \
    fon.qrc \
    marioo.qrc
