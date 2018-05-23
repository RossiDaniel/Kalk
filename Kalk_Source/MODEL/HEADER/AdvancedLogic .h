#ifndef SETLOGIN_H
#define SETLOGIN_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "MODEL/HEADER/abstractlogic.h"

class AdvancedLogic: public AbstractLogic{
private:
    numbers* operand1;
    numbers* operand2;
    std::string* operation;

public:
    AdvancedLogic();
    ~AdvancedLogic();
};

#endif // SETLOGIN_H
