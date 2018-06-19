#ifndef ADVANCEDCOMMONOPERATION_H
#define ADVANCEDCOMMONOPERATION_H
#include"Advanced.h"
#include<list>
#include<string>
#include<GUI/HEADER/qcustomplot.h>

class AdvancedCommonOperation:public QObject{
    Q_OBJECT
private:
    QCustomPlot* customPlot;
public:
    AdvancedCommonOperation();
    virtual ~AdvancedCommonOperation();

    std::string coscarto(const advanced&,const advanced&)const;
    std::string codevianza(const advanced&,const advanced&)const;
    std::string covarianza(const advanced&,const advanced&)const;
    std::string correlazione(const advanced&,const advanced&)const;
    std::string coeff_determinazione(const advanced&,const advanced&)const;
    std::string regressione(const advanced&,const advanced&)const;
    std::string intercetta(const advanced&,const advanced&)const;
    std::string Allinfo(const advanced&,const advanced&)const;
    std::string Grafic(const advanced&,const advanced&);
    std::string retta(const advanced&,const advanced&)const;

public slots:
    void cleanGrafic();
};

#endif //ADVANCEDCOMMONOPERATION_H
