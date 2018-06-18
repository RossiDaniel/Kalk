#include "MODEL/HEADER/parser.h"
Parser::Parser():emptyName(0){
    restoreDefault();
}

Parser::~Parser(){}

void Parser::restoreDefault(){
    dimensione=0;
    num=(std::to_string(INT_MAX)).size();
    n=0;
    k=0;
    segno=1;
    somma=0;
}

std::string Parser::parserName(QString name){
    std::string nm=name.toStdString();
    if(nm == ""){
        nm=getNameType().toStdString()+std::to_string(emptyName);
        emptyName++;
    }
    return nm;
}

std::list<int> Parser::parserData(QString data){
    restoreDefault();
    QChar blank=QChar(' ');
    QChar virgola=QChar(',');
    QChar meno=QChar('-');

    bool sent=true;
    std::list<int> l;

    for(int i=0; i< data.size(); i++){
        const QString q =data.at(i);
        sent=true;
        int k=q.toInt(&sent, 10);
            if(sent){
                if(condition()){
                    somma+=n*segno;
                    l.push_back(n*segno);
                    n=k;
                    segno=1;
                    dimensione=1;
                }else{
                    n=n*10;
                    n+=k;
                    dimensione++;
                }
            }
        if(data[i] == blank || data[i] == virgola || data[i] == meno || !sent){
            if(dimensione){
                somma+=n*segno;
                l.push_back(n*segno);
                n=0;
                segno=1;
                dimensione=0;
            }
            if(data[i]==meno){
                segno=-1;
            }
        }
        if((i+1) == data.size() && data[i] != blank && data[i] != virgola && sent){
            l.push_back(n*segno);
        }
    }
    return l;
}
