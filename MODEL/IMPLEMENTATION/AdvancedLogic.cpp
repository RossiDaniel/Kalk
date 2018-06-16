#include "MODEL/HEADER/AdvancedLogic.h"

AdvancedLogic::AdvancedLogic(std::list<const numbers*>* l): BasicLogic(QString("ADVANCED"),"advanced",l){
    operand1=0;
    operand2=0;
    operation=0;
}

AdvancedLogic::~AdvancedLogic(){

}

numbers* AdvancedLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new advanced(name,data);
}

void AdvancedLogic::singleOperation(int index){

}

bool AdvancedLogic::condition()const{
    return (n*10+k) > 50 && somma>INT_MAX;
}
