#ifndef ADVANCED_LOGIC_H
#define ADVANCED_LOGIC_H

#include <iostream>
#include <list>
#include <string>
#include <typeinfo>
#include "numbers.h"
#include "MODEL/HEADER/basiclogic.h"
#include "MODEL/HEADER/Advanced.h"
#include "MODEL/HEADER/AdvancedCommonOperation.h"

class AdvancedLogic: public BasicLogic{
    AdvancedCommonOperation* commonOperation;

public:
    AdvancedLogic(std::list<const numbers*>*);
    ~AdvancedLogic();

    //Override BasicLogic
    advanced* getObjectLogicClass(std::string,std::list<int>);

    //Overidde Parser
    bool condition()const;
    void results();
    void extraoperation(int);


};
#endif // ADVANCED_LOGIC_H
