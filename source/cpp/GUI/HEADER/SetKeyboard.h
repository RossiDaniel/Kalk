#ifndef SETVIEW_H
#define SETVIEW_H

#include <QWidget>
#include <GUI/HEADER/Keyboard.h>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include"MODEL/HEADER/SetLogic.h"
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>

class SetKeyboard: public Keyboard{
    Q_OBJECT

public:
    SetKeyboard();
    ~SetKeyboard();
    std::vector<QString> getSingleOperationkeyboard()const;
    std::vector<QString> getMultiOperationkeyboard()const;
    std::vector<QString> getExtraOperationkeyboard()const;
};

#endif // SETVIEW_H
