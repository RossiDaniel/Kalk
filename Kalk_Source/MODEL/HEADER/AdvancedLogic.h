#ifndef ADVANCED_LOGIC_H
#define ADVANCED_LOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/basiclogic.h"
#include"MODEL/HEADER/parser.h"

#include"MODEL/HEADER/Advanced.h"


class AdvancedLogic: public BasicLogic{

public:
    AdvancedLogic(std::list<const numbers*>*);
    ~AdvancedLogic();
    void singleOperation(QString);

    void add_set(QString,QString);
    void sub_set(QString,QString);
    void add_elements(QString,QString);
    void sub_elements(QString,QString);

    bool condition()const;


};
#endif // ADVANCED_LOGIC_H
