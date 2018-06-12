#ifndef DATASETLOGIC_H
#define DATASETLOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/abstractlogic.h"
#include"MODEL/HEADER/Dataset.h"

class DatasetLogic: public AbstractLogic{
private:
    std::list<const numbers*>* elements;
    numbers* operand1;
    numbers* operand2;
    QString* operation;

public:
    DatasetLogic(std::list<const numbers*>*);
    ~DatasetLogic();
    void SetOperation(QString);
    void singleOperation(QString);
    void getElements();
    void selectOperand(QListWidgetItem*);
    void CE();
    void SetOperand(std::string, std::string);

};
#endif // DATASETLOGIC_H
