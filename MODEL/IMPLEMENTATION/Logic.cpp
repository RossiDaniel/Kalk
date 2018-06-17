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

void Logic::SetOperation(int index){
    std::cout<<index;
    uni->SetOperation(index);
}

void Logic::singleOperation(int index){
    try{
        uni->singleOperation(index);
    }
    catch(QString q){
        emit setError(q);
    }
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
            uni->sub_set(name);
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

void Logic::result(){
    try{
        uni->results();
    }
    catch(QString q){
        emit setError(q);
    }
}

std::vector<QString> Logic::nameType()const{
    std::vector<QString> v;
    for(unsigned int i=0; i<logics.size();i++){
        v.push_back(logics[i]->getNameType());
    }
    return v;
}

void Logic::clearKalkElements(){
    uni->clearKalkElements();
}
