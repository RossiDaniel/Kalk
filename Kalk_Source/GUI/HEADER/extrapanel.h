#ifndef EXTRAPANEL_H
#define EXTRAPANEL_H

#include "MODEL/HEADER/Set.h"
#include "MODEL/HEADER/Dataset.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QScrollBar>
#include <QLabel>
#include <QString>
#include <climits>


class extrapanel:public QWidget{
    Q_OBJECT

public:
    virtual ~extrapanel();
    virtual std::list<int> parser()const =0;


public slots:

    virtual void creaset()=0;
    virtual void remove()=0;
    virtual void addelement()=0;
    virtual void subelement()=0;
    virtual void modify()=0;
    virtual void update()=0;

};
#endif // EXTRAPANEL_H
