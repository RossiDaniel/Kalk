#include "MODEL/HEADER/AdvancedLogic.h"

AdvancedLogic::AdvancedLogic(std::list<const numbers*>* l): AbstractLogic(QString("ADVANCED")){
    elements=l;
    operand1=0;
    operand2=0;
    operation=0;
}

AdvancedLogic::~AdvancedLogic(){

}

void AdvancedLogic::SetOperation(QString name){
    if(!operand1){throw QString("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new QString(name);
}
void AdvancedLogic::CE(){
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
void AdvancedLogic::singleOperation(QString){

}

void AdvancedLogic::getElements(){
    std::list<QString> l;
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if(dynamic_cast<const advanced*>(*cit)){
            l.push_back(QString::fromUtf8((*cit)->get_name().c_str()));
        }
    }
    emit listOfElements(l);

}

void AdvancedLogic::selectOperand(QListWidgetItem* element){
    std::string name=element->text().toStdString();
    if(name == "U"){}
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

void AdvancedLogic::SetOperand(std::string name, std::string op){
    std::string str;
        for(std::list<const numbers*>::const_iterator cit=elements->begin(); cit!=elements->end(); cit++){
            if((*cit)->get_name() == name && dynamic_cast<const advanced*>(*cit)){
                if(op == "Operand1"){
                    if(operand1){delete operand1;operand1=0;}
                    operand1 = (*cit)->clone();
                    str= *operand1;
                }
                else{
                    if(operand2){delete operand2;operand2=0;}
                    operand2 = (*cit)->clone();
                    str= *operand2;
                }
            }
        }
        emit setBarra(QString::fromUtf8(str.c_str()));

    }
