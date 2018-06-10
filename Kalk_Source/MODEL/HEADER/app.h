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
#include "MODEL/HEADER/DatasetLogic.h"
#include "GUI/HEADER/datasetview.h"
#include "MODEL/HEADER/Dataset.h"
#include <QWidget>
#include <QObject>
#include <GUI/HEADER/kalkmainwindow.h>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include"MODEL/HEADER/DatasetLogic.h"
#include"MODEL/HEADER/AdvancedLogic.h"

#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>
#include<QGraphicsView>
#include<GUI/HEADER/View.h>

class AppKalk: public QObject{
    Q_OBJECT
private:
    View* container_view;
    AbstractLogic* uni;
    std::list<const numbers*>* Uset;
    std::vector<KalkMainWindow*> views;
    std::vector<AbstractLogic*> logics;

public:
    AppKalk();
    ~AppKalk();

public slots:
    void changeLogic(int);

};

#endif // APP_H
