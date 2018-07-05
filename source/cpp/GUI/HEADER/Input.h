#include<QWidget>
#include<QStackedWidget>

#include<GUI/HEADER/extrapanel.h>

class Input: public QWidget{
    Q_OBJECT
private:
    int operation;
    bool isUsed;
    extrapanel* input_view;
    QMessageBox* MessageError;
public:
    Input();
    ~Input();
    void configureExtrapanel();
public slots:
    void manageInput(int);
    void unlock();
    void SendDataInput(QString,QString);
    void setErrorInput(QString);
    void ifExistClose();
signals:
    void executeOperation(int,QString,QString);

};
