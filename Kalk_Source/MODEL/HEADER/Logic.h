#include <QObject>
#include"MODEL/HEADER/basiclogic.h"
#include"MODEL/HEADER/SetLogic.h"
#include"MODEL/HEADER/DatasetLogic.h"
#include"MODEL/HEADER/AdvancedLogic.h"

class Logic: public QObject{
    Q_OBJECT
private:
    BasicLogic* uni;
    std::vector<BasicLogic*> logics;
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
    void executeOperation(int,QString,QString);

signals:
    void listOfElements(std::list<QString>);
    void setBarra(QString);
    void setError(QString);
    void setErrorInput(QString);
};
