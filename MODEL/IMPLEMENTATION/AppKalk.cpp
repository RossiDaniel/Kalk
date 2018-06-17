#include "MODEL/HEADER/AppKalk.h"

AppKalk::AppKalk(){
    logic= new Logic();
    container_view= new View(logic->nameType());
    input_manage= new Input();

    connect(container_view,SIGNAL(changelogic(int)),logic,SLOT(changeLogic(int)));
    connect(container_view,SIGNAL(cancel()),logic,SLOT(CE()));
    connect(container_view,SIGNAL(selectOperand(QListWidgetItem*)),logic,SLOT(selectOperand(QListWidgetItem*)));
    connect(container_view,SIGNAL(operation(int)),logic,SLOT(SetOperation(int)));
    connect(container_view,SIGNAL(singleOperation(int)),logic,SLOT(singleOperation(int)));
    connect(container_view,SIGNAL(input(int)),input_manage,SLOT(manageInput(int)));
    connect(container_view,SIGNAL(result()),logic,SLOT(result()));
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
    disconnect(container_view,SIGNAL(changelogic(int)),logic,SLOT(changeLogic(int)));
    disconnect(container_view,SIGNAL(cancel()),logic,SLOT(CE()));
    disconnect(container_view,SIGNAL(selectOperand(QListWidgetItem*)),logic,SLOT(selectOperand(QListWidgetItem*)));
    disconnect(container_view,SIGNAL(operation(int)),logic,SLOT(SetOperation(int)));
    disconnect(container_view,SIGNAL(singleOperation(int)),logic,SLOT(singleOperation(int)));
    disconnect(container_view,SIGNAL(input(int)),input_manage,SLOT(manageInput(int)));
    disconnect(container_view,SIGNAL(result()),logic,SLOT(result()));
    disconnect(container_view,SIGNAL(clearKalkElements()),logic,SLOT(clearKalkElements()));
    disconnect(container_view,SIGNAL(CloseIfExist()),input_manage,SLOT(ifExistClose()));

    disconnect(input_manage,SIGNAL(executeOperation(int,QString,QString)),logic,SLOT(executeOperation(int,QString,QString)));

    disconnect(logic,SIGNAL(listOfElements(std::list<QString>)),container_view,SLOT(refresh(std::list<QString>)));
    disconnect(logic,SIGNAL(setBarra(QString)),container_view,SLOT(setBarra(QString)));
    disconnect(logic,SIGNAL(setError(QString)),container_view,SLOT(setError(QString)));
    disconnect(logic,SIGNAL(setErrorInput(QString)),input_manage,SLOT(setErrorInput(QString)));
    disconnect(logic, SIGNAL(closeInputWindow()),input_manage,SLOT(ifExistClose()));

    delete logic;
    delete container_view;
    delete input_manage;
}

void AppKalk::configure(){
    logic->changeLogic(0);
    container_view->changePallet(0);
    container_view->show();
}

