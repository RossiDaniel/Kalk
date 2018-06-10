#include "GUI/HEADER/View.h"

View::View(std::vector<KalkMainWindow*>& views){
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

    StatussignalMapper -> setMapping (StatusSet, 0);
    StatussignalMapper -> setMapping (StatusDataset, 1);
    StatussignalMapper -> setMapping (StatusAdvanced, 2);

    connect (StatussignalMapper, SIGNAL(mapped(int)), operationArea, SLOT(setCurrentIndex(int)));

    for(unsigned int i=0; i< views.size(); i++){
        operationArea->addWidget(views[i]);
    }


    status->setAlignment(Qt::AlignTop);

    kalk->addWidget(operationArea);
    kalk->addLayout(status);
    setLayout(kalk);
}


