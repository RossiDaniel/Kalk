#ifndef ADVANCED_LOGIC_H
#define ADVANCED_LOGIC_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"MODEL/HEADER/basiclogic.h"
#include"MODEL/HEADER/Advanced.h"

class AdvancedLogic: public BasicLogic{

public:
    AdvancedLogic(std::list<const numbers*>*);
    ~AdvancedLogic();

    //Override BasicLogic
    void singleOperation(QString);
    numbers* getObjectLogicClass(std::string,std::list<int>);

    //Overidde Parser
    bool condition()const;


};
#endif // ADVANCED_LOGIC_H
