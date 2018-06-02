#include "MODEL/HEADER/app.h"
#include "GUI/HEADER/datasetview.h"
AppKalk::AppKalk(){
    view=new SetView();
    view_general= new GeneralView(view);

    uni =new SetLogic();
    Uset.push_back(new set("U"));
    QObject::connect(view, SIGNAL(valueChanged()), uni, SLOT(printValue()));
    QObject::connect(view, SIGNAL(StatusChange(QString)), this, SLOT(selectStatus(QString)));

}

AppKalk::~AppKalk(){

}

void AppKalk::selectStatus(QString str){

    if(str == "SET"){
        changeStatus(new SetView(), new SetLogic());
    std::cout<<"set";
    }
    if(str == "DATASET"){
        changeStatus(new SetView(), new DatasetLogic());
        std::cout<<"dataset";
    }
}

void AppKalk::changeStatus(KalkMainWindow* newView, AbstractLogic* newlogic){

    //QLayout* old =view_general->layout();
    //delete old;
    view_general->setUpdatesEnabled(true);

    view_general->setLayout(newView);
    view_general->setUpdatesEnabled(false);
    view=newView;
    uni=newlogic;
}
