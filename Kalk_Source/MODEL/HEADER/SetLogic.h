#ifndef SETLOGIN_H
#define SETLOGIN_H

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
    SetCommonOperation* Suni;
public:
    SetLogic(std::list<const numbers*>*);
    ~SetLogic();
    void singleOperation(QString);
    void selectOperand(QListWidgetItem*);
    void add_set(QString,QString);
    void sub_set(QString);
    void add_elements(QString,QString);
    void sub_elements(QString,QString);
    bool condition()const;
    bool in(const int,std::string)const;
    numbers* getObjectLogicClass(std::string,std::list<int>);

};

#endif // SETLOGIN_H
