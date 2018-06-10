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
    std::list<const numbers*>* elements;
    numbers* operand1;
    numbers* operand2;
    QString* operation;

public:
    DatasetLogic(std::list<const numbers*>*);
    ~DatasetLogic();
public slots:
    void SetOperation(QString);
    void CE();
    void singleOperation(QString);};
#endif // DATASETLOGIC_H
