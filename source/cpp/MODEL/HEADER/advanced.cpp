#include "advanced.h"

	advanced(const std::string& name):dataset(name){
	int somme=NULL;
	int size=NULL;
	double average;
	int GL;
	double variance;
	double DS;
	double deviance;
	std::list<double> deviation;
	std::list<double> power2_deviation;
	}
	advanced(const std::string& name, const std::list<int>& l):dataset(name,l){
	somme =this->somme();
	size=this->size();
	average=this->average();
	GL=this->GL();
	variance=this->variance();
	DS=this->DS();
	deviance=this->deviance();
	deviation=this->deviation();
	power2_deviation=this->power2_deviation();
	}

	double advanced::coeff_determinazione(const advanced& s1)const{
    double coeff =0;
    double correlazione =correlazione(s1)*100;
    coeff =(correlazione*correlazione)/10000;
    return coeff;
}

