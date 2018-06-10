#include "MODEL/HEADER/app.h"
#include "GUI/HEADER/datasetview.h"
AppKalk::AppKalk(){
    Uset=new std::list<const numbers*>();

    views.push_back(new SetView());
    views.push_back(new DatasetView());
    views.push_back(new AdvancedView());

    logics.push_back(new SetLogic(Uset));
    logics.push_back(new DatasetLogic(Uset));
    logics.push_back(new AdvancedLogic(Uset));

    container_view= new View(views);
    container_view->show();
    uni=logics[0];
    connect(container_view,SIGNAL(changelogic(int)),this,SLOT(changeLogic(int)));

    for(unsigned int i=0; i<views.size(); i++){
        connect(views[i],SIGNAL(operation(QString)),uni,SLOT(SetOperation(QString)));
        connect(views[i],SIGNAL(singleOperation(QString)),uni,SLOT(singleOperation(QString)));
        connect(views[i],SIGNAL(CE()),uni,SLOT(CE()));

    }/*
    void input(QString);
    void CE();
    void singleOperation(QString);
    void multiOperation(QString);
    void result();*/
}

AppKalk::~AppKalk(){

}

void AppKalk::changeLogic(int index){
    uni=logics[index];
    std::cout<<"iuuuu"<<std::endl;
}
