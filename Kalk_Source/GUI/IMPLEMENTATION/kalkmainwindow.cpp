    #include "GUI/HEADER/kalkmainwindow.h"
KalkMainWindow::KalkMainWindow(){

}


void KalkMainWindow::emitSignal(){
    emit valueChanged();
}

void KalkMainWindow::emitStatus(QString status){
    emit StatusChange(status);
}

