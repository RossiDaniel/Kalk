#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <QString>
#include <list>
#include <climits>
#include <QObject>

class Parser:public QObject{
protected:
    int dimensione;
    int num;
    int n;
    int k;
    int segno;
    long int somma;

public:
    Parser();
    virtual ~Parser()=0;
    std::list<int> parser(QString);
    virtual bool condition()const=0;
    void restoreDefault();
};


#endif //PARSER_H
