#ifndef APP_H
#define APP_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "GUI/HEADER/kalkmainwindow.h"
#include "MODEL/HEADER/abstractlogic.h"
#include "MODEL/HEADER/SetLogic.h"
#include "GUI/HEADER/setview.h"
#include "MODEL/HEADER/Set.h"
#include <QWidget>
#include <GUI/HEADER/kalkmainwindow.h>
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

class AppKalk{
    Q_OBJECT
private:
    KalkMainWindow* view;
    AbstractLogic* uni;
    std::list<const numbers*> Uset;

public:
    AppKalk();
    ~AppKalk();
};

#endif // APP_H
