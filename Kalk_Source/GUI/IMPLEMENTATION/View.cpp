#include "GUI/HEADER/View.h"

View::View(){
    status=new QGridLayout();
    operationArea=new QGridLayout();
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

    dataset->hide();

    operationArea->addWidget(set,0,0);
    operationArea->addWidget(dataset,0,0);

    status->setAlignment(Qt::AlignTop);

    kalk->addItem(operationArea);
    kalk->addItem(status);
    setLayout(kalk);
}

void View::selectStatus(QString newStatus){
    if(newStatus == "SET"){
        changeStatus(set);
    }
    if(newStatus == "DATASET"){
        changeStatus(dataset);
    }
    if(newStatus == "ADVANCED"){
        //changeStatus(advaced);
    }
}
void View::changeStatus(KalkMainWindow* newStatus){
    KalkMainWindow* oldStatus=currentType;
    currentType=newStatus;
    currentType->setHidden(false);
    oldStatus->hide();
}

