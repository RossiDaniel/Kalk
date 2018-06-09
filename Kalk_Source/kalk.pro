TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
QT += core gui
QT +=printsupport
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets
TARGET = kalk

SOURCES += \
    GUI/IMPLEMENTATION/main.cpp \
    MODEL/IMPLEMENTATION/Dataset.cpp \
    MODEL/IMPLEMENTATION/Set.cpp \
    MODEL/IMPLEMENTATION/UniverseDataset.cpp \
    MODEL/IMPLEMENTATION/UniverseSet.cpp \
    MODEL/IMPLEMENTATION/ris.cpp \
    GUI/IMPLEMENTATION/extrapanel.cpp \
    MODEL/IMPLEMENTATION/app.cpp\
    MODEL/IMPLEMENTATION/advanced.cpp\
    MODEL/IMPLEMENTATION/UniverseAdvanced.cpp\
    GUI/IMPLEMENTATION/qcustomplot.cpp\
    MODEL/IMPLEMENTATION/numbers.cpp \
    GUI/IMPLEMENTATION/setview.cpp \
    GUI/IMPLEMENTATION/datasetview.cpp \
    GUI/IMPLEMENTATION/advancedview.cpp \
    MODEL/IMPLEMENTATION/SetLogic.cpp \
    MODEL/IMPLEMENTATION/DatasetLogic.cpp\
    MODEL/IMPLEMENTATION/AdvancedLogic.cpp \
    GUI/IMPLEMENTATION/kalkmainwindow.cpp \
    MODEL/IMPLEMENTATION/abstractlogic.cpp \
    GUI/IMPLEMENTATION/View.cpp





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
    MODEL/HEADER/app.h\
    MODEL/HEADER/SetLogic.h\
    MODEL/HEADER/abstractlogic.h \
    GUI/HEADER/datasetview.h \
    GUI/HEADER/advancedview.h \
    MODEL/HEADER/DatasetLogic.h \
    MODEL/HEADER/AdvancedLogic.h \
    GUI/HEADER/View.h

