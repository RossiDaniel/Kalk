#include "MODEL/HEADER/SetLogic.h"

SetLogic::SetLogic(std::list<const numbers*>* l): BasicLogic(QString("SET"),"set",l){
    elements->push_back(new set("U"));
    operand1=0;
    operand2=0;
    operation=0;
}

SetLogic::~SetLogic(){

}
void SetLogic::selectOperand(QListWidgetItem* name){
    if(name->text() == "U"){
        emit setError(QString("Remember you cannot do operation with Set U"));
    }
    else{
        BasicLogic::selectOperand(name);
    }
}


void SetLogic::singleOperation(QString){

}

void SetLogic::add_set(QString name,QString data){
    std::cout<<"ciucia";
    bool sent=false;
    for(std::list<const numbers*>::iterator it= elements->begin(); it!=elements->end() && !sent; it++){
        if((*it)->get_name() == name.toStdString() && dynamic_cast<const set*>(*it)){
            sent =true;
            emit setErrorInput(QString("Exception: a SET named '"+ name +"' already exists in the universe."));
        }
    }
    if(!sent){
        set* s=new set(name.toStdString(),parser(data));
        elements->push_back(s->clone());
        set* n=const_cast<set*>(static_cast<const set*>(*(elements->begin())));
        *n =Suni->Union(*n,*s);
        ((const_cast<numbers*>(*elements->begin())))->change_name("U");
    }
    getElements();
}
void SetLogic::sub_set(QString name,QString data){

}
void SetLogic::add_elements(QString name,QString data){

}
void SetLogic::sub_elements(QString name,QString data){

}

bool SetLogic::condition()const{
    return dimensione >= num-1;
}
