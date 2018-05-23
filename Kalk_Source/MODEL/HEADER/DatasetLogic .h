#ifndef SETLOGIN_H
#define SETLOGIN_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "MODEL/HEADER/abstractlogic.h"

class DatasetLogic: public AbstractLogic{
private:
    numbers* operand1;
    numbers* operand2;
    std::string* operation;

public:
    DatasettLogic();
    ~DatasetLogic();
};

#endif // SETLOGIN_H
