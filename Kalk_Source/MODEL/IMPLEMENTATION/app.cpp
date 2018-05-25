#include "MODEL/HEADER/app.h"

app::app(){
    view =new SetView();
    Uset.push_back(new set("U"));
    view->show();
}
