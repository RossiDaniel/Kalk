#include"GUI/HEADER/Input.h"

Input::Input(){
    input_view=0;
    isUsed=0;
}

Input::~Input(){

}

void Input::manageInput(int index){
    operation=index;
    ifExistClose();
    configureExtrapanel();
    switch (index) {
        case 0:
            input_view->creaset();
            break;
        case 1:
            input_view->remove();
            break;
        case 2:
            input_view->addelement();
            break;
        case 3:
            input_view->subelement();
            break;
        default:
            std::cout<<index;
    }
    input_view->show();
}

void Input::configureExtrapanel(){
    input_view = new extrapanel();
    connect(input_view,SIGNAL(destroyed()),this,SLOT(unlock()));
    connect(input_view,SIGNAL(DataInput(QString,QString)),this,SLOT(SendDataInput(QString,QString)));
    isUsed=true;

}
void Input::ifExistClose(){
    if(isUsed){
        Disconnect();
        input_view->close();
        delete input_view;
        input_view=0;
        isUsed=false;
    }
}
void Input::unlock(){
    Disconnect();
    input_view=0;
    isUsed=false;
}

void Input::Disconnect(){
    disconnect(input_view,SIGNAL(destroyed()),this,SLOT(unlock()));
    disconnect(input_view,SIGNAL(DataInput(QString,QString)),this,SLOT(SendDataInput(QString,QString)));
}

void Input::SendDataInput(QString name, QString elements){
    emit executeOperation(operation,name,elements);
}

void Input::setErrorInput(QString text){
    std::cout<<"iuppi";
    QMessageBox* ciucia= new QMessageBox();
    ciucia->setText(text);
    ciucia->show();
}
