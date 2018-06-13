#include "MODEL/HEADER/parser.h"
Parser::Parser(){
    dimensione=0;
    num=0;
    n=0;
    k=0;

}

Parser::~Parser(){}

std::list<int> Parser::parser(QString data)const{
/*    num =(std::to_string(INT_MAX)).size();
    long int somma=0;
    bool sent=true;
    bool overflow=false;
    std::list<int> l;
    QChar blank(' ');
    QChar virgola(',');
    QChar meno('-');
    for(int i=0; i< data.size(); i++){
            const QString q =data.at(i);
            sent=true;
            int k=q.toInt(&sent, 10);
                if(sent){
                    if(status == "set"){
                        if(dimensione >=num-1){
                            overflow=true;
                            l.push_back(n*segno);
                            n=k;
                            segno=1;
                            dimensione=1;
                        }
                    }else{
                        if(somma>INT_MAX){
                            throw std::string("The inserted value si too big, insert a smaller number");
                        }
                        else{
                            if(status == "advanced"){
                                if((n*10+k)>50){
                                    somma+=n*segno;
                                    overflow=true;
                                    l.push_back(n*segno);
                                    n=k;
                                    segno=1;
                                    dimensione=1;
                                }
                            }
                            else{
                                if(dimensione >=num-1){
                                    somma+=n*segno;
                                    overflow=true;
                                    l.push_back(n*segno);
                                    n=k;
                                    segno=1;
                                    dimensione=1;
                                }
                             }
                         }
                    }
                    if(!overflow){
                        n=n*10;
                        n+=k;
                        dimensione++;
                    }
                    else{
                        overflow=false;
                    }
            }
        if(insieme[i] == blank || insieme[i] == virgola || insieme[i] == meno || !sent){
            if(dimensione){
                somma+=n*segno;
                l.push_back(n*segno);
                n=0;
                segno=1;
                dimensione=0;
            }
            if(insieme[i]==meno){
                segno=-1;
            }
        }
        if((i+1) == insieme.size() && insieme[i] != blank && insieme[i] != virgola && sent){
            l.push_back(n*segno);
        }
    }
    return l;*/
}
