#ifndef KALK_H
#define KALK_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include "GUI/HEADER/kalkmainwindow.h"
#include "MODEL/HEADER/abstractlogic.h"

class logic{
private:
    KalkMainWindow* view;
    AbstractLogic* uni;
    std::list<const numbers*> Uset;

public:
    logic();
    ~logic();
};

#endif // KALK_H
