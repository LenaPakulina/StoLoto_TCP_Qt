QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graphics/scene.cpp \
    main.cpp \
    mainwindow.cpp \
    utils/config.cpp \
    widgets/lotoform.cpp \
    widgets/startform.cpp \
    widgets/ticket.cpp

HEADERS += \
    graphics/scene.h \
    mainwindow.h \
    utils/config.h \
    utils/debugsettings.h \
    widgets/lotoform.h \
    widgets/startform.h \
    widgets/ticket.h

FORMS += \
    mainwindow.ui \
    widgets/lotoform.ui \
    widgets/startform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
