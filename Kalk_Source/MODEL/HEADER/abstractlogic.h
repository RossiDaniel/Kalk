#ifndef ABSTRACTLOGIC_H
#define ABSTRACTLOGIC_H

#include<QWidget>

class AbstractLogic: public QWidget{
    Q_OBJECT

public:
    AbstractLogic();
    ~AbstractLogic();

public slots:
    virtual void printValue()=0;
};

#endif // ABSTRACTLOGIC_H
