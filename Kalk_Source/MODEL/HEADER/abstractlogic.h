#ifndef ABSTRACTLOGIC_H
#define ABSTRACTLOGIC_H

#include<QWidget>
#include<QListWidgetItem>

class AbstractLogic: public QObject{
    Q_OBJECT
private:
    QString nameType;
public:
    AbstractLogic(QString);
    virtual ~AbstractLogic()=0;
    virtual void getNameType();
public slots:
    virtual void CE()=0;
    virtual void SetOperand(std::string, std::string )=0;
    virtual void SetOperation(QString)=0;
    virtual void singleOperation(QString)=0;
    virtual void getElements()=0;
    virtual void selectOperand(QListWidgetItem*)=0;

signals:
    void listOfElements(std::list<QString>);
    void setBarra(QString);
};

#endif // ABSTRACTLOGIC_H
