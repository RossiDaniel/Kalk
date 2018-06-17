#include "MODEL/HEADER/Advanced.h"

advanced::advanced(const std::string& name, const std::list<int>& l):dataset(name,l){
    update();
}

void advanced::clear(){
    this->dataset::clear();
    this->update();
}
advanced* advanced::clone() const{
    return new advanced(*this);
}
void advanced::add_list(const std::list<int>& l){
    this->dataset::add_list(l);
    this->update();
}
void advanced::sub_list(const std::list<int>& l){
    this->dataset::sub_list(l);
    this->update();
}

std::string advanced::name() const{
    return std::string("advanced");
}

void advanced::update(){
    size=this->dataset::size();
    average=this->dataset::average();
    GL=this->dataset::GL();
    variance=this->dataset::variance();
    DS=this->dataset::DS();
    deviance=this->dataset::deviance();
    deviation=this->dataset::deviation();
    power2_deviation=this->dataset::power2_deviation();
}

std::list<double> advanced::coscarto(const advanced& s2)const{
    std::list<double> coscarto;
    std::cout<<size<<" "<<s2.size;
    if(size != s2.size){throw std::string("Exception : Advanced dataset incompatible, size is different");}
    this->checkpoint(s2);
        std::list<double>::const_iterator it1= deviation.begin();
        std::list<double>::const_iterator it2= s2.deviation.begin();
        for(; it1!=deviation.end(); it1++,it2++){
            coscarto.push_back((*it1)*(*it2));
        }
    return coscarto;
}

double advanced::codevianza(const advanced& s2)const{
    double codevianza =0;
    std::list<double> coscarti =coscarto(s2);
    for(std::list<double>::iterator it= coscarti.begin(); it!=coscarti.end(); it++){
            codevianza = codevianza + (*it);
        }
    return codevianza;
}

double advanced::covarianza(const advanced& s2)const{
    double covarianza =0;
    double code =codevianza(s2);
    covarianza =code / GL;
    return covarianza;
}

double advanced::correlazione(const advanced& s2)const{
    double correlazione =0;
    double cova =covarianza(s2);
    correlazione =(cova*10000)/((DS*100)*(s2.DS*100));
    return correlazione;
}

double advanced::coeff_determinazione(const advanced& s1)const{
    double coeff =0;
    double corre =correlazione(s1)*100;
    coeff =(corre*corre)/10000;
    return coeff;
}

double advanced::regressione(const advanced& s2)const{
    double regressione =0;
    double corre =correlazione(s2);
    double ds1 = DS*100;
    double ds2 = s2.DS*100;
    regressione = corre * (ds2/ds1);
    return regressione;
}

double advanced::intercetta(const advanced& s2)const{
    double intercetta =0;
    double regre =regressione(s2);
    intercetta = s2.average - (regre*average);
    return intercetta;
}

