#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <QString>
#include <list>

class Parser{
private:
    int dimensione;
    int num;
    int n;
    int k;

public:
    Parser();
    virtual ~Parser()=0;
    std::list<int> parser(QString)const;
    virtual bool condition()const=0;

};


#endif //PARSER_H
