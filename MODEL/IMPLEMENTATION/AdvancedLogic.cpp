#include "MODEL/HEADER/AdvancedLogic.h"

AdvancedLogic::AdvancedLogic(std::list<const numbers*>* l): BasicLogic(QString("ADVANCED"),"advanced",l){
    operand1=0;
    operand2=0;
    operation=0;
    commonOperation= new AdvancedCommonOperation();
}

AdvancedLogic::~AdvancedLogic(){
    AC();
    delete commonOperation;
}

advanced *AdvancedLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new advanced(name,data);
}

bool AdvancedLogic::condition()const{
    if(somma>INT_MAX){
        throw QString("The inserted value si too big, insert a smaller number");
    }
    return (n*10+k) > 50;
}

void AdvancedLogic::results(){
    if(!operand1 || !operand2 || operation ==-1){throw QString("ERROR: a operand must be chosen before operation.");}
    try{
    switch (operation) {
        case 0:
            emit setBarra((commonOperation->Allinfo(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 1:
            emit setBarra((commonOperation->coscarto(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 2:
            emit setBarra((commonOperation->codevianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 3:
            emit setBarra((commonOperation->covarianza(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 4:
            emit setBarra((commonOperation->correlazione(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 5:
            emit setBarra((commonOperation->coeff_determinazione(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 6:
            emit setBarra((commonOperation->regressione(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 7:
            emit setBarra((commonOperation->intercetta(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 8:
            emit setBarra((commonOperation->retta(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        case 9:
            emit setBarra((commonOperation->Grafic(*(dynamic_cast<const advanced*>(operand1)),*(dynamic_cast<const advanced*>(operand2)))).c_str());
            break;
        default:
            emit setError(QString("ERROR: operation is not available."));
    }
    }catch(QString q){
        emit setError(q);
    }
    catch(std::string str){
        emit setError(QString(str.c_str()));
    }
    AC();
}

void AdvancedLogic::extraoperation(int index){
    try{
    switch (index) {
        case 0:
            results();
             break;
        default:
            emit setBarra(QString("ERROR: no extraoperation with that index."));
    }
    }catch(QString q){
        emit setErrorInput(q);
    }
    catch(std::string str){
        emit setError(QString(str.c_str()));
    }
}
