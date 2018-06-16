#ifndef INPUT_SET_H
#define INPUT_SET_H

#include "GUI/HEADER/extrapanel.h"
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


class InputSet:public extrapanel{
    Q_OBJECT
private:
    QLabel* errore;
    QGridLayout* Griglia;
    QLabel* Name;
    QLineEdit* InputName;
    QLabel* Set;
    QLineEdit* Inputset;
    QPushButton* Invio;
    QPushButton* up;
    dataset* d;


public:
    InputSet();
    ~InputSet();
    std::list<int> parser()const;

public slots:
    void creaset();
    void remove();
    void addelement();
    void subelement();
    void modify();
    void update();

};
#endif // INPUT_SET_H

