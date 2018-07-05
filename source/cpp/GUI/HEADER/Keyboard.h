#ifndef KALKMAINWINDOW_H
#define KALKMAINWINDOW_H

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>
#include<QString>


class Keyboard: public QWidget{
    Q_OBJECT
private:
    QGridLayout* buttonLayout;
    QSignalMapper* SingleOperationsignalMapper;
    QSignalMapper* MultiOperationsignalMapper;
    QSignalMapper* ExtraOperationsignalMapper;

    std::vector<QPushButton*> Operationkeyboard;
public:
    ~Keyboard();
    virtual std::vector<QString> getSingleOperationkeyboard()const=0;
    virtual std::vector<QString> getMultiOperationkeyboard()const=0;
    virtual std::vector<QString> getExtraOperationkeyboard()const=0;
    void configure();
signals:
    void multioperation(int);
    void singleOperation(int);
    void extraoperation(int);
};

#endif // KALKMAINWINDOW_H
