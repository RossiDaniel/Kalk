#ifndef KALKMAINWINDOW_H
#define KALKMAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include"MODEL/HEADER/kalk.h"
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>

class KalkMainWindow;

#include"GUI/HEADER/extrapanel.h"

class KalkMainWindow: public QWidget{
    Q_OBJECT
private:
    kalk* uni;

    QGridLayout* right;
    QGridLayout* left;
    QHBoxLayout* all;
    QGridLayout* buttonLayout;
    QGridLayout* bottom;
    QGridLayout* StatusGrid;

    QSignalMapper* StatussignalMapper;
    QSignalMapper* InputsignalMapper;
    QSignalMapper* SingleOperationsignalMapper;
    QSignalMapper* MultiOperationsignalMapper;

    QPushButton* StatusSet;
    QPushButton* StatusDataset;
    QPushButton* StatusAdvanced;
    QLabel* Status;

    QPushButton* CE;

    QPushButton* Button1;
    QPushButton* Button2;
    QPushButton* Button3;
    QPushButton* Button4;
    QPushButton* Button5;
    QPushButton* Button6;

    QPushButton* Button7;
    QPushButton* Button8;
    QPushButton* Button9;
    QPushButton* Button10;
    QPushButton* Button11;
    QPushButton* Button12;
    QPushButton* Button13;
    QPushButton* Button14;

    QTextEdit* Barra;
    QLineEdit* errori;
    QListWidget* elenco;

public:
    KalkMainWindow();
    ~KalkMainWindow();
    void refresh();
    void add_set(const numbers&);
    void sub_set(const std::string);
    void add_elements(const std::string, const std::list<int>&)const;
    void sub_elements(const std::string, const std::list<int>&)const;

    QString status()const;
    dataset* getDataset(std::string) const;
    std::list<std::string> getListOfSet()const;
    std::string vuoto()const;
public slots:
    void openExtraPanel(QString);
    void selectoperand(QListWidgetItem*);
    void SetOperation(QString);
    void clearElenco();
    void multiOperation();
    void singleOperation(QString);
    void save();
    void changeStatus(QString);
    void setCE();
};

#endif // KALKMAINWINDOW_H
