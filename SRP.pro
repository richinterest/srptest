QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    clientwindow.cpp \
    main.cpp \
    server.cpp \
    server_screen.cpp \
    serverwindow.cpp

HEADERS += \
    client.h \
    clientwindow.h \
    server.h \
    serverwindow.h \
    ui_serverwindow.h \

  # 指定生成的文件目录
  # 设置 uic 生成的文件的目录


FORMS += \
    clientwindow.ui \
    screen.ui \
    serverwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
