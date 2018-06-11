#include "GUI/HEADER/setview.h"

SetView::SetView(){
    typestatus= new QLabel("Status Attuale: ");
    Status = new QLabel("SET");

    Button1 =new QPushButton("Create Set");
    Button2 =new QPushButton("Delete Set");
    Button3 =new QPushButton("Clear Kalk");
    Button4 =new QPushButton("Save Result");
    Button5 =new QPushButton("Insert Number");
    Button6 =new QPushButton("Delete Number");
    Button7 =new QPushButton("Union");
    Button8 =new QPushButton("Intercetion");
    Button9 =new QPushButton("Difference");
    Button10 =new QPushButton("Complement");
    Button11 =new QPushButton("SymmetricalDif.");
    Button12 =new QPushButton("CartesianProd");
    Button13 =new QPushButton("PowerSet()");
    Button14 =new QPushButton("=");

    InputsignalMapper = new QSignalMapper (this) ;

    InputsignalMapper -> setMapping (Button1, "New") ;
    InputsignalMapper -> setMapping (Button2, "Remove") ;
    InputsignalMapper -> setMapping (Button5, "AddElement") ;
    InputsignalMapper -> setMapping (Button6, "SubElement") ;

    connect(InputsignalMapper, SIGNAL(mapped(QString)), this, SIGNAL(input(QString))) ;

    SingleOperationsignalMapper = new QSignalMapper (this) ;

    SingleOperationsignalMapper -> setMapping (Button13, "powerset") ;
    SingleOperationsignalMapper -> setMapping (Button10, "complement") ;

    MultiOperationsignalMapper = new QSignalMapper (this) ;

    MultiOperationsignalMapper -> setMapping (Button7, "union") ;
    MultiOperationsignalMapper -> setMapping (Button8, "intercetion") ;
    MultiOperationsignalMapper -> setMapping (Button9, "difference") ;
    MultiOperationsignalMapper -> setMapping (Button11, "symmetricaldifference") ;
    MultiOperationsignalMapper -> setMapping (Button12, "cartesianproduct") ;

    buttonLayout= new QGridLayout();

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

    buttonLayout->setAlignment(Qt::AlignTop);
    setLayout(buttonLayout);
}
SetView::~SetView(){}

/*
void KalkMainWindow::openExtraPanel(QString q){
    extrapanel* panel=new extrapanel(this,q);
    panel->show();
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


std::string KalkMainWindow::vuoto()const{
    return uni->getVoidNumbers();
}

*/
