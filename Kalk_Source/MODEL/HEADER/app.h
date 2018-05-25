#ifndef APP_H
#define APP_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "GUI/HEADER/kalkmainwindow.h"
#include "MODEL/HEADER/abstractlogic.h"
#include "MODEL/HEADER/SetLogic.h"
#include "GUI/HEADER/setview.h"
#include "MODEL/HEADER/Set.h"


class app{
private:
    KalkMainWindow* view;
    AbstractLogic* uni;
    std::list<const numbers*> Uset;

public:
    app();
    ~app();
};

#endif // APP_H
