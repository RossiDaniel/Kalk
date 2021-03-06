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
    MODEL/IMPLEMENTATION/ris.cpp \
    GUI/IMPLEMENTATION/extrapanel.cpp \
    MODEL/IMPLEMENTATION/advanced.cpp\
    GUI/IMPLEMENTATION/qcustomplot.cpp\
    MODEL/IMPLEMENTATION/numbers.cpp \
    MODEL/IMPLEMENTATION/SetLogic.cpp \
    MODEL/IMPLEMENTATION/DatasetLogic.cpp\
    MODEL/IMPLEMENTATION/AdvancedLogic.cpp \
    GUI/IMPLEMENTATION/View.cpp \
    MODEL/IMPLEMENTATION/AppKalk.cpp \
    MODEL/IMPLEMENTATION/Logic.cpp \
    GUI/IMPLEMENTATION/Input.cpp \
    MODEL/IMPLEMENTATION/parser.cpp \
    MODEL/IMPLEMENTATION/basiclogic.cpp \
    MODEL/IMPLEMENTATION/SetCommonOperation.cpp \
    MODEL/IMPLEMENTATION/AdvancedCommonOperation.cpp \
    MODEL/IMPLEMENTATION/DatasetCommonOperation.cpp \
    GUI/IMPLEMENTATION/Keyboard.cpp \
    GUI/IMPLEMENTATION/SetKeyboard.cpp \
    GUI/IMPLEMENTATION/DatasetKeyboard.cpp \
    GUI/IMPLEMENTATION/AdvancedKeyboard.cpp


HEADERS += \
    MODEL/HEADER/Dataset.h \
    MODEL/HEADER/Set.h \
    MODEL/HEADER/numbers.h \
    GUI/HEADER/extrapanel.h \
    GUI/HEADER/qcustomplot.h\
    MODEL/HEADER/SetLogic.h\
    MODEL/HEADER/DatasetLogic.h \
    MODEL/HEADER/AdvancedLogic.h \
    GUI/HEADER/View.h \
    MODEL/HEADER/AppKalk.h \
    MODEL/HEADER/Advanced.h \
    MODEL/HEADER/Logic.h \
    GUI/HEADER/Input.h \
    MODEL/HEADER/parser.h \
    MODEL/HEADER/basiclogic.h \
    MODEL/HEADER/SetCommonOperation.h \
    MODEL/HEADER/DatasetCommonOperation.h \
    MODEL/HEADER/AdvancedCommonOperation.h \
    GUI/HEADER/Keyboard.h \
    GUI/HEADER/SetKeyboard.h \
    GUI/HEADER/DatasetKeyboard.h \
    GUI/HEADER/AdvancedKeyboard.h
