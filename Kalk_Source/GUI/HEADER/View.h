#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <GUI/HEADER/kalkmainwindow.h>
#include <GUI/HEADER/setview.h>
#include <GUI/HEADER/datasetview.h>
#include <GUI/HEADER/advancedview.h>
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
#include<QStackedWidget>

class View: public QWidget{
    Q_OBJECT

private:
    QStackedWidget* operationArea;
    QHBoxLayout* kalk;
    QGridLayout* status;

    QPushButton* StatusSet;
    QPushButton* StatusDataset;
    QPushButton* StatusAdvanced;
    QSignalMapper* StatussignalMapper;

    SetView* set;
    DatasetView* dataset;
    AdvancedView* advanced;

public:
    View(std::vector<KalkMainWindow*>&);

signals:
    void changelogic(int);
};

#endif // VIEW_H
