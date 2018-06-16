#include "MODEL/HEADER/DatasetLogic.h"

DatasetLogic::DatasetLogic(std::list<const numbers*>* l): BasicLogic(QString("DATASET"),"dataset",l){
    operand1=0;
    operand2=0;
    operation=0;
    Duni= new DatasetCommonOperation();
}

DatasetLogic::~DatasetLogic(){

}

numbers* DatasetLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new dataset(name,data);
}

void DatasetLogic::singleOperation(int index){
    std::string str;
    try{
    switch (index) {
        case 0:
            emit setBarra(QString(Duni->somme(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 1:
            emit setBarra(QString(Duni->size(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 2:
            emit setBarra(QString(Duni->average(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 3:
            emit setBarra(QString(Duni->gl(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 4:
            emit setBarra(QString(Duni->variance(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 5:
            emit setBarra(QString(Duni->ds(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 6:
            emit setBarra(QString(Duni->deviance(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 7:
            emit setBarra(QString(Duni->deviation(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 8:
            emit setBarra(QString(Duni->deviation2(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        default:
            std::cout<<index;
    }
    }catch(QString q){
        emit setErrorInput(q);
    }
}

bool DatasetLogic::condition()const{
    return dimensione >=num-1 && somma>INT_MAX;
}
