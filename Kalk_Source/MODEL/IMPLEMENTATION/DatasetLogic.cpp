#include "MODEL/HEADER/DatasetLogic.h"

DatasetLogic::DatasetLogic(std::list<const numbers*>* l): AbstractLogic(QString("DATASET")){
    elements=l;
    operand1=0;
    operand2=0;
    operation=0;
}

DatasetLogic::~DatasetLogic(){

}

void DatasetLogic::SetOperation(QString name){
    if(!operand1){throw QString("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new QString(name);
}
void DatasetLogic::CE(){
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
void DatasetLogic::singleOperation(QString){

}
void DatasetLogic::getElements(){
    std::list<QString> l;
    for(std::list<const numbers*>::const_iterator cit= elements->begin(); cit!=elements->end(); cit++){
        if(dynamic_cast<const dataset*>(*cit)){
            l.push_back(QString::fromUtf8((*cit)->get_name().c_str()));
        }
    }
    emit listOfElements(l);

}

void DatasetLogic::selectOperand(QListWidgetItem* element){
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

void DatasetLogic::SetOperand(std::string name, std::string op){
    std::string str;
        for(std::list<const numbers*>::const_iterator cit=elements->begin(); cit!=elements->end(); cit++){
            if((*cit)->get_name() == name && dynamic_cast<const dataset*>(*cit)){
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

