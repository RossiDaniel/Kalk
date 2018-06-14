#include "MODEL/HEADER/Logic.h"

Logic::Logic(){
    Uset=new std::list<const numbers*>();
    setLogics();
    for(unsigned int i=0; i<logics.size();i++){
        connect(logics[i],SIGNAL(listOfElements(std::list<QString>)),this,SIGNAL(listOfElements(std::list<QString>)));
        connect(logics[i],SIGNAL(setBarra(QString)),this,SIGNAL(setBarra(QString)));
        connect(logics[i],SIGNAL(setError(QString)),this,SIGNAL(setError(QString)));
        connect(logics[i],SIGNAL(setErrorInput(QString)),this,SIGNAL(setErrorInput(QString)));
        connect(logics[i],SIGNAL(closeInputWindow()),this,SIGNAL(closeInputWindow()));
    }
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
    uni->getElements();
}

void Logic::executeOperation(int index,QString name,QString elements){
    try{
    switch (index) {
        case 0:
            uni->add_set(name,elements);
            break;
        case 1:
            uni->sub_set(name,elements);
            break;
        case 2:
            uni->add_elements(name,elements);
            break;
        case 3:
            uni->sub_elements(name,elements);
            break;
        default:
            std::cout<<index;
    }
    }catch(QString q){
        emit setErrorInput(q);
    }
}
