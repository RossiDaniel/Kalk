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
    void emitSignal();
    void emitStatus(QString);

signals:
    void valueChanged();
    void StatusChange(QString);


};

#endif // KALKMAINWINDOW_H
