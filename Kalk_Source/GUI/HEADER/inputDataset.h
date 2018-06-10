#ifndef INPUT_DATASET_H
#define INPUT_DATASET_H

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


class InputDataset:public extrapanel{
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
    InputDataset();
    ~InputDataset();
    std::list<int> parser()const;

public slots:
    void creaset();
    void remove();
    void addelement();
    void subelement();
    void modify();
    void update();

};
#endif // INPUT_DATASET_H

