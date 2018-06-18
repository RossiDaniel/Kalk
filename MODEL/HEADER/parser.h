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
    unsigned int emptyName;

public:
    Parser();
    virtual ~Parser()=0;
    std::list<int> parserData(QString);
    std::string parserName(QString);
    virtual bool condition()const=0;
    void restoreDefault();
    virtual QString getNameType()=0;

};


#endif //PARSER_H
