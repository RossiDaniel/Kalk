#include "MODEL/HEADER/SetLogic.h"

SetLogic::SetLogic(std::list<const numbers*>* l){
    elements=l;
}

SetLogic::~SetLogic(){

}

void SetLogic::SetOperation(QString name){
    if(!operand1){throw QString("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new QString(name);
}
void SetLogic::CE(){

}
void SetLogic::singleOperation(QString){

}
