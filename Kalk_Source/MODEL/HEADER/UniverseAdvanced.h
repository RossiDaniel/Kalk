#ifndef ADVANCEDUNIVERSE_H
#define ADVANCEDUNIVERSE_H
#include"advanced.h"
#include<list>
#include<string>
class AdvancedUniverse{
public:
    std::string coscarto(const advanced&,const advanced&)const;
    std::string codevianza(const advanced&,const advanced&)const;
    std::string covarianza(const advanced&,const advanced&)const;
    std::string correlazione(const advanced&,const advanced&)const;
    std::string coeff_determinazione(const advanced&,const advanced&)const;
    std::string regressione(const advanced&,const advanced&)const;
    std::string intercetta(const advanced&,const advanced&)const;

};

#endif //ADVANCEDUNIVERSE_H
