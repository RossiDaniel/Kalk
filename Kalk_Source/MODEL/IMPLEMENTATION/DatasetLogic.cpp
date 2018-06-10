#include "MODEL/HEADER/DatasetLogic.h"

DatasetLogic::DatasetLogic(std::list<const numbers*>* l){
    elements=l;
}

DatasetLogic::~DatasetLogic(){

}
void DatasetLogic::SetOperation(QString name){
    if(!operand1){throw QString("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new QString(name);
}
void DatasetLogic::CE(){

}
void DatasetLogic::singleOperation(QString){

}
