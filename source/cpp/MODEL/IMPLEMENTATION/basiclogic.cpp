#include "MODEL/HEADER/basiclogic.h"
BasicLogic::BasicLogic(QString name, std::string tname, std::list<const numbers*>* l): nameType(name),type(tname),elements(l) {}
BasicLogic::~BasicLogic(){}
QString BasicLogic::getNameType(){
    return nameType;
}

void BasicLogic::getElements(){
    std::list<QString> l;
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if(type == (*cit)->name()){
            l.push_back(QString::fromUtf8((*cit)->get_name().c_str()));
        }
    }
    emit listOfElements(l);
}

void BasicLogic::AC(){
    if(operand1){
        delete operand1;operand1=0;
    }
    if(operand2){
        delete operand2;operand2=0;
    }
    if(operation!=-1){
        operation=-1;
    }
}

void BasicLogic::selectOperand(QListWidgetItem* element){
    std::string name=element->text().toStdString();
    if(!operand1){
        return SetOperand(name,"Operand1");
    }
    else{
        if(operation==-1){
            return SetOperand(name,"Operand1");
        }
        else{
            return SetOperand(name,"Operand2");
        }
    }
}

void BasicLogic::SetOperand(std::string name, std::string op){
    std::string str;
    for(std::list<const numbers*>::const_iterator cit=elements->begin(); cit!=elements->end(); cit++){
        if(type == (*cit)->name() && (*cit)->get_name() == name){
            if(op == "Operand1"){
                if(operand1){delete operand1;operand1=0;}
                operand1 = (*cit)->clone();
                str=*operand1;
            }
            else{
                if(operand2){delete operand2;operand2=0;}
                operand2 = (*cit)->clone();
                str=*operand2;
            }
        }
    }
    emit setBarra(QString::fromUtf8(str.c_str()));
}

void BasicLogic::multioperation(int index){
    if(!operand1){emit setError(QString("ERROR : an operand must be chosen before an operation is selected."));}
    if(operation==-1){operation=-1;operation=0;delete operand2;operand2=0;}
    operation =index;
}

void BasicLogic::add_set(QString name,QString data){
    for(std::list<const numbers*>::iterator it= elements->begin(); it!=elements->end(); it++){
        if((*it)->get_name() == name.toStdString() && checkType((*it)->name())){
            throw QString("ERROR: an element named '"+ name +"' already exists in the universe.");
        }
    }
    elements->push_back(getObjectLogicClass(parserName(name),parserData(data)));
    update();
}

void BasicLogic::sub_elements(QString name,QString data){
    bool sent =false;
    std::list<const numbers*>::const_iterator cit= elements->begin();
    for(; cit!=elements->end() && !sent; cit++){
        if(checkType((*cit)->name()) && (*cit)->get_name() == name.toStdString()){
            sent =true;
            (const_cast<numbers*>(*cit))->sub_list(parserData(data));
        }
    }
    if(!sent){throw QString("ERROR: The element you want to add doesn't exist.");}
    update();
}

void BasicLogic::sub_set(QString name){
    bool sent=false;
    for(std::list<const numbers*>::const_iterator cit=elements->begin(); !sent && cit!=elements->end(); cit++){
        if(checkType((*cit)->name()) && (*cit)->get_name() == name.toStdString()){
            sent =true;
            delete *cit;
            cit=elements->erase(cit);
        }
    }
    if(!sent){throw QString("ERROR: The element you want to delete doesn't exist.");}
    update();
}

void BasicLogic::add_elements(QString name, QString data){
    bool sent =false;
    std::list<const numbers*>::const_iterator cit= elements->begin();
    for(; cit!=elements->end() && !sent; cit++){
        if(checkType((*cit)->name()) && (*cit)->get_name() == name.toStdString()){
            sent =true;
            (const_cast<numbers*>(*cit))->add_list(parserData(data));
        }
    }
    if(!sent){throw QString("ERROR: The element you want to add doesn't exist.");}
    update();
}


void BasicLogic::update(){
    getElements();
    emit closeInputWindow();
    emit setBarra(QString("Operation done."));
}

bool BasicLogic::checkType(std::string otherType)const{
    return type == otherType;
}

void BasicLogic::results(){
    if(!result){
        throw  QString("ERROR: not result is avalilable.");
    }
    elements->push_back(result->clone());
    delete result;
    result=0;
    AC();
    getElements();
}

void BasicLogic::singleOperation(int index){
    std::string str="ERROR: the operation doesn't exists, index: "+index;
    emit setError(QString(str.c_str()));
}

void BasicLogic::clearKalkElements(){
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if(type == (*cit)->name()){
            delete *cit;
            cit=elements->erase(cit);
            cit--;
        }
        emptyName=0;
    }
    getElements();
}

void BasicLogic::extraoperation(int index){
    emit setError(QString("ERROR: there are not extraoperation available"+index));
}
