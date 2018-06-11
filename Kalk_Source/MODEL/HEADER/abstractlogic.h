#ifndef ABSTRACTLOGIC_H
#define ABSTRACTLOGIC_H

#include<QWidget>

class AbstractLogic: public QObject{
    Q_OBJECT

public:
    AbstractLogic();
    virtual ~AbstractLogic()=0;

public slots:
    virtual void SetOperation(QString)=0;
    virtual void CE()=0;
    virtual void singleOperation(QString)=0;
    virtual void getElements()=0;

signals:
    void listOfElements(std::list<QString>);
};

#endif // ABSTRACTLOGIC_H
