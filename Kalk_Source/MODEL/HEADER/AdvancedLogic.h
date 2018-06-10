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
    std::list<const numbers*>* elements;
    numbers* operand1;
    numbers* operand2;
    QString* operation;

public:
    AdvancedLogic(std::list<const numbers*>*);
    ~AdvancedLogic();

public slots:
    void SetOperation(QString);
    void CE();
    void singleOperation(QString);};

#endif // DATASETLOGIN_H
