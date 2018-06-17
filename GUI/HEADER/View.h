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
    int currentStatus;
    QPalette* pal;
    QPushButton* CE;
    QPushButton* clearKalk;
    QGridLayout* inputButtonGrid;

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

    std::vector<QPushButton*> statusButton;
    std::vector<QPushButton*> inputButton;

    QSignalMapper* StatusSignalMapper;
    QSignalMapper* InputSignalMapper;

    SetView* set;
    DatasetView* dataset;
    AdvancedView* advanced;
    std::vector<KalkMainWindow*> views;
public:
    View(std::vector<QString>);
    ~View();
    void setViews();
    std::vector<QString> getBasicOperation()const;
public slots:
    void refresh(std::list<QString>);
    void setCE();
    void setBarra(QString);
    void setError(QString);
    void changePallet(int);
    void clear();

signals:
    void input(int);
    void selectOperand(QListWidgetItem*);
    void changelogic(int);
    void cancel();
    void operation(int);
    void singleOperation(int);
    void result();
    void clearKalkElements();
    void CloseIfExist();
    void extraoperation(int);

};

#endif // VIEW_H
