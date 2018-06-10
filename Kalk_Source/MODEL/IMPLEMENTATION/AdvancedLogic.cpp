#include "MODEL/HEADER/AdvancedLogic.h"

AdvancedLogic::AdvancedLogic(std::list<const numbers*>* l){
    elements=l;
}

AdvancedLogic::~AdvancedLogic(){

}
void AdvancedLogic::SetOperation(QString name){
    if(!operand1){throw QString("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new QString(name);
}
void AdvancedLogic::CE(){

}
void AdvancedLogic::singleOperation(QString){

}
