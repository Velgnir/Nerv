QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/ScrollCustomMenu.cpp \
    src/buttoncustommenu.cpp \
    src/filecontroller.cpp \
    src/fileinlist.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    includes/Blockfile.h \
    includes/CharacterFile.h \
    includes/DirectoryFile.h \
    includes/FifoFile.h \
    includes/OtherFiles.h \
    includes/RegularFile.h \
    includes/ScrollCustomMenu.h \
    includes/SocketFile.h \
    includes/Symlink.h \
    includes/buttoncustommenu.h \
    includes/file.h \
    includes/filecontroller.h \
    includes/fileinlist.h \
    includes/mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
