#include "GUI/HEADER/extrapanel.h"

extrapanel::extrapanel(){
    griglia= new QGridLayout();
    nameLabel= new QLabel();
    inputName= new QLineEdit();
    insertLabel= new QLabel();
    inputNumbers= new QLineEdit();
    invio = new QPushButton("INVIO");

    griglia->addWidget(nameLabel,1,1);
    griglia->addWidget(inputName,2,1);
    griglia->addWidget(insertLabel,3,1);
    griglia->addWidget(inputNumbers,4,1);
    griglia->addWidget(invio,5,1);

    nameLabel->setAlignment(Qt::AlignCenter);
    insertLabel->setAlignment(Qt::AlignCenter);

    setLayout(griglia);
}

extrapanel::~extrapanel(){

}

void extrapanel::creaset(){
    nameLabel->setText("Insert a name:");
    insertLabel->setText("Insert a space or a comma to separate the values:");
    connect(invio, SIGNAL(clicked(bool)), this, SLOT(INVIO()));
}

void extrapanel::remove(){
    nameLabel->setText("Insert the name of the element you want to delete:");
    insertLabel->hide();
    inputNumbers->hide();
    connect(invio,SIGNAL(clicked(bool)),this,SLOT(INVIO()));
}

void extrapanel::addelement(){
    nameLabel->setText("Insert the name of the element to which you want to add values:");
    insertLabel->setText("Put a space or a comma to separate values:");
    connect(invio,SIGNAL(clicked(bool)),this,SLOT(INVIO()));
}

void extrapanel::subelement(){
    nameLabel->setText("Insert the name of the element from which you want to delete values");
    insertLabel->setText("Put a space or a comma to separate values:");
    connect(invio, SIGNAL(clicked(bool)), this, SLOT(INVIO()));
}

void extrapanel::INVIO(){
    emit DataInput(inputName->text(),inputNumbers->text());
}


void extrapanel::closeEvent( QCloseEvent* event ){
    emit destroyed();
    event->accept();
}

/*

extrapanel::extrapanel(KalkMainWindow* p,QString q){
    d=0;
    father=p;

    Griglia= new QGridLayout();
    errore =new QLabel("");
    errore->hide();
    Name=new QLabel("");
    InputName= new QLineEdit();
    Set=new QLabel("");
    InputSet= new QLineEdit();
    Invio= new QPushButton("invio");
    up =new QPushButton("Modifica");
    up->hide();

    Invio->setAutoDefault(true);
    if(father->status() == "set"){
        if(q == "New"){
            Name->setText("Insert a name for the Set:");
            Set->setText("Insert a space or a comma to separate the values:");
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(creaset()));
        }
        if(q == "Remove"){
            Name->setText("Insert the name of the set you want to delete:");
            Set->hide();
            InputSet->hide();
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(remove()));
        }
        if(q == "AddElement"){
            Name->setText("Insert the name of the set to which you want to add values:");
            Set->setText("Put a space or a comma to separate values:");

            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(addelement()));
        }
        if(q == "SubElement"){
            Name->setText("Insert the name of the set from which you want to delete values");
            Set->setText("Put a space or a comma to separate values:");
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(subelement()));
        }
    }
    if(father->status() == "dataset"){
        if(q == "New"){
            Name->setText("Insert a name for the Dataset:");
            Set->setText("Put a space or a comma to separate values:");
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(creaset()));
        }
        if(q == "Remove"){
            Name->setText("Insert the name of the set you want to delete:");
            Set->hide();
            InputSet->hide();
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(remove()));
        }
        if(q == "Change"){
            Name->setText("Insert the name of the Dataset you want to modify:");
            Set->hide();
            InputSet->hide();
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(modify()));
            connect(up, SIGNAL(clicked(bool)), this, SLOT(update()));

        }
    }
    if(father->status() == "advanced"){
        if(q == "New"){
            Name->setText("Insert a name for the Advanced Dataset:");
            Set->setText("Put a space or a comma to separate values:");
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(creaset()));
        }
        if(q == "Remove"){
            Name->setText("Insert the name of the Advanced Dataset you want to delete:");
            Set->hide();
            InputSet->hide();
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(remove()));
        }
        if(q == "Change"){
            Name->setText("Insert the name of the Advanced Dataset you want to modify:");
            Set->hide();
            InputSet->hide();
            connect(Invio, SIGNAL(clicked(bool)), this, SLOT(modify()));
            connect(up, SIGNAL(clicked(bool)), this, SLOT(update()));
        }
    }
    Griglia->addWidget(Name,1,1);
    Griglia->addWidget(errore,2,1);
    Griglia->addWidget(InputName,3,1);
    Griglia->addWidget(Set,4,1);
    Griglia->addWidget(InputSet,5,1);
    Griglia->addWidget(Invio,6,1);
    Griglia->addWidget(up,7,1);

    this->setLayout(Griglia);

}

void extrapanel::creaset(){
    try{
        numbers* s=0;
        std::string name=InputName->text().toStdString();
        if(name == ""){name = father->vuoto();}
        if(father->status() == "set"){
            s= new set(name,this->parser());
        }
        if(father->status() == "dataset"){
            s= new dataset(name,this->parser());
        }
        if(father->status() == "advanced"){
            s= new advanced(name,this->parser());
        }
        father->add_set(*s);
        father->refresh();
        father->updateGeometry();
        this->close();
    }
    catch(std::string st){
        QString qst = QString::fromStdString(st);
        errore->setText(qst);
        errore->setVisible(true);
    }
}

void extrapanel::remove(){
    std::string name=InputName->text().toStdString();
    try{
        father->sub_set(name);
        father->refresh();
        father->updateGeometry();
        this->close();
    }
    catch(std::string st){
        QString qst = QString::fromStdString(st);
        errore->setText(qst);
        errore->setVisible(true);
    }
}

void extrapanel::addelement(){
        std::string name=InputName->text().toStdString();
        std::list<int> l=this->parser();
        try{
            father->add_elements(name, l);
            father->refresh();
            father->updateGeometry();
            this->close();
        }
        catch(std::string st){
            QString qst = QString::fromStdString(st);
            errore->setText(qst);
            errore->setVisible(true);
        }
}

void extrapanel::subelement(){
    std::string name=InputName->text().toStdString();
    std::list<int> l=this->parser();
    try{
        father->sub_elements(name, l);
        father->refresh();
        father->updateGeometry();
        this->close();
    }
    catch(std::string st){
        QString qst = QString::fromStdString(st);
        errore->setText(qst);
        errore->setVisible(true);
    }
}

void extrapanel::modify(){
    try{
        std::string name=InputName->text().toStdString();
        d =father->getDataset(name);
        Name->hide();
        InputName->hide();
        Set->setVisible(true);
        Set->clear();
        Set->setText("Modify the selected Advanced Dataset:");
        std::list<int> l= d->get_element();
        std::list<int>::const_iterator cit = l.begin();
        std::string str;
        for(; cit!=l.end(); cit++){
            str= str + std::to_string(*cit) + " ";
        }
        InputSet->setVisible(true);
        InputSet->setText(QString::fromStdString(str));
        Invio->hide();
        up->setVisible(true);
    }
    catch(std::string ex){
        QString qst = QString::fromStdString(ex);
        errore->setText(qst);
        errore->setVisible(true);
    }
}

void extrapanel::update(){
    try{
        std::list<int> l=this->parser();
        d->clear();
        d->add_list(l);
        d=0;
        this->close();
    }
    catch(std::string ex){
        QString qst = QString::fromStdString(ex);
        errore->setText(qst);
        errore->setVisible(true);
    }
}

std::list<int> extrapanel::parser()const{
    QString status=father->status();
    if(d && dynamic_cast<const advanced*>(d)){status="advanced";}
    int num =(std::to_string(INT_MAX)).size();

    QString insieme=InputSet->text();
    int n=0;
    int segno=1;
    int dimensione=0;
    long int somma=0;
    bool sent=true;
    bool overflow=false;
    std::list<int> l;
    QChar blank(' ');
    QChar virgola(',');
    QChar meno('-');
    for(int i=0; i< insieme.size(); i++){
            const QString q =insieme.at(i);
            sent=true;
            int k=q.toInt(&sent, 10);
                if(sent){
                    if(status == "set"){
                        if(dimensione >=num-1){
                            overflow=true;
                            l.push_back(n*segno);
                            n=k;
                            segno=1;
                            dimensione=1;
                        }
                    }else{
                        if(somma>INT_MAX){
                            throw std::string("The inserted value si too big, insert a smaller number");
                        }
                        else{
                            if(status == "advanced"){
                                if((n*10+k)>50){
                                    somma+=n*segno;
                                    overflow=true;
                                    l.push_back(n*segno);
                                    n=k;
                                    segno=1;
                                    dimensione=1;
                                }
                            }
                            else{
                                if(dimensione >=num-1){
                                    somma+=n*segno;
                                    overflow=true;
                                    l.push_back(n*segno);
                                    n=k;
                                    segno=1;
                                    dimensione=1;
                                }
                             }
                         }
                    }
                    if(!overflow){
                        n=n*10;
                        n+=k;
                        dimensione++;
                    }
                    else{
                        overflow=false;
                    }
            }
        if(insieme[i] == blank || insieme[i] == virgola || insieme[i] == meno || !sent){
            if(dimensione){
                somma+=n*segno;
                l.push_back(n*segno);
                n=0;
                segno=1;
                dimensione=0;
            }
            if(insieme[i]==meno){
                segno=-1;
            }
        }
        if((i+1) == insieme.size() && insieme[i] != blank && insieme[i] != virgola && sent){
            l.push_back(n*segno);
        }
    }
    return l;
}
*/
