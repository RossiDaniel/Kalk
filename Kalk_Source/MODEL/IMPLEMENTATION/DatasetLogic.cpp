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
    delete operand1;operand1=0;
    delete operation;operation=0;
    delete operand2;operand2=0;

}
void DatasetLogic::singleOperation(QString){

}
void DatasetLogic::getElements(){
    std::list<QString> l;
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if(dynamic_cast<const dataset*>(*cit)){
            l.push_back(QString::fromUtf8((*cit)->get_name().c_str()));
        }
    }
    emit listOfElements(l);

}
