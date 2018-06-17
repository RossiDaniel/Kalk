#include "GUI/HEADER/datasetview.h"

DatasetView::DatasetView(){

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

    buttonLayout= new QGridLayout();

    unsigned int row=1;
    for(unsigned int button=0; button<Operationkeyboard.size();button++){
        if(button == row*4){row++;}
        buttonLayout->addWidget(Operationkeyboard[button],row,(button%4)+1);
    }

    buttonLayout->setAlignment(Qt::AlignTop);
    setLayout(buttonLayout);
}

DatasetView::~DatasetView(){

}

std::vector<QString> DatasetView::getSingleOperationkeyboard(){
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Somme");
    VofButtonName.push_back("Size");
    VofButtonName.push_back("Average");
    VofButtonName.push_back("GL");
    VofButtonName.push_back("Variance");
    VofButtonName.push_back("DS");
    VofButtonName.push_back("Deviance");
    VofButtonName.push_back("Deviation");
    VofButtonName.push_back("Deviation^2");

    return VofButtonName;
}

std::vector<QString> DatasetView::getMultiOperationkeyboard(){
    std::vector<QString> VofButtonName;
    return VofButtonName;
}

std::vector<QString> DatasetView::getExtraOperationkeyboard(){
    std::vector<QString> VofButtonName;
    return VofButtonName;
}
