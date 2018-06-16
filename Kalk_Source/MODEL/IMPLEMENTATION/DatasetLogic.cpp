#include "MODEL/HEADER/DatasetLogic.h"

DatasetLogic::DatasetLogic(std::list<const numbers*>* l): BasicLogic(QString("DATASET"),"dataset",l){
    operand1=0;
    operand2=0;
    operation=0;
}

DatasetLogic::~DatasetLogic(){

}

numbers* DatasetLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new dataset(name,data);
}

void DatasetLogic::singleOperation(QString){

}

bool DatasetLogic::condition()const{
    return dimensione >=num-1 && somma>INT_MAX;
}
