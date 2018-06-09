#include "MODEL/HEADER/app.h"
#include "GUI/HEADER/datasetview.h"
AppKalk::AppKalk(){
    view= new View();
    view->show();
    uni =new SetLogic();
    Uset.push_back(new set("U"));
    //QObject::connect(view, SIGNAL(valueChanged()), uni, SLOT(printValue()));
    //QObject::connect(view, SIGNAL(StatusChange(QString)), this, SLOT(selectStatus(QString)));

}

AppKalk::~AppKalk(){

}
