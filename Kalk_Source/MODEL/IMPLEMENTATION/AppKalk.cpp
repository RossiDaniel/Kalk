#include "MODEL/HEADER/AppKalk.h"

AppKalk::AppKalk(){
    container_view= new View();
    logic= new Logic();

    connect(container_view,SIGNAL(changelogic(int)),logic,SLOT(changeLogic(int)));
    connect(container_view,SIGNAL(cancel()),logic,SLOT(CE()));
    connect(container_view,SIGNAL(selectOperand(QListWidgetItem*)),logic,SLOT(selectOperand(QListWidgetItem*)));
    connect(container_view,SIGNAL(operation(QString)),logic,SLOT(SetOperation(QString)));
    connect(container_view,SIGNAL(singleOperation(QString)),logic,SLOT(singleOperation(QString)));

    connect(logic,SIGNAL(listOfElements(std::list<QString>)),container_view,SLOT(refresh(std::list<QString>)));
    connect(logic,SIGNAL(setBarra(QString)),container_view,SLOT(setBarra(QString)));

    container_view->show();
}

AppKalk::~AppKalk(){

}
