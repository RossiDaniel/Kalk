#include "MODEL/HEADER/Logic.h"

Logic::Logic(){
    Uset=new std::list<const numbers*>();
    setLogics();
    for(unsigned int i=0; i<logics.size();i++){
    connect(logics[i],SIGNAL(listOfElements(std::list<QString>)),this,SIGNAL(listOfElements(std::list<QString>)));
    connect(logics[i],SIGNAL(setBarra(QString)),this,SIGNAL(setBarra(QString)));
    }
    uni=logics[0];
}

Logic::~Logic(){

}

void Logic::setLogics(){
    logics.push_back(new SetLogic(Uset));
    logics.push_back(new DatasetLogic(Uset));
    logics.push_back(new AdvancedLogic(Uset));
}

void Logic::CE(){
    uni->CE();
}

void Logic::SetOperation(QString q){
    uni->SetOperation(q);
}

void Logic::singleOperation(QString q){
    uni->singleOperation(q);
}

void Logic::selectOperand(QListWidgetItem* item){
    uni->selectOperand(item);
}

void Logic::changeLogic(int index){
    uni=logics[index];
    uni->getNameType();
}
