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
    std::list<const numbers*>* elements;
    numbers* operand1;
    numbers* operand2;
    QString* operation;

public:
    SetLogic(std::list<const numbers*>*);
    ~SetLogic();

public slots:
    void SetOperation(QString);
    void CE();
    void singleOperation(QString);
};

#endif // SETLOGIN_H
