    #include "GUI/HEADER/kalkmainwindow.h"
KalkMainWindow::KalkMainWindow(){
    set=new QPushButton("SET");
    dataset=new QPushButton("DATASET");
    advanced=new QPushButton("ADVACED");

}

QGridLayout* KalkMainWindow::GetStatusGrid(){
    QGridLayout* StatusGrid= new QGridLayout();
    StatusGrid->addWidget(set,1,1);
    StatusGrid->addWidget(dataset,2,1);
    StatusGrid->addWidget(advanced,3,1);
    return StatusGrid;
}

void KalkMainWindow::emitSignal(){
    emit valueChanged();
}
