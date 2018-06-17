#ifndef SETVIEW_H
#define SETVIEW_H

#include <QWidget>
#include <GUI/HEADER/kalkmainwindow.h>
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

class SetView: public KalkMainWindow{
    Q_OBJECT

private:
    QGridLayout* buttonLayout;
    QSignalMapper* SingleOperationsignalMapper;
    QSignalMapper* MultiOperationsignalMapper;
    QSignalMapper* ExtraOperationsignalMapper;

    std::vector<QPushButton*> Operationkeyboard;
public:
    SetView();
    ~SetView();
    std::vector<QString> getSingleOperationkeyboard();
    std::vector<QString> getMultiOperationkeyboard();
    std::vector<QString> getExtraOperationkeyboard();

};

#endif // SETVIEW_H
