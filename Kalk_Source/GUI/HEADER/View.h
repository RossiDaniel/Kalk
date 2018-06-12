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
    QPushButton* CE;
    QTextEdit* Barra;
    QLineEdit* errori;
    QListWidget* elenco;
    QGridLayout* bottom;
    QGridLayout* right;
    QGridLayout* left;
    QHBoxLayout* all;

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
    std::vector<KalkMainWindow*> views;
public:
    View();
    ~View();
    void setViews();
public slots:
    void refresh(std::list<QString>);
    void setCE();
    void setBarra(QString);

signals:
    void selectOperand(QListWidgetItem*);
    void changelogic(int);
    void cancel();
    void operation(QString);
    void singleOperation(QString);
};

#endif // VIEW_H
