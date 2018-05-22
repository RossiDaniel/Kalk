#include "MODEL/HEADER/logic.h"
#include "GUI/HEADER/setview.h"
#include "MODEL/HEADER/SetLogic.h"


logic::logic(){
    view=new SetView();
    uni= new SetLogic();
    view->show();
}
logic::~logic(){

}
