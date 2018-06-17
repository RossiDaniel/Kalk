#include "GUI/HEADER/View.h"

View::View(std::vector<QString> v){

    setFixedSize(800,320);
    currentStatus=0;

    CE = new QPushButton("CE");
    clearKalk = new QPushButton("ClearKalk");

    connect (CE, SIGNAL(clicked()), this, SLOT(setCE())) ;
    connect (clearKalk, SIGNAL(clicked()), this, SIGNAL(clearKalkElements())) ;

    all=new QHBoxLayout();
    inputButtonGrid=new QGridLayout();
    bottom = new QGridLayout();
    right= new QGridLayout();
    left= new QGridLayout();
    Barra= new QTextEdit();
    errori= new QLineEdit("Errors will be shown here.");
    elenco= new QListWidget();
    elenco->setFixedWidth(200);

    connect (elenco, SIGNAL(itemClicked(QListWidgetItem*)), this, SIGNAL(selectOperand(QListWidgetItem*)));

    operationArea=new QStackedWidget();
    status=new QGridLayout();
    StatusSignalMapper = new QSignalMapper();
    InputSignalMapper = new QSignalMapper();
    for(unsigned int i=0; i<v.size(); i++){
        statusButton.push_back(new QPushButton(v[i]));
        status->addWidget(statusButton[i],i,1);
        connect (statusButton[i], SIGNAL(clicked()), StatusSignalMapper, SLOT(map())) ;
        StatusSignalMapper -> setMapping (statusButton[i], i);
    }

    connect (StatusSignalMapper, SIGNAL(mapped(int)), operationArea, SLOT(setCurrentIndex(int)));
    connect (StatusSignalMapper, SIGNAL(mapped(int)), this, SIGNAL(changelogic(int)));
    connect (StatusSignalMapper, SIGNAL(mapped(int)), this, SLOT(changePallet(int)));

    std::vector<QString> inputButtonName;
    inputButtonName.push_back("Create");
    inputButtonName.push_back("Delete");
    inputButtonName.push_back("Add");
    inputButtonName.push_back("Sub");

    for(unsigned int i=0; i<inputButtonName.size(); i++){
        inputButton.push_back(new QPushButton(inputButtonName[i]));
        connect(inputButton[i],SIGNAL(clicked()),InputSignalMapper,SLOT(map()));
        InputSignalMapper->setMapping(inputButton[i],i);
        inputButtonGrid->addWidget(inputButton[i],1,i);
    }

    inputButtonGrid->setAlignment(Qt::AlignTop);
    inputButtonGrid->setMargin(5);
    inputButtonGrid->setSpacing(5);

    connect(InputSignalMapper,SIGNAL(mapped(int)),this,SIGNAL(input(int)));

    pal = new QPalette();
    pal->setColor(QPalette::Button, QColor(Qt::gray));

    kalk=new QHBoxLayout();
    Barra->setReadOnly(true);
    errori->setReadOnly(true);

    setViews();
    for(unsigned int i=0; i< views.size(); i++){
        operationArea->addWidget(views[i]);
        connect(views[i],SIGNAL(operation(int)),this,SIGNAL(operation(int)));
        connect(views[i],SIGNAL(singleOperation(int)),this,SIGNAL(singleOperation(int)));
        connect(views[i],SIGNAL(input(int)),this,SIGNAL(input(int)));
        connect(views[i],SIGNAL(result()),this,SIGNAL(result()));
    }

    //barra sulla destra
    right->addWidget(Barra,0,0);
    right->addWidget(CE,1,0);
    right->addWidget(clearKalk,2,0);
    right->addLayout(inputButtonGrid,3,0);
    right->addWidget(operationArea,4,0);
    right->addWidget(errori, 5,0);
    right->setMargin(5);
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

View::~View(){

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
    clear();
}

void View::setBarra(QString text){
    clear();
    Barra->setText(text);
}

void View::setError(QString text){
    clear();
    errori->setText(text);
}

void View::setViews(){
    views.push_back(new SetView());
    views.push_back(new DatasetView());
    views.push_back(new AdvancedView());

}

void View::clear(){
    Barra->clear();
    errori->clear();
}

void View::changePallet(int index){
    statusButton[currentStatus]->setPalette(statusButton[currentStatus]->style()->standardPalette());
    statusButton[index]->setAutoFillBackground(true);
    statusButton[index]->setPalette(*pal);
    statusButton[index]->update();
    statusButton[index]->setAutoFillBackground(false);
    currentStatus=index;
}
