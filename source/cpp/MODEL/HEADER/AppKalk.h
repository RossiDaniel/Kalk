#ifndef APP_H
#define APP_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "GUI/HEADER/Keyboard.h"
#include "MODEL/HEADER/Logic.h"
#include "MODEL/HEADER/SetLogic.h"
#include "GUI/HEADER/SetKeyboard.h"
#include "MODEL/HEADER/Set.h"
#include "MODEL/HEADER/DatasetLogic.h"
#include "GUI/HEADER/DatasetKeyboard.h"
#include "MODEL/HEADER/Dataset.h"
#include <QWidget>
#include <QObject>
#include <GUI/HEADER/Keyboard.h>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include"MODEL/HEADER/DatasetLogic.h"
#include"MODEL/HEADER/AdvancedLogic.h"
#include "MODEL/HEADER/Set.h"
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>

#include<GUI/HEADER/View.h>
#include"GUI/HEADER/Input.h"

class AppKalk: public QWidget{
    Q_OBJECT
private:
    View* container_view;
    Logic* logic;
    Input* input_manage;
public:
    AppKalk();
    ~AppKalk();
    void configure();
};

#endif // APP_H
