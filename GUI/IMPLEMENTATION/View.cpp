#include "GUI/HEADER/View.h"

View::View(std::vector<QString> v){

    setFixedSize(900,400);
    currentStatus=0;

    QPushButton* AC = new QPushButton("AC");
    QPushButton* clearKalk = new QPushButton("ClearKalk");
    QHBoxLayout* all=new QHBoxLayout();
    QGridLayout* inputButtonGrid=new QGridLayout();
    QGridLayout* right= new QGridLayout();
    QGridLayout* left= new QGridLayout();
    Barra= new QTextEdit();
    errori= new QLineEdit();
    elenco= new QListWidget();
    QStackedWidget* operationArea=new QStackedWidget();
    QGridLayout* status=new QGridLayout();
    QSignalMapper* StatusSignalMapper = new QSignalMapper();
    QSignalMapper* InputSignalMapper = new QSignalMapper();
    std::vector<QString> inputButtonName=getBasicOperation();
    std::vector<QPushButton*> inputButton;

    pal = new QPalette();
    kalk=new QHBoxLayout();

    elenco->setFixedWidth(200);

    connect (AC, SIGNAL(clicked()), this, SLOT(setAC())) ;
    connect (clearKalk, SIGNAL(clicked()), this, SIGNAL(clearKalkElements())) ;
    connect (clearKalk, SIGNAL(clicked()), this, SLOT(clear())) ;
    connect (elenco, SIGNAL(itemClicked(QListWidgetItem*)), this, SIGNAL(selectOperand(QListWidgetItem*)));

    for(unsigned int i=0; i<v.size(); i++){
        statusButton.push_back(new QPushButton(v[i]));
        status->addWidget(statusButton[i],i,1);
        connect(statusButton[i],SIGNAL(clicked()),this,SIGNAL(CloseIfExist()));
        connect (statusButton[i], SIGNAL(clicked()), StatusSignalMapper, SLOT(map())) ;
        StatusSignalMapper -> setMapping (statusButton[i], i);
    }

    connect (StatusSignalMapper, SIGNAL(mapped(int)), operationArea, SLOT(setCurrentIndex(int)));
    connect (StatusSignalMapper, SIGNAL(mapped(int)), this, SIGNAL(changelogic(int)));
    connect (StatusSignalMapper, SIGNAL(mapped(int)), this, SLOT(changePallet(int)));

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

    pal->setColor(QPalette::Button, QColor(Qt::gray));

    Barra->setReadOnly(true);
    errori->setReadOnly(true);

    setViews();
    for(unsigned int i=0; i< views.size(); i++){
        operationArea->addWidget(views[i]);
        connect(views[i],SIGNAL(multioperation(int)),this,SIGNAL(multioperation(int)));
        connect(views[i],SIGNAL(singleOperation(int)),this,SIGNAL(singleOperation(int)));
        connect(views[i],SIGNAL(extraoperation(int)),this,SIGNAL(extraoperation(int)));
    }

    //barra sulla destra
    right->addWidget(Barra,0,0);
    right->addWidget(AC,1,0);
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
    delete kalk;
}

void View::refresh(std::list<QString> l){
    elenco->clear();
    errori->clear();
    for(std::list<QString>::const_iterator cit= l.begin(); cit!=l.end(); cit++){
         elenco->addItem(*cit);
     }
}


void View::setAC(){
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
    views.push_back(new SetKeyboard());
    views.push_back(new DatasetKeyboard());
    views.push_back(new AdvancedKeyboard());

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
    clear();
    Barra->setText(QString("Change type done."));
}

std::vector<QString> View::getBasicOperation()const{
    std::vector<QString> inputButtonName;
    inputButtonName.push_back("Create");
    inputButtonName.push_back("Delete");
    inputButtonName.push_back("Add");
    inputButtonName.push_back("Sub");
    return inputButtonName;
}
