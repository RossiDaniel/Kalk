#include "MODEL/HEADER/DatasetLogic.h"

DatasetLogic::DatasetLogic(std::list<const numbers*>* l): BasicLogic(QString("DATASET"),"dataset",l){
    operand1=0;
    operand2=0;
    operation=0;
    commonOperation= new DatasetCommonOperation();
}

DatasetLogic::~DatasetLogic(){
    AC();
    delete commonOperation;
}

dataset *DatasetLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new dataset(name,data);
}

void DatasetLogic::singleOperation(int index){
    if(!operand1){throw QString("ERROR: a operand must be chosen before operation.");}
    std::string str;
    try{
    switch (index) {
        case 0:
            emit setBarra(QString(commonOperation->somme(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 1:
            emit setBarra(QString(commonOperation->size(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 2:
            emit setBarra(QString(commonOperation->average(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 3:
            emit setBarra(QString(commonOperation->gl(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 4:
            emit setBarra(QString(commonOperation->variance(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 5:
            emit setBarra(QString(commonOperation->ds(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 6:
            emit setBarra(QString(commonOperation->deviance(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 7:
            emit setBarra(QString(commonOperation->deviation(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        case 8:
            emit setBarra(QString(commonOperation->deviation2(*(dynamic_cast<const dataset*>(operand1))).c_str()));
            break;
        default:
            BasicLogic::singleOperation(index);
    }
    }catch(QString q){
        emit setError(q);
    }
    catch(std::string str){
        emit setError(QString(str.c_str()));
    }

    AC();
}

bool DatasetLogic::condition()const{
    std::cout<<somma<<" "<<INT_MAX<<std::endl;
    if(somma>INT_MAX){
        throw QString("The inserted value si too big, insert a smaller number");
    }
    return dimensione >=num-1;
}

