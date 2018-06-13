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

void AdvancedLogic::sub_set(QString name,QString data){

}
void AdvancedLogic::add_elements(QString name,QString data){

}
void AdvancedLogic::sub_elements(QString name,QString data){

}

bool AdvancedLogic::condition()const{
    return (n*10+k) > 50 && somma>INT_MAX;
}
