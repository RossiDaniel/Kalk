#include "MODEL/HEADER/basiclogic.h"
BasicLogic::BasicLogic(QString name, std::string tname, std::list<const numbers*>* l): nameType(name),type(tname),elements(l) {}
BasicLogic::~BasicLogic(){}
void BasicLogic::getNameType(){
    emit setBarra(QString("Kalk is set on "+nameType+" type."));
}

void BasicLogic::getElements(){
    std::list<QString> l;
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        std::cout<<type<<" "<<(*cit)->name()<<std::endl;
        if(type == (*cit)->name()){
            l.push_back(QString::fromUtf8((*cit)->get_name().c_str()));
        }
    }
    emit listOfElements(l);
}

void BasicLogic::CE(){
    if(operand1){
        delete operand1;operand1=0;
    }
    if(operand2){
        delete operand2;operand2=0;
    }
    if(operation){
        delete operation;operation=0;
    }
}

void BasicLogic::selectOperand(QListWidgetItem* element){
    std::string name=element->text().toStdString();
    if(!operand1){
        return SetOperand(name,"Operand1");
    }
    else{
        if(!operation){
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
                str=*operand1;
            }
        }
    }
    emit setBarra(QString::fromUtf8(str.c_str()));
}

void BasicLogic::SetOperation(QString name){
    if(!operand1){throw QString("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new QString(name);
}

void BasicLogic::sub_set(QString name, QString data){
    bool sent=false;
    for(std::list<const numbers*>::const_iterator cit=elements->begin(); !sent && cit!=elements->end(); cit++){
        if(type == (*cit)->name() && (*cit)->get_name() == name.toStdString()){
            sent =true;
            delete *cit;
            cit=elements->erase(cit);
        }
    }
    if(!sent){throw QString("The element you want to delete doesn't exist.");}
}

void BasicLogic::update(){
    getElements();
    emit closeInputWindow();
    emit setBarra(QString("Operation done."));
}
