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
    GUI/IMPLEMENTATION/kalkmainwindow.cpp \
    MODEL/IMPLEMENTATION/ris.cpp \
    GUI/IMPLEMENTATION/extrapanel.cpp \
    MODEL/IMPLEMENTATION/kalk.cpp\
    MODEL/IMPLEMENTATION/advanced.cpp\
    MODEL/IMPLEMENTATION/UniverseAdvanced.cpp\
    GUI/IMPLEMENTATION/qcustomplot.cpp\
    MODEL/IMPLEMENTATION/numbers.cpp \
    MODEL/IMPLEMENTATION/heapsort.cpp

HEADERS += \
    MODEL/HEADER/advanced.h\
    MODEL/HEADER/Dataset.h \
    MODEL/HEADER/Set.h \
    MODEL/HEADER/UniverseDataset.h \
    MODEL/HEADER/UniverseSet.h \
    GUI/HEADER/kalkmainwindow.h \
    MODEL/HEADER/numbers.h \
    GUI/HEADER/extrapanel.h \
    MODEL/HEADER/kalk.h \
    MODEL/HEADER/UniverseAdvanced.h\
    GUI/HEADER/qcustomplot.h\