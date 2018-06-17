#ifndef DATASETLOGIC_H
#define DATASETLOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/basiclogic.h"
#include"MODEL/HEADER/Dataset.h"
#include "MODEL/HEADER/DatasetCommonOperation.h"

class DatasetLogic: public BasicLogic{
private:
    DatasetCommonOperation* commonOperation;

public:
    DatasetLogic(std::list<const numbers*>*);
    ~DatasetLogic();

    //Override BasicLogic
    void singleOperation(int);
    numbers* getObjectLogicClass(std::string,std::list<int>);

    //Overidde Parser
    bool condition()const;


};
#endif // DATASETLOGIC_H
