    #include "GUI/HEADER/kalkmainwindow.h"
KalkMainWindow::KalkMainWindow(){
    StatusSet= new QPushButton("SET");
    StatusDataset =new QPushButton("DATASET");
    StatusAdvanced= new QPushButton("ADVANCED");

    StatussignalMapper = new QSignalMapper();
    connect (StatusSet, SIGNAL(clicked()), StatussignalMapper, SLOT(map())) ;
    connect (StatusDataset, SIGNAL(clicked()), StatussignalMapper, SLOT(map())) ;
    connect (StatusAdvanced, SIGNAL(clicked()), StatussignalMapper, SLOT(map())) ;

    StatussignalMapper -> setMapping (StatusSet, "SET");
    StatussignalMapper -> setMapping (StatusDataset, "DATASET");
    StatussignalMapper -> setMapping (StatusAdvanced, "ADVANCED");

    connect (StatussignalMapper, SIGNAL(mapped(QString)), this, SIGNAL(StatusChange(QString)));
}

QGridLayout* KalkMainWindow::GetStatusGrid(){
    QGridLayout* StatusGrid= new QGridLayout();
    StatusGrid->addWidget(StatusSet,1,1);
    StatusGrid->addWidget(StatusDataset,2,1);
    StatusGrid->addWidget(StatusAdvanced,3,1);
    return StatusGrid;
}

void KalkMainWindow::emitSignal(){
    emit valueChanged();
}

void KalkMainWindow::emitStatus(QString status){
    emit StatusChange(status);
}

std::string KalkMainWindow::getNewStatus()const{
    return newStatus.toStdString();
}
