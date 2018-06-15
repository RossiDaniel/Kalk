#ifndef BASIC_LOGIC_H
#define BASIC_LOGIC_H

#include<QWidget>
#include<QListWidgetItem>
#include "MODEL/HEADER/numbers.h"
#include "MODEL/HEADER/parser.h"

#include<typeinfo>

class BasicLogic: public Parser{
    Q_OBJECT
private:
    QString nameType;
    std::string type;
protected:
    std::list<const numbers*>* elements;
    numbers* operand1;
    numbers* operand2;
    QString* operation;

public:
    BasicLogic(QString,std::string,std::list<const numbers*>*);
    virtual ~BasicLogic()=0;
    void getNameType();
    bool checkType(std::string)const;
    void CE();
    virtual void SetOperand(std::string, std::string );
    virtual void SetOperation(QString);
    virtual void selectOperand(QListWidgetItem*);
    virtual void singleOperation(QString)=0;

    virtual void add_set(QString,QString);
    virtual void sub_set(QString);
    virtual void add_elements(QString,QString);
    virtual void sub_elements(QString,QString);

    virtual numbers* getObjectLogicClass(std::string,std::list<int>)=0;
    void getElements();
    void update();

signals:
    void listOfElements(std::list<QString>);
    void setBarra(QString);
    void setError(QString);
    void setErrorInput(QString);
    void closeInputWindow();
};

#endif // BASIC_LOGIC_H
