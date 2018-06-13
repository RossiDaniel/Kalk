#include "MODEL/HEADER/DatasetLogic.h"

DatasetLogic::DatasetLogic(std::list<const numbers*>* l): BasicLogic(QString("DATASET"),"dataset",l){
    operand1=0;
    operand2=0;
    operation=0;
}

DatasetLogic::~DatasetLogic(){

}


void DatasetLogic::singleOperation(QString){

}

void DatasetLogic::add_set(QString name,QString data){
    bool sent=false;/*
    for(std::list<const numbers*>::iterator it= elements->begin(); it!=elements->end() && !sent; it++){
        if((*it)->get_name() == name.toStdString() && dynamic_cast<const set*>(*it)){
            sent =true;
            emit setError(QString("Exception: a SET named '"+ name +"' already exists in the universe."));
        }
    }
    if(!sent){
        set* s=new set();
        elements->push_back(const_cast<numbers*>((s->clone())));
        set* n=const_cast<set*>(static_cast<const set*>(*(elements->begin())));
        *n =Suni->Union(*n,*const_cast<set*>(dynamic_cast<const set*>(&s)));
        ((const_cast<numbers*>(*elements->begin())))->change_name("U");
    }*/
}

void DatasetLogic::sub_set(QString name,QString data){

}
void DatasetLogic::add_elements(QString name,QString data){

}
void DatasetLogic::sub_elements(QString name,QString data){

}

bool DatasetLogic::condition()const{
    return dimensione >=num-1 && somma>INT_MAX;
}
