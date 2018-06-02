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
#include"MODEL/HEADER/SetLogic.h"
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>
#include<QGraphicsView>
#include<GUI/HEADER/generalview.h>

class AppKalk: public QObject{
    Q_OBJECT
private:
    GeneralView* view_general;
    KalkMainWindow* view;
    AbstractLogic* uni;
    std::list<const numbers*> Uset;

public:
    AppKalk();
    ~AppKalk();
    void changeStatus(KalkMainWindow*, AbstractLogic*);
public slots:
    void selectStatus(QString);

};

#endif // APP_H
