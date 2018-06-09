
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

    QGridLayout* right;
    QGridLayout* left;
    QHBoxLayout* all;
    QGridLayout* buttonLayout;
    QGridLayout* bottom;

    QSignalMapper* StatussignalMapper;
    QSignalMapper* InputsignalMapper;
    QSignalMapper* SingleOperationsignalMapper;
    QSignalMapper* MultiOperationsignalMapper;

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
    DatasetView();
};


#endif // DATASETVIEW_H
