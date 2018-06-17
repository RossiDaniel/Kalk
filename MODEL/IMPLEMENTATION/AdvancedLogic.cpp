#include "MODEL/HEADER/AdvancedLogic.h"

AdvancedLogic::AdvancedLogic(std::list<const numbers*>* l): BasicLogic(QString("ADVANCED"),"advanced",l){
    operand1=0;
    operand2=0;
    operation=0;
    commonOperation= new AdvancedCommonOperation();
}

AdvancedLogic::~AdvancedLogic(){

}

numbers* AdvancedLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new advanced(name,data);
}

bool AdvancedLogic::condition()const{
    return (n*10+k) > 50 && somma>INT_MAX;
}

void AdvancedLogic::results(){
    if(!operand1 || !operand2 || operation ==-1){throw QString("ERROR: a operand must be chosen before operation.");}
    try{
    switch (operation) {
        case 0:
            emit setBarra((commonOperation->codevianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 1:
        emit setBarra((commonOperation->codevianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 2:
        emit setBarra((commonOperation->codevianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 3:
        emit setBarra((commonOperation->codevianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 4:
        emit setBarra((commonOperation->codevianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        default:
            emit setError(QString("ERROR: operation is not available."));
    }
    }catch(QString q){
        emit setErrorInput(q);
    }
    CE();
}
