#ifndef ABSTRACTLOGIC_H
#define ABSTRACTLOGIC_H

#include<QWidget>

class AbstractLogic: public QWidget{
    Q_OBJECT

public:
    AbstractLogic();
    ~AbstractLogic();

public slots:
    virtual void SetOperation(QString)=0;
    virtual void CE()=0;
    virtual void singleOperation(QString)=0;

};

#endif // ABSTRACTLOGIC_H
