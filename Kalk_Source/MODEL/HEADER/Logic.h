#include <QObject>
#include"MODEL/HEADER/abstractlogic.h"
#include"MODEL/HEADER/SetLogic.h"
#include"MODEL/HEADER/DatasetLogic.h"
#include"MODEL/HEADER/AdvancedLogic.h"

class Logic: public QObject{
    Q_OBJECT
private:
    AbstractLogic* uni;
    std::vector<AbstractLogic*> logics;
    std::list<const numbers*>* Uset;

public:
    Logic();
    ~Logic();
    void setLogics();

public slots:
    void CE();
    void SetOperation(QString);
    void singleOperation(QString);
    void selectOperand(QListWidgetItem*);
    void changeLogic(int);
signals:
    void listOfElements(std::list<QString>);
    void setBarra(QString);

};
