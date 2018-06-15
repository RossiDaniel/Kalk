#ifndef DATASETLOGIC_H
#define DATASETLOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/basiclogic.h"
#include"MODEL/HEADER/parser.h"
#include"MODEL/HEADER/Dataset.h"

class DatasetLogic: public BasicLogic,Parser{

public:
    DatasetLogic(std::list<const numbers*>*);
    ~DatasetLogic();
    void singleOperation(QString);

    void add_set(QString,QString);
    void add_elements(QString,QString);
    void sub_elements(QString,QString);

    bool condition()const;


};
#endif // DATASETLOGIC_H
