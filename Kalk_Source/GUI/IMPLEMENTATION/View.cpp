#include "GUI/HEADER/View.h"

View::View(){
    status=new QGridLayout();
    operationArea=new QStackedWidget();
    kalk=new QHBoxLayout();

    StatusSet= new QPushButton("SET");
    StatusDataset =new QPushButton("DATASET");
    StatusAdvanced= new QPushButton("ADVANCED");

    status->addWidget(StatusSet,1,1);
    status->addWidget(StatusDataset,2,1);
    status->addWidget(StatusAdvanced,3,1);

    StatussignalMapper = new QSignalMapper();
    connect (StatusSet, SIGNAL(clicked()), StatussignalMapper, SLOT(map())) ;
    connect (StatusDataset, SIGNAL(clicked()), StatussignalMapper, SLOT(map())) ;
    connect (StatusAdvanced, SIGNAL(clicked()), StatussignalMapper, SLOT(map())) ;

    StatussignalMapper -> setMapping (StatusSet, "SET");
    StatussignalMapper -> setMapping (StatusDataset, "DATASET");
    StatussignalMapper -> setMapping (StatusAdvanced, "ADVANCED");

    connect (StatussignalMapper, SIGNAL(mapped(QString)), this, SLOT(selectStatus(QString))) ;
    set=new SetView();
    dataset= new DatasetView();
    currentType=set;
    operationArea->addWidget(set);
    operationArea->addWidget(dataset);

    status->setAlignment(Qt::AlignTop);

    kalk->addWidget(operationArea);
    kalk->addLayout(status);
    setLayout(kalk);
}

void View::selectStatus(QString newStatus){
    if(newStatus == "SET"){
        operationArea->setCurrentIndex(0);
    }
    if(newStatus == "DATASET"){
        operationArea->setCurrentIndex(1);
    }
    if(newStatus == "ADVANCED"){
        //changeStatus(advaced);
    }
}
void View::changeStatus(KalkMainWindow* newStatus){
    currentType=newStatus;
    std::cout<<"ciucia";
    operationArea->update() ;
}

