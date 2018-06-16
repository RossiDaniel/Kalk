#ifndef DATASETLOGIC_H
#define DATASETLOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/basiclogic.h"
#include"MODEL/HEADER/Dataset.h"

class DatasetLogic: public BasicLogic{

public:
    DatasetLogic(std::list<const numbers*>*);
    ~DatasetLogic();

    //Override BasicLogic
    void singleOperation(QString);
    numbers* getObjectLogicClass(std::string,std::list<int>);

    //Overidde Parser
    bool condition()const;


};
#endif // DATASETLOGIC_H
