#ifndef INPUT_ADVANCED_H
#define INPUT_ADVANCED_H

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


class InputAdvanced:public extrapanel{
    Q_OBJECT
private:
    QLabel* errore;
    QGridLayout* Griglia;
    QLabel* Name;
    QLineEdit* InputName;
    QLabel* Set;
    QLineEdit* InputSet;
    QPushButton* Invio;
    QPushButton* up;


public:
    InputAdvanced();
    ~InputAdvanced();
    std::list<int> parser()const;

public slots:
    void creaset();
    void remove();
    void addelement();
    void subelement();
    void modify();
    void update();

};
#endif // INPUT_ADVANCED_H

