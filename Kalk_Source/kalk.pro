TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
QT += core gui
QT +=printsupport
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets
TARGET = kalk

SOURCES += GUI/IMPLEMENTATION/main.cpp \
    MODEL/IMPLEMENTATION/Dataset.cpp \
    MODEL/IMPLEMENTATION/Set.cpp \
    MODEL/IMPLEMENTATION/UniverseDataset.cpp \
    MODEL/IMPLEMENTATION/UniverseSet.cpp \
    MODEL/IMPLEMENTATION/ris.cpp \
    GUI/IMPLEMENTATION/extrapanel.cpp \
    MODEL/IMPLEMENTATION/kalk.cpp\
    MODEL/IMPLEMENTATION/advanced.cpp\
    MODEL/IMPLEMENTATION/UniverseAdvanced.cpp\
    GUI/IMPLEMENTATION/qcustomplot.cpp\
    MODEL/IMPLEMENTATION/numbers.cpp \
    GUI/IMPLEMENTATION/setview.cpp \
    MODEL/IMPLEMENTATION/logic.cpp\
    MODEL/IMPLEMENTATION/SetLogic.cpp




HEADERS += \
    MODEL/HEADER/advanced.h\
    MODEL/HEADER/Dataset.h \
    MODEL/HEADER/Set.h \
    MODEL/HEADER/UniverseDataset.h \
    MODEL/HEADER/UniverseSet.h \
    GUI/HEADER/kalkmainwindow.h \
    MODEL/HEADER/numbers.h \
    GUI/HEADER/extrapanel.h \
    MODEL/HEADER/UniverseAdvanced.h\
    GUI/HEADER/qcustomplot.h\
    GUI/HEADER/setview.h\
    MODEL/HEADER/logic.h\
    MODEL/HEADER/SetLogic.h\
    MODEL/HEADER/abstractlogic.h
