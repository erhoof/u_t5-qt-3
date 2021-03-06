QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DoneReqListModel.cpp \
    HardDrive.cpp \
    HardDriveTableModel.cpp \
    InitialSetup.cpp \
    MainWindow.cpp \
    NewRequestsModel.cpp \
    SortedReqListModel.cpp \
    main.cpp

HEADERS += \
    DoneReqListModel.h \
    HardDrive.h \
    HardDriveInfo.h \
    HardDriveTableModel.h \
    InitialSetup.h \
    MainWindow.h \
    NewRequestsModel.h \
    RequestModel.h \
    SortedReqListModel.h

FORMS += \
    InitialSetup.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
