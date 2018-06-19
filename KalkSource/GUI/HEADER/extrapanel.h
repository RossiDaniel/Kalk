#ifndef EXTRAPANEL_H
#define EXTRAPANEL_H

#include "MODEL/HEADER/Set.h"
#include "MODEL/HEADER/Dataset.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QScrollBar>
#include <QLabel>
#include <QString>
#include <climits>
#include <QMessageBox>
#include <QCloseEvent>

class extrapanel:public QWidget{
    Q_OBJECT
private:
    int operation;
    QGridLayout* griglia;
    QLabel* nameLabel;
    QLineEdit* inputName;
    QLabel* insertLabel;
    QLineEdit* inputNumbers;
    QPushButton* invio;
    QPushButton* up;
public:
    extrapanel();
    ~extrapanel();
    void configureExtrapanel();
    void creaset();
    void remove();
    void addelement();
    void subelement();
    void closeEvent( QCloseEvent* event );
public slots:
    void INVIO();
signals:
    void DataInput(QString,QString);
};
#endif // EXTRAPANEL_H
