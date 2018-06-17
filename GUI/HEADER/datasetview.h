
#ifndef DATASETVIEW_H
#define DATASETVIEW_H

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

class DatasetView: public KalkMainWindow{
    Q_OBJECT

private:
    QGridLayout* buttonLayout;
    QSignalMapper* SingleOperationsignalMapper;
    QSignalMapper* MultiOperationsignalMapper;
    QSignalMapper* ExtraOperationsignalMapper;

    std::vector<QPushButton*> Operationkeyboard;
public:
    DatasetView();
    ~DatasetView();
    std::vector<QString> getSingleOperationkeyboard();
    std::vector<QString> getMultiOperationkeyboard();
    std::vector<QString> getExtraOperationkeyboard();
};


#endif // DATASETVIEW_H
