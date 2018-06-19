#ifndef ADVANCED_H
#define ADVANCED_H
#include"Dataset.h"

class advanced: public dataset{
private:
	int size;
	double average;
	int GL;
	double variance;
	double DS;
	double deviance;
	std::list<double> deviation;
	std::list<double> power2_deviation;
public:
	advanced(const std::string&, const std::list<int>&);

    void clear();
    advanced* clone() const;
    void add_list(const std::list<int>&);
    void sub_list(const std::list<int>&);
    void update();
    std::string name() const;


    std::list<double> coscarto(const advanced&)const;
    double codevianza(const advanced&)const;
    double covarianza(const advanced&)const;
    double correlazione(const advanced&)const;
    double coeff_determinazione(const advanced&)const;
    double regressione(const advanced&)const;
    double intercetta(const advanced&)const;

};

#endif //ADVANCED_H
