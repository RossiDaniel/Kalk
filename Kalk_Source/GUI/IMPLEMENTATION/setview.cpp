#include "GUI/HEADER/setview.h"

SetView::SetView(){
    setFixedSize(800,320);

    CE = new QPushButton("CE");
    int n=5;
    connect(CE, SIGNAL(clicked(bool)), this, SLOT(setValue(n)));
    QLabel* typestatus= new QLabel("Status Attuale: ");
    Status = new QLabel("SET");
    StatusSet= new QPushButton("SET");
    StatusDataset =new QPushButton("DATASET");
    StatusAdvanced= new QPushButton("ADVANCED");

    StatussignalMapper = new QSignalMapper (this) ;


    StatussignalMapper -> setMapping (StatusSet, "set") ;
    StatussignalMapper -> setMapping (StatusDataset, "dataset") ;
    StatussignalMapper -> setMapping (StatusAdvanced, "advanced") ;


    Button1 =new QPushButton("Create Set");
    Button2 =new QPushButton("Delete Set");
    Button3 =new QPushButton("Clear Kalk");
    Button4 =new QPushButton("Save Result");
    Button5 =new QPushButton("Insert Number");
    Button6 =new QPushButton("Delete Number");
    Button7 =new QPushButton("Union");
    Button8= new QPushButton("Intercetion");
    Button9 =new QPushButton("Difference");
    Button10 =new QPushButton("Complement");
    Button11= new QPushButton("SymmetricalDif.");
    Button12= new QPushButton("CartesianProd");
    Button13= new QPushButton("PowerSet()");
    Button14=new QPushButton("=");

    InputsignalMapper = new QSignalMapper (this) ;


    InputsignalMapper -> setMapping (Button1, "New") ;
    InputsignalMapper -> setMapping (Button2, "Remove") ;
    InputsignalMapper -> setMapping (Button5, "AddElement") ;
    InputsignalMapper -> setMapping (Button6, "SubElement") ;



    SingleOperationsignalMapper = new QSignalMapper (this) ;

    SingleOperationsignalMapper -> setMapping (Button13, "powerset") ;
    SingleOperationsignalMapper -> setMapping (Button10, "complement") ;



    MultiOperationsignalMapper = new QSignalMapper (this) ;



    MultiOperationsignalMapper -> setMapping (Button7, "union") ;
    MultiOperationsignalMapper -> setMapping (Button8, "intercetion") ;
    MultiOperationsignalMapper -> setMapping (Button9, "difference") ;
    MultiOperationsignalMapper -> setMapping (Button11, "symmetricaldifference") ;
    MultiOperationsignalMapper -> setMapping (Button12, "cartesianproduct") ;




    all=new QHBoxLayout();
    StatusGrid =new QGridLayout();
    bottom = new QGridLayout();
    buttonLayout= new QGridLayout();
    right= new QGridLayout();
    left= new QGridLayout();
    Barra= new QTextEdit("Welcome user!");
    errori= new QLineEdit("Errors will be shown here.");
    elenco= new QListWidget();
    elenco->setFixedWidth(200);

    buttonLayout->addWidget(CE,0,1);
    buttonLayout->addWidget(Button1,1,1);
    buttonLayout->addWidget(Button2,1,2);
    buttonLayout->addWidget(Button3,1,3);
    buttonLayout->addWidget(Button4,1,4);
    buttonLayout->addWidget(Button5,2,1);
    buttonLayout->addWidget(Button6,2,2);
    buttonLayout->addWidget(Button7,2,3);
    buttonLayout->addWidget(Button8,2,4);
    buttonLayout->addWidget(Button9,3,1);
    buttonLayout->addWidget(Button10,3,2);
    buttonLayout->addWidget(Button11,3,3);
    buttonLayout->addWidget(Button12,3,4);
    buttonLayout->addWidget(Button13,4,1);
    buttonLayout->addWidget(Button14,4,2);
    buttonLayout->addWidget(typestatus,4,3);
    buttonLayout->addWidget(Status,4,4);

    bottom->addWidget(StatusSet,1,1);
    bottom->addWidget(StatusDataset,2,1);
    bottom->addWidget(StatusAdvanced,3,1);

    StatusGrid->addItem(bottom,0,0);
    Barra->setReadOnly(true);
    errori->setReadOnly(true);

    //barra sulla destra
    right->addWidget(Barra,0,0);
    right->addLayout(buttonLayout,1,0);
    right->addWidget(errori, 2,0);

    //barra sulla sinistra
    left->addWidget(elenco);

    //layout generale
    all->addItem(left);
    all->addItem(right);
    all->addItem(StatusGrid);

    buttonLayout->setAlignment(Qt::AlignTop);
    StatusGrid->setAlignment(Qt::AlignTop);
    //this->refresh();
    this->setLayout(all);
}
SetView::~SetView(){
    delete right;
    delete left;
    delete all;
    delete buttonLayout;
    delete bottom;
    delete StatusGrid;

    delete StatussignalMapper;
    delete InputsignalMapper;
    delete SingleOperationsignalMapper;
    delete MultiOperationsignalMapper;

    delete StatusSet;
    delete StatusDataset;
    delete StatusAdvanced;
    delete Status;

    delete Button1;
    delete Button2;
    delete Button3;
    delete Button4;
    delete Button5;
    delete Button6;

    delete Button7;
    delete Button8;
    delete Button9;
    delete Button10;
    delete Button11;
    delete Button12;
    delete Button13;
    delete Button14;

    delete Barra;
    delete errori;
    delete elenco;
}

void SetView::setValue(int value){
    emit valueChanged(value);
}
/*
void KalkMainWindow::openExtraPanel(QString q){
    extrapanel* panel=new extrapanel(this,q);
    panel->show();
}


void KalkMainWindow::refresh(){
    elenco->clear();
    errori->clear();
     std::list<std::string> l =uni->ListNumbers();
     for(std::list<std::string>::const_iterator cit= l.begin(); cit!=l.end(); cit++){
         const char *c = (*cit).c_str();
         QString q(c);
         elenco->addItem(q);
     }
}

void KalkMainWindow::add_set(const numbers& s){
    uni->add_set(s);
}
void KalkMainWindow::sub_set(const std::string s){
    uni->sub_set(s);
    this->refresh();
    Barra->clear();
    errori->clear();
}
void KalkMainWindow::add_elements(const std::string name, const std::list<int>& l)const{
    uni->add_elements(name,l);
}

void KalkMainWindow::sub_elements(const std::string name, const std::list<int>& l)const{
    uni->sub_elements(name,l);
}

void KalkMainWindow::selectoperand(QListWidgetItem* item){
    QString Stditem=item->text();
    QString q;
    try{
        std::string s =uni->SetValue(Stditem.toStdString());
        q=QString::fromStdString(s);
        Barra->clear();
        errori->clear();
        Barra->setText(q);
    }
    catch(std::string ex){
        q=QString::fromStdString(ex);
        Barra->clear();
        Barra->setText(q);
        errori->clear();
        errori->insert("ERRORE : non puoi fare operazioni con l'insieme U");
    }
}
void KalkMainWindow::SetOperation(QString q){
    try{
        uni->SetOperation(q.toStdString());
        errori->clear();
    }
    catch(std::string ex){
        errori->clear();
        QString qst = QString::fromStdString(ex);
        errori->insert(qst);
    }
}
std::list<std::string> KalkMainWindow::getListOfSet()const{
    return uni->ListNumbers();
}

QString KalkMainWindow::status()const{
    return QString::fromStdString(uni->getStatus());
}

void KalkMainWindow::clearElenco(){
    uni->clear();
    errori->clear();
    Barra->clear();
    Barra->setText("Pulizia eseguita con successo!");
    this->refresh();
}

void KalkMainWindow::multiOperation(){
    try{
        QString q =QString::fromStdString(uni->multiOperation());
        Barra->clear();
        errori->clear();
        Barra->setText(q);
    }
    catch(std::string ex){
        QString Qex =QString::fromStdString(ex);
        Barra->clear();
        errori->clear();
        errori->insert(Qex);
    }
}

void KalkMainWindow::singleOperation(QString q){
    try{
        this->SetOperation(q);
        QString q =QString::fromStdString(uni->singleOperation());
        Barra->clear();
        errori->clear();
        Barra->setText(q);
    }
    catch(std::string ex){
        QString Qex =QString::fromStdString(ex);
        Barra->clear();
        errori->clear();
        errori->insert(Qex);
    }
}

void KalkMainWindow::save(){
    try{
        uni->SaveResult();
        this->refresh();
    }
    catch(std::string ex){
        QString Qex =QString::fromStdString(ex);
        Barra->clear();
        errori->clear();
        errori->insert(Qex);
    }
}

dataset* KalkMainWindow::getDataset(std::string name) const{
    return uni->getDataset(name);
}

void KalkMainWindow::changeStatus(QString q){
    if(uni->getStatus() == "set"){
        disconnect (Button1, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button2, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button5, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button6, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button13, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button10, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button7, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button8, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button9, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button11, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button12, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;

        disconnect (Button3,SIGNAL(clicked()),this,SLOT(clearElenco()));
        disconnect (Button4,SIGNAL(clicked()),this,SLOT(save()));

        disconnect (SingleOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(singleOperation(QString)));
        disconnect (InputsignalMapper, SIGNAL(mapped(QString)), this, SLOT(openExtraPanel(QString))) ;
        disconnect (MultiOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(SetOperation(QString)));

        delete SingleOperationsignalMapper;
        delete MultiOperationsignalMapper;
        delete InputsignalMapper;
        uni->resetkalk();

    }
    if(uni->getStatus() == "dataset"){
        disconnect (Button1, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button2, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button4,SIGNAL(clicked()),InputsignalMapper,SLOT(map()));
        disconnect (Button5, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button6, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button13, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button10, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button7, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button8, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button9, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button11, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button12, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        disconnect (Button3,SIGNAL(clicked()),this,SLOT(clearElenco()));

        disconnect (SingleOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(singleOperation(QString)));
        disconnect (InputsignalMapper, SIGNAL(mapped(QString)), this, SLOT(openExtraPanel(QString))) ;
        disconnect (MultiOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(SetOperation(QString)));

        Button14->setVisible(true);

        delete SingleOperationsignalMapper;
        delete MultiOperationsignalMapper;
        delete InputsignalMapper;
        uni->resetkalk();
    }
    if(uni->getStatus() == "advanced"){
        disconnect (Button1, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect (Button2, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        disconnect(Button4,SIGNAL(clicked()),InputsignalMapper,SLOT(map()));
        disconnect (Button5, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button6, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button13, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button10, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button7, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button8, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button9, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button11, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect (Button12, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        disconnect(Button3,SIGNAL(clicked()),this,SLOT(clearElenco()));

        disconnect (SingleOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(singleOperation(QString)));
        disconnect (InputsignalMapper, SIGNAL(mapped(QString)), this, SLOT(openExtraPanel(QString))) ;
        disconnect (MultiOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(SetOperation(QString)));

        delete SingleOperationsignalMapper;
        delete MultiOperationsignalMapper;
        delete InputsignalMapper;
        uni->resetkalk();
    }
    if(q == "set"){
        SingleOperationsignalMapper = new QSignalMapper();
        MultiOperationsignalMapper = new QSignalMapper();
        InputsignalMapper = new QSignalMapper();
        uni->setStatus("set");
        Status->setText("SET");
        Button1->setText("Create Set");
        Button2->setText("Delete Set");
        Button3->setText("Clear Kalk");
        Button4->setText("Save Result");
        Button5->setText("Insert Number");
        Button6->setText("Delete Number");
        Button7->setText("Union");
        Button8->setText("Intercetion");
        Button9->setText("Difference");
        Button10->setText("Complement");
        Button11->setText("SymmetricalDif.");
        Button12->setText("CartesianProd");
        Button13->setText("PowerSet()");

        connect (Button1, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect (Button2, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect (Button5, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect (Button6, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect (Button13, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button10, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button7, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button8, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button9, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button11, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button12, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect(Button3,SIGNAL(clicked()),this,SLOT(clearElenco()));
        connect(Button4,SIGNAL(clicked()),this,SLOT(save()));

        InputsignalMapper -> setMapping (Button1, "New") ;
        InputsignalMapper -> setMapping (Button2, "Remove") ;
        InputsignalMapper -> setMapping (Button5, "AddElement") ;
        InputsignalMapper -> setMapping (Button6, "SubElement") ;
        SingleOperationsignalMapper -> setMapping (Button13, "powerset") ;
        SingleOperationsignalMapper -> setMapping (Button10, "complement") ;
        MultiOperationsignalMapper -> setMapping (Button7, "union") ;
        MultiOperationsignalMapper -> setMapping (Button8, "intercetion") ;
        MultiOperationsignalMapper -> setMapping (Button9, "difference") ;
        MultiOperationsignalMapper -> setMapping (Button11, "symmetricaldifference") ;
        MultiOperationsignalMapper -> setMapping (Button12, "cartesianproduct") ;

        connect (SingleOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(singleOperation(QString)));
        connect (InputsignalMapper, SIGNAL(mapped(QString)), this, SLOT(openExtraPanel(QString))) ;
        connect (MultiOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(SetOperation(QString)));
        this->refresh();

    }
    if(q == "dataset"){
        SingleOperationsignalMapper = new QSignalMapper();
        MultiOperationsignalMapper = new QSignalMapper();
        InputsignalMapper = new QSignalMapper();
        uni->setStatus("dataset");
        Status->setText("DATASET");
        Button1->setText("Create Dataset");
        Button2->setText("Delete Dataset");
        Button3->setText("Clear Kalk");
        Button4->setText("Change Number");
        Button5->setText("Somme");
        Button6->setText("Size");
        Button7->setText("Average");
        Button8->setText("GL");
        Button9->setText("Variance");
        Button10->setText("DS");
        Button11->setText("Deviance");
        Button12->setText("Deviation");
        Button13->setText("Deviation^2");
        Button14->hide();

        connect (Button1, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect (Button2, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect(Button4,SIGNAL(clicked()),InputsignalMapper,SLOT(map()));
        connect (Button5, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button6, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button13, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button10, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button7, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button8, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button9, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button11, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect (Button12, SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        connect(Button3,SIGNAL(clicked()),this,SLOT(clearElenco()));

        InputsignalMapper -> setMapping (Button1, "New") ;
        InputsignalMapper -> setMapping (Button2, "Remove") ;
        InputsignalMapper -> setMapping (Button4, "Change") ;
        SingleOperationsignalMapper -> setMapping (Button5, "somme") ;
        SingleOperationsignalMapper -> setMapping (Button6, "size") ;
        SingleOperationsignalMapper -> setMapping (Button7, "average") ;
        SingleOperationsignalMapper -> setMapping (Button8, "gl") ;
        SingleOperationsignalMapper -> setMapping (Button9, "variance") ;
        SingleOperationsignalMapper -> setMapping (Button10, "ds") ;
        SingleOperationsignalMapper -> setMapping (Button11, "deviance") ;
        SingleOperationsignalMapper -> setMapping (Button12, "deviation") ;
        SingleOperationsignalMapper -> setMapping (Button13, "deviation^2") ;

        connect (SingleOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(singleOperation(QString)));
        connect (InputsignalMapper, SIGNAL(mapped(QString)), this, SLOT(openExtraPanel(QString))) ;
        connect (MultiOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(SetOperation(QString)));
        this->refresh();
    }
    if(q == "advanced"){
        SingleOperationsignalMapper = new QSignalMapper();
        MultiOperationsignalMapper = new QSignalMapper();
        InputsignalMapper = new QSignalMapper();
        uni->setStatus("advanced");
        Status->setText("ADVANCED");
        Button1->setText("Create Advanced");
        Button2->setText("Delete Advanced");
        Button3->setText("Clear Kalk");
        Button4->setText("All Info");
        Button5->setText("Coscarto");
        Button6->setText("Codevianza");
        Button7->setText("Covarianza");
        Button8->setText("Correlazione");
        Button9->setText("C.Determinazione");
        Button10->setText("Regressione");
        Button11->setText("Intercetta");
        Button12->setText("Retta");
        Button13->setText("Grafic");

        connect (Button1, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect (Button2, SIGNAL(clicked()), InputsignalMapper, SLOT(map())) ;
        connect(Button4,SIGNAL(clicked()),MultiOperationsignalMapper,SLOT(map()));
        connect (Button5, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button6, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button10, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button7, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button8, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button9, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button11, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button12, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect (Button13, SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        connect(Button3,SIGNAL(clicked()),this,SLOT(clearElenco()));

        InputsignalMapper -> setMapping (Button1, "New") ;
        InputsignalMapper -> setMapping (Button2, "Remove") ;
        MultiOperationsignalMapper -> setMapping (Button4, "allinfo") ;
        MultiOperationsignalMapper -> setMapping (Button5, "coscarto") ;
        MultiOperationsignalMapper -> setMapping (Button6, "codevianza") ;
        MultiOperationsignalMapper -> setMapping (Button7, "covarianza") ;
        MultiOperationsignalMapper -> setMapping (Button8, "correlazione") ;
        MultiOperationsignalMapper -> setMapping (Button9, "correllazione^2") ;
        MultiOperationsignalMapper -> setMapping (Button10, "regressione") ;
        MultiOperationsignalMapper -> setMapping (Button11, "intercetta") ;
        MultiOperationsignalMapper -> setMapping (Button12, "retta") ;
        MultiOperationsignalMapper -> setMapping (Button13, "grafic") ;

        connect (SingleOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(singleOperation(QString)));
        connect (InputsignalMapper, SIGNAL(mapped(QString)), this, SLOT(openExtraPanel(QString))) ;
        connect (MultiOperationsignalMapper, SIGNAL(mapped(QString)), this, SLOT(SetOperation(QString)));
        this->refresh();
    }
    Barra->setText("Status Update!");
}

void KalkMainWindow::setCE(){
    uni->resetkalk();
    Barra->clear();
}

std::string KalkMainWindow::vuoto()const{
    return uni->getVoidNumbers();
}

*/
