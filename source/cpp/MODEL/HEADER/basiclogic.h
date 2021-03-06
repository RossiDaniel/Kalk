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
    int operation;
    numbers* result;

public:
    BasicLogic(QString,std::string,std::list<const numbers*>*);
    virtual ~BasicLogic()=0;
    QString getNameType();
    bool checkType(std::string)const;
    void AC();
    virtual void clearKalkElements();
    virtual void SetOperand(std::string, std::string );
    virtual void multioperation(int);
    virtual void selectOperand(QListWidgetItem*);
    virtual void singleOperation(int);
    virtual void extraoperation(int);

    virtual void add_set(QString,QString);
    virtual void sub_set(QString);
    virtual void add_elements(QString,QString);
    virtual void sub_elements(QString,QString);

    virtual numbers* getObjectLogicClass(std::string,std::list<int>)=0;
    void getElements();
    void update();
    virtual void results();


signals:
    void listOfElements(std::list<QString>);
    void setBarra(QString);
    void setError(QString);
    void setErrorInput(QString);
    void closeInputWindow();
};

#endif // BASIC_LOGIC_H
