#include "MODEL/HEADER/app.h"
#include "GUI/HEADER/datasetview.h"
AppKalk::AppKalk(){
    views.push_back(new SetView());
    views.push_back(new DatasetView());
    views.push_back(new AdvancedView());

    for(unsigned int i=0; i<views.size(); i++){
        //connect();
    }

    container_view= new View(views);
    container_view->show();
    uni =new SetLogic();
    Uset.push_back(new set("U"));
}

AppKalk::~AppKalk(){

}
