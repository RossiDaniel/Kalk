#ifndef DATASETLOGIC_H
#define DATASETLOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "abstractlogic.h"

class DatasetLogic: public AbstractLogic{
private:
    numbers* operand1;
    numbers* operand2;
    std::string* operation;

public:
    DatasetLogic();
    ~DatasetLogic();
};

#endif // DATASETLOGIC_H
