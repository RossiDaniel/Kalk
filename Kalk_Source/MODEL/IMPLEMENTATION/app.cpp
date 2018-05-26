#include "MODEL/HEADER/app.h"

AppKalk::AppKalk(){
    view =new SetView();
    uni =new SetLogic();
    Uset.push_back(new set("U"));
    view->show();
    QObject::connect(view, SIGNAL(valueChanged()), uni, SLOT(printValue()));
}

AppKalk::~AppKalk(){

}
