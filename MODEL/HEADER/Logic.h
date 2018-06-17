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
    std::vector<QString> nameType()const;
public slots:
    void CE();
    void SetOperation(int);
    void singleOperation(int);
    void selectOperand(QListWidgetItem*);
    void changeLogic(int);
    void executeOperation(int,QString,QString);
    void result();
    void clearKalkElements();

signals:
    void listOfElements(std::list<QString>);
    void setBarra(QString);
    void setError(QString);
    void setErrorInput(QString);
    void closeInputWindow();
};
