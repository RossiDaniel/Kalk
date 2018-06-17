#ifndef SETLOGIC_H
#define SETLOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "MODEL/HEADER/basiclogic.h"
#include "MODEL/HEADER/Set.h"
#include "MODEL/HEADER/SetCommonOperation.h"

class SetLogic: public BasicLogic{
private:
    SetCommonOperation* commonOperation;
public:
    SetLogic(std::list<const numbers*>*);
    ~SetLogic();
    void singleOperation(int);
    void selectOperand(QListWidgetItem*);
    void add_set(QString,QString);
    void sub_set(QString);
    void add_elements(QString,QString);
    void sub_elements(QString,QString);
    bool condition()const;
    bool in(const int,std::string)const;
    numbers* getObjectLogicClass(std::string,std::list<int>);
    void results();
    void clearKalkElements();
};

#endif // SETLOGIC_H
