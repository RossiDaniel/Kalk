#include "MODEL/HEADER/AppKalk.h"

AppKalk::AppKalk(){
    logic= new Logic();
    container_view= new View(logic->nameType());
    input_manage= new Input();

    connect(container_view,SIGNAL(changelogic(int)),logic,SLOT(changeLogic(int)));
    connect(container_view,SIGNAL(cancel()),logic,SLOT(AC()));
    connect(container_view,SIGNAL(selectOperand(QListWidgetItem*)),logic,SLOT(selectOperand(QListWidgetItem*)));
    connect(container_view,SIGNAL(multioperation(int)),logic,SLOT(multioperation(int)));
    connect(container_view,SIGNAL(singleOperation(int)),logic,SLOT(singleOperation(int)));
    connect(container_view,SIGNAL(input(int)),input_manage,SLOT(manageInput(int)));
    connect(container_view,SIGNAL(clearKalkElements()),logic,SLOT(clearKalkElements()));
    connect(container_view,SIGNAL(CloseIfExist()),input_manage,SLOT(ifExistClose()));
    connect(container_view,SIGNAL(extraoperation(int)),logic,SLOT(extraoperation(int)));

    connect(input_manage,SIGNAL(executeOperation(int,QString,QString)),logic,SLOT(executeOperation(int,QString,QString)));

    connect(logic,SIGNAL(listOfElements(std::list<QString>)),container_view,SLOT(refresh(std::list<QString>)));
    connect(logic,SIGNAL(setBarra(QString)),container_view,SLOT(setBarra(QString)));
    connect(logic,SIGNAL(setError(QString)),container_view,SLOT(setError(QString)));
    connect(logic,SIGNAL(setErrorInput(QString)),input_manage,SLOT(setErrorInput(QString)));
    connect(logic, SIGNAL(closeInputWindow()),input_manage,SLOT(ifExistClose()));

    connect(this,SIGNAL(destroyed()),this,SLOT(close()));

    this->setAttribute(Qt::WA_DeleteOnClose);
}

AppKalk::~AppKalk(){
    delete logic;
    delete container_view;
    delete input_manage;
}

void AppKalk::configure(){
    logic->changeLogic(0);
    container_view->changePallet(0);
    container_view->show();
}

