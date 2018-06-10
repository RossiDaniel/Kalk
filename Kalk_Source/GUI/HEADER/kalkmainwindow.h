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
    KalkMainWindow();

public slots:

signals:
    void input(QString);
    void CE();
    void operation(QString);
    void singleOperation(QString);
    void result();

};

#endif // KALKMAINWINDOW_H
