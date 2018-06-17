#ifndef ADVANCEDVIEW_H
#define ADVANCEDVIEW_H

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

class AdvancedView: public KalkMainWindow{
    Q_OBJECT

private:
    QGridLayout* buttonLayout;
    QSignalMapper* SingleOperationsignalMapper;
    QSignalMapper* MultiOperationsignalMapper;
    QSignalMapper* ExtraOperationsignalMapper;

    std::vector<QPushButton*> Operationkeyboard;
public:
    AdvancedView();
    ~AdvancedView();
    std::vector<QString> getSingleOperationkeyboard();
    std::vector<QString> getMultiOperationkeyboard();
    std::vector<QString> getExtraOperationkeyboard();

};

#endif // ADVANCEDVIEW_H
