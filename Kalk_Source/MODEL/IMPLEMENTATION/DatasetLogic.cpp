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
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if((*cit)->get_name() == name.toStdString() && (*cit)->get_name() == name.toStdString()){
            throw QString("The element you want to delete doesn't exist.");
        }
    }
    elements->push_back(const_cast<numbers*>((new dataset(name.toStdString(),parser(data)))));
    update();
}

void DatasetLogic::add_elements(QString name,QString data){
    bool sent=false;
    std::list<const numbers*>::const_iterator cit= elements->begin();
    for(; cit!=elements->end() && !sent; cit++){
        if((*cit)->get_name() == name.toStdString() && type == (*cit)->name()){
            sent =true;
            (const_cast<numbers*>(*elements->begin()))->add_list(parser(data));
        }
    }
    if(!sent){throw QString("Error: the element inserted doesn't exist.");}
}
void DatasetLogic::sub_elements(QString name,QString data){

}

bool DatasetLogic::condition()const{
    return dimensione >=num-1 && somma>INT_MAX;
}
