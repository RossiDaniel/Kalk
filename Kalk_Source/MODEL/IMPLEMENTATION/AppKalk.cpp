#include "MODEL/HEADER/AppKalk.h"

AppKalk::AppKalk(){
    Uset=new std::list<const numbers*>();

    views.push_back(new SetView());
    views.push_back(new DatasetView());
    views.push_back(new AdvancedView());

    logics.push_back(new SetLogic(Uset));
    logics.push_back(new DatasetLogic(Uset));
    logics.push_back(new AdvancedLogic(Uset));

    container_view= new View(views);
    uni=logics[0];

    connect(container_view,SIGNAL(changelogic(int)),this,SLOT(changeLogic(int)));
    connect(container_view,SIGNAL(cancel()),uni,SLOT(CE()));
    connect(container_view,SIGNAL(selectOperand(QListWidgetItem*)),uni,SLOT(selectOperand(QListWidgetItem*)));
    connect(container_view,SIGNAL(operation(QString)),uni,SLOT(SetOperation(QString)));
    connect(container_view,SIGNAL(singleOperation(QString)),uni,SLOT(singleOperation(QString)));

    connect(uni,SIGNAL(listOfElements(std::list<QString>)),container_view,SLOT(refresh(std::list<QString>)));
    connect(uni,SIGNAL(setBarra(QString)),container_view,SLOT(setBarra(QString)));

    changeLogic(0);
    container_view->show();
}

AppKalk::~AppKalk(){

}

void AppKalk::changeLogic(int index){
    uni=logics[index];
    uni->getElements();
    uni->getNameType();
}


