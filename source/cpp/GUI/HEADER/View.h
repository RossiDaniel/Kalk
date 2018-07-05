#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <GUI/HEADER/Keyboard.h>
#include <GUI/HEADER/SetKeyboard.h>
#include <GUI/HEADER/DatasetKeyboard.h>
#include <GUI/HEADER/AdvancedKeyboard.h>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include"MODEL/HEADER/SetLogic.h"
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>
#include<QStackedWidget>

class View: public QWidget{
    Q_OBJECT

private:
    int currentStatus;
    QPalette pal;
    QTextEdit* Barra;
    QLineEdit* errori;
    QListWidget* elenco;
    QHBoxLayout* kalk;
    std::vector<QPushButton*> statusButton;
    std::vector<Keyboard*> views;
public:
    View(std::vector<QString>);
    ~View();
    void setViews();
    std::vector<QString> getBasicOperation()const;
public slots:
    void refresh(std::list<QString>);
    void setAC();
    void setBarra(QString);
    void setError(QString);
    void changePalette(int);
    void clear();

signals:
    void input(int);
    void selectOperand(QListWidgetItem*);
    void changelogic(int);
    void cancel();
    void multioperation(int);
    void singleOperation(int);
    void clearKalkElements();
    void CloseIfExist();
    void extraoperation(int);

};

#endif // VIEW_H
