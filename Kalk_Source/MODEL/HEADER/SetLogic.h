#ifndef SETLOGIN_H
#define SETLOGIN_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "MODEL/HEADER/abstractlogic.h"
#include "MODEL/HEADER/Set.h"

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
    void singleOperation(QString);
    void getElements();
    void selectOperand(QListWidgetItem*);
    void CE();
    void SetOperand(std::string, std::string);

};

#endif // SETLOGIN_H
