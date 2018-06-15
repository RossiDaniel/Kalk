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
    BasicLogic::selectOperand(name);
}


void SetLogic::singleOperation(QString){

}

void SetLogic::add_set(QString name,QString data){
    bool sent=false;
    for(std::list<const numbers*>::iterator it= elements->begin(); it!=elements->end() && !sent; it++){
        if((*it)->get_name() == name.toStdString() && dynamic_cast<const set*>(*it)){
            sent =true;
            throw QString("Exception: a SET named '"+ name +"' already exists in the universe.");
        }
    }
    if(!sent){
        set* s=new set(name.toStdString(),parser(data));
        elements->push_back(s->clone());
        set* n=const_cast<set*>(static_cast<const set*>(*(elements->begin())));
        *n =Suni->Union(*n,*s);
        ((const_cast<numbers*>(*elements->begin())))->change_name("U");
    }
    update();
}

void SetLogic::sub_set(QString name,QString data){
    if(name.toStdString() == "U"){throw QString("Exception: the 'U' Set cannot be deleted.");}
    bool sent =false;
    std::list<const numbers*>::iterator it= elements->begin();
    for(; it!=elements->end() && !sent; it++){
        if((*it)->get_name() == name.toStdString()  && dynamic_cast<const set*>(*it)){
            sent =true;
            std::list<int> l= (static_cast<const set*>(*it))->get_element();
            std::list<int>::const_iterator cit= l.begin();
            bool found =false;
            for(; cit!=l.end(); cit++){
                found =this->in(*cit,name.toStdString());
                if(!found){const_cast<set*>(static_cast<const set*>(*elements->begin()))->sub_value(*cit);}
            }
            delete *it;
            it=elements->erase(it);
        }
    }
    if(!sent){throw QString("The element you want to delete doesn't exist.");}
    update();

}
void SetLogic::add_elements(QString name,QString data){
    if(name.toStdString() == "U"){throw QString("Error: the 'U' Set cannot be deleted.");}
    bool sent =false;
    std::list<const numbers*>::const_iterator cit= elements->begin();
    for(; cit!=elements->end() && !sent; cit++){
        if((*cit)->get_name() == name.toStdString() && dynamic_cast<const set*>(*cit)){
            sent =true;
            if(name.toStdString() == "U"){throw QString("Error: you cannot add numbers to element U.");}
            else{
                std::list<int> l=parser(data);
                (const_cast<numbers*>(*cit))->add_list(l);
                (const_cast<numbers*>(*elements->begin()))->add_list(l);
            }
        }
    }
    if(!sent){throw QString("Error: the element inserted doesn't exist.");}
}
void SetLogic::sub_elements(QString name,QString data){

}

bool SetLogic::condition()const{
    return dimensione >= num-1;
}

bool SetLogic::in(const int n,std::string name)const{
    bool sent=false;
    std::list<const numbers*>::const_iterator cit= elements->begin();
        cit++;
        for(; cit!=elements->end() && !sent; cit++){
            if(dynamic_cast<const set*>(*cit) && (*cit)->get_name()!=name){
                sent=static_cast<const set*>(*cit)->search(n);
            }
        }
    return sent;
}

