#ifndef SETLOGIN_H
#define SETLOGIN_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "MODEL/HEADER/basiclogic.h"
#include "MODEL/HEADER/parser.h"
#include "MODEL/HEADER/Set.h"

class SetLogic: public BasicLogic,Parser{

public:
    SetLogic(std::list<const numbers*>*);
    ~SetLogic();
    void singleOperation(QString);
    void selectOperand(QListWidgetItem*);
    void add_set(QString,QString);
    void sub_set(QString,QString);
    void add_elements(QString,QString);
    void sub_elements(QString,QString);
    bool condition()const;


};

#endif // SETLOGIN_H
