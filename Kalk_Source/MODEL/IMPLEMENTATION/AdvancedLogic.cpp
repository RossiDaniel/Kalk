#include "MODEL/HEADER/AdvancedLogic.h"

AdvancedLogic::AdvancedLogic(std::list<const numbers*>* l): BasicLogic(QString("ADVANCED"),"advanced",l){
    operand1=0;
    operand2=0;
    operation=0;
}

AdvancedLogic::~AdvancedLogic(){

}

void AdvancedLogic::singleOperation(QString){

}

void AdvancedLogic::add_set(QString name,QString data){
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if((*cit)->get_name() == name.toStdString() && (*cit)->get_name() == name.toStdString()){
            throw QString("The element you want to delete doesn't exist.");
        }
    }
    elements->push_back(const_cast<numbers*>((new advanced(name.toStdString(),parser(data)))));
    update();
}

void AdvancedLogic::add_elements(QString name,QString data){
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
void AdvancedLogic::sub_elements(QString name,QString data){

}

bool AdvancedLogic::condition()const{
    return (n*10+k) > 50 && somma>INT_MAX;
}
