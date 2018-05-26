#ifndef DATASETLOGIN_H
#define DATASETLOGIN_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"abstractlogic.h"

class AdvancedLogic: public AbstractLogic{
private:
    numbers* operand1;
    numbers* operand2;
    std::string* operation;

public:
    AdvancedLogic();
    ~AdvancedLogic();
};

#endif // DATASETLOGIN_H
