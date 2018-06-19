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
    delete griglia;
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
