#ifndef ADVANCEDCOMMONOPERATION_H
#define ADVANCEDCOMMONOPERATION_H
#include"Advanced.h"
#include<list>
#include<string>
class AdvancedCommonOperation{
public:
    std::string coscarto(const advanced&,const advanced&)const;
    std::string codevianza(const advanced&,const advanced&)const;
    std::string covarianza(const advanced&,const advanced&)const;
    std::string correlazione(const advanced&,const advanced&)const;
    std::string coeff_determinazione(const advanced&,const advanced&)const;
    std::string regressione(const advanced&,const advanced&)const;
    std::string intercetta(const advanced&,const advanced&)const;

};

#endif //ADVANCEDCOMMONOPERATION_H
