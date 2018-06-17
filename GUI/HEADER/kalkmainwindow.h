#ifndef KALKMAINWINDOW_H
#define KALKMAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include<QListWidget>
#include<QScrollBar>
#include <QListWidgetItem>
#include <QTextEdit>
#include<QLabel>
#include<QSignalMapper>
#include<QString>


class KalkMainWindow: public QWidget{
    Q_OBJECT
public:
    virtual ~KalkMainWindow()=0;

signals:
    void input(int);
    void operation(int);
    void singleOperation(int);
    void extraoperation(int);
    void result();
    void cancel();

};

#endif // KALKMAINWINDOW_H
