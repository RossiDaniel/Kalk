#ifndef ADVANCED_LOGIC_H
#define ADVANCED_LOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/abstractlogic.h"
#include"MODEL/HEADER/Advanced.h"


class AdvancedLogic: public AbstractLogic{
private:
    std::list<const numbers*>* elements;
    numbers* operand1;
    numbers* operand2;
    QString* operation;

public:
    AdvancedLogic(std::list<const numbers*>*);
    ~AdvancedLogic();
    void SetOperation(QString);
    void singleOperation(QString);
    void getElements();
    void selectOperand(QListWidgetItem*);
    void CE();
    void SetOperand(std::string, std::string);

};
#endif // ADVANCED_LOGIC_H
