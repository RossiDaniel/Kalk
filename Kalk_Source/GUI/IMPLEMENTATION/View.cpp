#include "GUI/HEADER/View.h"

View::View(std::vector<KalkMainWindow*>& views){
    setFixedSize(800,320);
    CE = new QPushButton("CE");

    connect (CE, SIGNAL(clicked()), this, SLOT(setCE())) ;

    all=new QHBoxLayout();
    bottom = new QGridLayout();
    right= new QGridLayout();
    left= new QGridLayout();
    Barra= new QTextEdit("Welcome user!");
    errori= new QLineEdit("Errors will be shown here.");
    elenco= new QListWidget();
    elenco->setFixedWidth(200);
    status=new QGridLayout();
    operationArea=new QStackedWidget();
    kalk=new QHBoxLayout();
    Barra->setReadOnly(true);
    errori->setReadOnly(true);

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
    connect (StatussignalMapper, SIGNAL(mapped(int)), this, SIGNAL(changelogic(int)));

    for(unsigned int i=0; i< views.size(); i++){
        operationArea->addWidget(views[i]);
    }

    //barra sulla destra
    right->addWidget(Barra,0,0);
    right->addWidget(CE,1,0);
    right->addWidget(operationArea,2,0);
    right->addWidget(errori, 3,0);

    //barra sulla sinistra
    left->addWidget(elenco);

    //layout generale
    all->addItem(left);
    all->addItem(right);

    kalk->addLayout(all);
    kalk->addLayout(status);
    status->setAlignment(Qt::AlignTop);

    setLayout(kalk);
}

void View::refresh(std::list<QString> l){
    elenco->clear();
    errori->clear();
    for(std::list<QString>::const_iterator cit= l.begin(); cit!=l.end(); cit++){
         elenco->addItem(*cit);
     }
}


void View::setCE(){
    emit cancel();
    Barra->clear();
}
