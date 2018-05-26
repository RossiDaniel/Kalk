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

class KalkMainWindow: public QWidget{
    Q_OBJECT
public:
    KalkMainWindow(){}
public slots:
    void emitSignal();
signals:
    void valueChanged();

};

#endif // KALKMAINWINDOW_H
