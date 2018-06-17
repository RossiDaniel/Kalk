#include "GUI/HEADER/setview.h"

SetView::SetView(){

    std::vector<QString> multiName =getMultiOperationkeyboard();
    MultiOperationsignalMapper = new QSignalMapper (this) ;

    for(unsigned int i=0; i<multiName.size();i++){
        Operationkeyboard.push_back(new QPushButton(multiName[i]));
        connect (Operationkeyboard.back(), SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        MultiOperationsignalMapper -> setMapping (Operationkeyboard.back(), i) ;
    }

    connect(MultiOperationsignalMapper, SIGNAL(mapped(int)), this, SIGNAL(operation(int))) ;

    std::vector<QString> singleName =getSingleOperationkeyboard();
    SingleOperationsignalMapper = new QSignalMapper (this) ;

    for(unsigned int i=0; i<singleName.size();i++){
        Operationkeyboard.push_back(new QPushButton(singleName[i]));
        connect (Operationkeyboard.back(), SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        SingleOperationsignalMapper -> setMapping (Operationkeyboard.back(), i) ;
    }

    connect(SingleOperationsignalMapper, SIGNAL(mapped(int)), this, SIGNAL(singleOperation(int)));

    std::vector<QString> extraName =getExtraOperationkeyboard();
    ExtraOperationsignalMapper = new QSignalMapper (this) ;

    for(unsigned int i=0; i<extraName.size();i++){
        Operationkeyboard.push_back(new QPushButton(extraName[i]));
        connect (Operationkeyboard.back(), SIGNAL(clicked()), ExtraOperationsignalMapper, SLOT(map())) ;
        ExtraOperationsignalMapper -> setMapping (Operationkeyboard.back(), i) ;
    }

    connect(ExtraOperationsignalMapper, SIGNAL(mapped(int)), this, SIGNAL(extraoperation(int))) ;

    QPushButton* result= new QPushButton("=");
    connect(result,SIGNAL(clicked(bool)),this,SIGNAL(result()));
    Operationkeyboard.push_back(result);

    buttonLayout= new QGridLayout();

    unsigned int row=1;
    for(unsigned int button=0; button<Operationkeyboard.size();button++){
        if(button == row*4){row++;}
        buttonLayout->addWidget(Operationkeyboard[button],row,(button%4)+1);
    }

    buttonLayout->setAlignment(Qt::AlignTop);
    setLayout(buttonLayout);
}
SetView::~SetView(){}

std::vector<QString> SetView::getSingleOperationkeyboard(){
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Complement");
    VofButtonName.push_back("PowerSet()");
    return VofButtonName;
}

std::vector<QString> SetView::getMultiOperationkeyboard(){
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Union");
    VofButtonName.push_back("Intercetion");
    VofButtonName.push_back("Difference");
    VofButtonName.push_back("SymmetricalDif.");
    VofButtonName.push_back("CartesianProd");
    return VofButtonName;
}

std::vector<QString> SetView::getExtraOperationkeyboard(){
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Save");
    return VofButtonName;
}
