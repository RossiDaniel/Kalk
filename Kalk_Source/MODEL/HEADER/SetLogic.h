#ifndef SETLOGIN_H
#define SETLOGIN_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "MODEL/HEADER/abstractlogic.h"

class SetLogic: public AbstractLogic{
private:
    numbers* operand1;
    numbers* operand2;
    std::string* operation;

public:
    SetLogic();
    ~SetLogic();

public slots:
    void printValue();
};

#endif // SETLOGIN_H
