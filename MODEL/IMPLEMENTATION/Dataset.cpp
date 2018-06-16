#include"MODEL/HEADER/Dataset.h"
#include<math.h>

dataset::dataset(const std::string& nm, const std::list<int>& l):numbers(nm) {
    element=l;
    if(l.size()<2){
        for(unsigned int i=0; i<2-l.size();i++){
            element.push_back(0);
        }
    }
}


numbers::ris* dataset::in_const(const int n)const{
	ris* x =new ris();
    for ( std::list<int>::const_iterator it =element.begin(); it != element.end(); it++){
        if(*it == n){
			x->is =true;
			x->various.push_back(*it);
		}
	}
	return x;
}

numbers::ris* dataset::in(const int n){
    for ( std::list<int>::iterator it =element.begin(); it != element.end(); it++){
        if(*it == n){
			return new ris(true,it);
		}
	}
	return new ris();	
}

dataset* dataset::clone()const{
    return new dataset(*this);
}

void dataset::add_value(const int n){
    element.push_back(n);
}

void dataset::sub_value(const int n){
    ris* x =in(n);
    if(x->is){
        std::list<int>::iterator it=x->iterator;
        element.erase(it);
    }
    delete x;
}

void dataset::add_list(const std::list<int>& l){
    element =l;
    if(l.size()<2){
        for(unsigned int i=0; i<2-l.size();i++){
            element.push_back(0);
        }
    }
}
void dataset::sub_list(const std::list<int>& l){
    for (std::list<int>::const_iterator it =l.begin(); it != l.end(); it++){
        this->sub_value(*it);
    }
}

int dataset::somme()const{
	int somme =0;
    for (std::list<int>::const_iterator it =element.begin(); it != element.end(); it++){
		somme =somme + *it;
	}
	return somme;
}

int dataset::size() const{
	return element.size();
}

double dataset::average()const{
	double somme =this->somme();
	double size =this->size();
	return somme / size;
}

int dataset::GL()const{
	return element.size()-1;
}

double dataset::variance()const{
	double deviance =this->deviance();
	int GL =this->GL();
	double variance =deviance/GL;
	return variance;
}
double dataset::DS()const{
	double variance =this->variance();
	return sqrt(variance);
}

double dataset::deviance()const{
	std::list<double> l =this->power2_deviation();
	double deviance =0;
    for (std::list<double>::const_iterator it =l.begin(); it != l.end(); it++){ 		
		deviance =deviance+*it;
	}
	return deviance;
}

std::list<double> dataset::deviation()const{
	std::list<double> l;
	double average =this->average();
    for (std::list<int>::const_iterator it =element.begin(); it != element.end(); it++){
        l.push_back(static_cast<double>(*it) - average );
	}
	return l;
}


std::list<double> dataset::power2_deviation()const{
	std::list<double> l =this->deviation();
    for (std::list<double>::iterator it =l.begin(); it != l.end(); it++){ 		
		*it =*it * *it;
	}
	return l;
}


std::list<int> dataset::operator*(const dataset& s) const{
    std::list<int> l;
    if(element.size() == s.element.size()){
    std::list<int>::const_iterator it1 = element.begin();
    std::list<int>::const_iterator it2 =s.element.begin();
    for (; it1 != element.end(); it1++,it2++){
            l.push_back(*it1 * *it2);
        }
    }
    return l;
}


dataset& dataset::operator=(const dataset* s){
	if(*this != *s){
		element =s->get_element();
		this->change_name(s->get_name());
		delete s;
	}
	return *this;	
}

bool dataset::operator!=(const dataset& s)const{
    std::list<int> l =s.get_element();
	if(element.size() == l.size() && this->get_name() == s.get_name() && element == l){
		return false;}
	return true;
}

dataset::operator std::string(){
    std::string dset;
    dset= this->get_name();
    dset +="={";
    std::list<int>::const_iterator cit = element.begin();
    if(!element.empty()){

        dset +=std::to_string(*cit);
        cit++;
    }
    for (; cit != element.end(); cit++){
        dset+=", "+ std::to_string(*cit);;
    }
    dset+="}";
    return dset;
}

std::string dataset::name() const{
    return std::string("dataset");
}

void dataset::checkpoint(const dataset& s)const{
    bool sent=false;
    std::list<int>::const_iterator cit1=element.begin();
    std::list<int>::const_iterator cit2=s.element.begin();

    for(; cit1!=element.end() && !sent; cit1++, cit2++){
        if(*cit1 != *cit2){
            sent=true;
        }
    }
    if(sent == false){
        std::list<int>::const_iterator cit3=element.begin();
        std::list<int>::const_iterator cit4=s.element.begin();
        int n1= *element.begin();
        for(; cit3!=element.end() && !sent; cit3++){
            if(n1 != *cit3){sent=true;}
        }

        int n2= *s.element.begin();
        for(; cit4!=s.element.end() && !sent; cit4++){
            if(n2 != *cit4){sent=true;}
        }
        if(sent == false){
            throw std::string("Exception : you cannot execute this operation on equals advanced dataset.");
        }
    }
}
