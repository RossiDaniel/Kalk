#include "MODEL/HEADER/SetLogic.h"

SetLogic::SetLogic(std::list<const numbers*>* l): BasicLogic(QString("SET"),"set",l){
    elements->push_back(new set("U"));
    operand1=0;
    operand2=0;
    operation=0;
    result=0;
    commonOperation=new SetCommonOperation();
}

SetLogic::~SetLogic(){
    if(result){delete result;result=0;}
    AC();
    delete commonOperation;
}

set* SetLogic::getObjectLogicClass(std::string name,std::list<int> data){
    return new set(name,data);
}


void SetLogic::selectOperand(QListWidgetItem* name){
    if(name->text() == "U"){
        std::string str =*const_cast<numbers*>(*(elements->begin()));
        emit setBarra(QString(str.c_str()));
    }
    else{
        BasicLogic::selectOperand(name);
    }
}


void SetLogic::singleOperation(int index){
    if(!operand1){throw QString("ERROR: a operand must be chosen before operation.");}
    std::string str;
    if(result!=0){delete result; result=0;}
    try{
    switch (index) {
        case 0:
            result=&commonOperation->Difference(*(dynamic_cast<const set*>(*elements->begin())),*(dynamic_cast<const set*>(operand1)));
            result->change_name("not"+operand1->get_name());
            str=*result;
            emit setBarra(str.c_str());
            break;
        case 1:
            emit setBarra(QString(commonOperation->PowerSet(*(dynamic_cast<const set*>(operand1))).c_str()));
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

void SetLogic::add_set(QString name,QString data){
    bool sent=false;
    for(std::list<const numbers*>::iterator it= elements->begin(); it!=elements->end() && !sent; it++){
        if((*it)->get_name() == name.toStdString() && dynamic_cast<const set*>(*it)){
            sent =true;
            throw QString("Exception: a SET named '"+ name +"' already exists in the universe.");
        }
    }
    if(!sent){
        set* s=const_cast<set*>(static_cast<const set*>(getObjectLogicClass(parserName(name),parserData(data))));
        elements->push_back(s->clone());
        set* n=const_cast<set*>(static_cast<const set*>(*(elements->begin())));
        *n =commonOperation->Union(*n,*s);
        ((const_cast<numbers*>(*elements->begin())))->change_name("U");
        delete s;
    }
    update();
}

void SetLogic::sub_set(QString name){
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
    if(!sent){throw QString("ERROR: The element you want to delete doesn't exist.");}
    update();
}

void SetLogic::sub_elements(QString name,QString data){
    bool sent =false;
    if(name.toStdString() == "U"){
        sent=true;
        std::list<const numbers*>::const_iterator cit= elements->begin();
        for(; cit!=elements->end(); cit++){
            if(dynamic_cast<const set*>(*cit)){
                (const_cast<numbers*>(*cit))->sub_list(parserData(data));
            }
        }
    }
    else{
        std::list<const numbers*>::const_iterator cit= elements->begin();
        for(; cit!=elements->end() && !sent; cit++){
            if((*cit)->get_name() == name.toStdString() && dynamic_cast<const set*>(*cit)){
                sent =true;
                std::list<int> l=parserData(data);
                std::list<int>::const_iterator lcit= l.begin();
                for(;lcit!=l.end(); lcit++){
                    bool found=this->in(*lcit,name.toStdString());
                    (const_cast<numbers*>(*cit))->sub_value(*lcit);
                    if(!found){(const_cast<numbers*>(*elements->begin()))->sub_value(*lcit);}
                }
            }
        }
    }
    if(!sent){throw QString("ERROR: l'elemento a cui vuoi sottrarre dei numeri non esiste");}
    update();
}
void SetLogic::add_elements(QString name,QString data){
    bool sent =false;
    std::list<const numbers*>::const_iterator cit= elements->begin();
    for(; cit!=elements->end() && !sent; cit++){
        if((*cit)->get_name() == name.toStdString() && dynamic_cast<const set*>(*cit)){
            sent =true;
            std::list<int> number=parserData(data);
            if(name.toStdString() != "U"){(const_cast<numbers*>(*cit))->add_list(number);}
            (const_cast<numbers*>(*elements->begin()))->add_list(number);
        }
    }
    if(!sent){throw QString("ERROR: The element you want to add doesn't exist.");}
    update();
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

void SetLogic::results(){
    if(!operand1 || !operand2 || operation ==-1){throw QString("ERROR: a operand must be chosen before operation.");}
    if(result){delete result;result=0;}

    std::string str;
    try{
    switch (operation) {
        case 0:
            result=&commonOperation->Union(*(dynamic_cast<const set*>(operand1)),*(dynamic_cast<const set*>(operand2)));
            str=*result;
            emit setBarra(str.c_str());
            break;
        case 1:
            result=&commonOperation->Intersection(*(dynamic_cast<const set*>(operand1)),*(dynamic_cast<const set*>(operand2)));
            str=*result;
            emit setBarra(str.c_str());
            break;
        case 2:
            result=&commonOperation->Difference(*(dynamic_cast<const set*>(operand1)),*(dynamic_cast<const set*>(operand2)));
            str=*result;
            emit setBarra(str.c_str());
            break;
        case 3:
            result=&commonOperation->SymmetricDifference(*(dynamic_cast<const set*>(operand1)),*(dynamic_cast<const set*>(operand2)));
            str=*result;
            emit setBarra(str.c_str());
            break;
        case 4:
            str=commonOperation->CartesianProduct(*(dynamic_cast<const set*>(operand1)),*(dynamic_cast<const set*>(operand2)));
            emit setBarra(str.c_str());
            break;
        default:
            emit setError(QString("ERROR: operation not available."));
    }
    }catch(QString q){
        emit setError(q);
    }
    catch(std::string str){
        emit setError(QString(str.c_str()));
    }
    AC();
}

void SetLogic::clearKalkElements(){
    std::list<const numbers*>::const_iterator cit= elements->begin();
    (const_cast<numbers*>(*cit))->clear();
    cit++;
    for(; cit!=elements->end(); cit++){
        if("set" == (*cit)->name()){
            delete *cit;
            cit=elements->erase(cit);
            cit--;
        }
    }
    emptyName=0;
    getElements();
}

void SetLogic::extraoperation(int index){
    try{
    switch (index) {
        case 0:
           BasicLogic::results();
            break;
        case 1:
            results();
             break;
        default:
            emit setBarra(QString("ERROR: no extraoperation with that index."));
    }
    }catch(QString q){
        emit setErrorInput(q);
    }
    catch(std::string str){
        emit setError(QString(str.c_str()));
    }
}
