
#include"MODEL/HEADER/Set.h"

set::set(const std::string& nm  ): numbers(nm) {}

set::set(const std::string& nm, const std::list<int>& l):numbers(nm) {
	this->add_list(l);
}

numbers::ris* set::in_const(const int n)const{
    for ( std::list<int>::const_iterator it =element.begin(); it != element.end(); it++){
        if(*it == n){
			return new ris(true,it);

		}
	}
	return new ris();
}

numbers::ris* set::in(const int n){
    for ( std::list<int>::iterator it =element.begin(); it != element.end(); it++){
    	if(*it == n){
			return new ris(true,it);
		}
	}
	return new ris();	
}

set* set::clone()const{
    return new set(*this);
}

void set::add_value(const int n){
    ris *x =in_const(n);
	if(!x->is){element.push_back(n);}
	delete x;
}


void set::add_list(const std::list<int>& l){
    for ( std::list<int>::const_iterator it =l.begin(); it != l.end(); it++){
        ris* x =in_const(*it);
		if(!x->is){element.push_back(*it);}
		delete x;
	}
}

void set::sub_value(const int n){
    ris* x =in(n);
	if(x->is){
        std::list<int>::iterator it = x->iterator;
		element.erase(it);
	}
	delete x;
}

void set::add_list_without_control(const std::list<int>& l){
	element =l;
}

void set::add_value_without_control(const int n){
	element.push_back(n);
}


void set::sub_list(const std::list<int>& l){
    for (std::list<int>::const_iterator it =l.begin(); it != l.end(); it++){
    	this->sub_value(*it);
	}
}
bool set::operator==(const set& s){
    if(this->get_name() == s.get_name() && element.size() == s.element.size() && element == s.element){
		return true;
	}
	return false;
}

bool set::operator!=(const set& s){
    if(this->get_name() == s.get_name() && element.size() == s.element.size() && element == s.element){
		return false;
	}
	return true;
}

set& set::operator=(const set* s){
	if(*this != *s){
        element =s->element;
		this->change_name(s->get_name());
		delete s;
	}
	return *this;	
}
set& set::operator+(const set& s) const{
	set* result =new set("( "+this->get_name()+" + "+s.get_name()+" )");
	result->add_list_without_control(element);
    result->add_list(s.element);
	return *result;
}

set& set::operator-(const set& s) const{
	set* result =new set("( "+this->get_name()+" - "+s.get_name()+" )");
	result->add_list_without_control(element);
    result->sub_list(s.element);
	return *result;
}

set& set::operator/(const set& s) const{
	set* result =new set("( "+this->get_name()+" / "+s.get_name()+" )");
    for (std::list<int>::const_iterator it =s.element.begin(); it != s.element.end(); it++){
        ris* x =in_const(*it);
		if(x->is){
			result->add_value_without_control(*it);
		}
		delete x;
	}
	return *result;
}

set& set::operator%(const set& s) const{
	set* result =new set("( "+this->get_name()+" % "+s.get_name()+" )");
	std::list<int> ins;
    for(std::list<int>::const_iterator it =s.element.begin(); it != s.element.end(); it++){
        ris* x =in_const(*it);
		if(!x->is){
			ins.push_back(*it);
		}
		delete x;
	}
	for(std::list<int>::const_iterator it =element.begin(); it != element.end(); it++){
        ris* x =s.in_const(*it);
		if(!x->is){
			ins.push_back(*it);
		}
		delete x;
	}
	result->add_list_without_control(ins);
	return *result;
}

std::string set::partition() const{
    if(element.size() > 15){throw std::string("Exception: the size is too big, it must be minus than 15.");}
    std::string str = "PowerSet( "+this->get_name()+" )= ";
    std::vector<int> pre;
    for(unsigned int i=0; i<=element.size(); i++){
        str += combination(i,0, pre);
        pre.clear();
    }
    return str + ");";
}

std::string set::combination(int n, int index, std::vector<int>& pre)const {
    std::string str="";
    if(n == 0){return str="{ }";}
    if(n == 1){
        std::string pres="(";
        for(unsigned int j=0; j < pre.size(); j++){
            pres+= std::to_string(pre[j])+", ";
        }

        std::list<int>::const_iterator cit=element.begin();
        for(int i=0; i< index; i++, cit++){}
        for(unsigned int i=index; i< element.size(); i++, cit++){
            str+= pres + std::to_string(*cit) + ");";
        }
        pre.pop_back();
        return str;
    }
    else{
        std::list<int>::const_iterator cit=element.begin();
        for(int k=0; k< index; k++, cit++){}
        for(unsigned int i=index; i<(element.size()-n+1); i++, cit++){
            pre.push_back(*cit);
            str+= combination(n-1,i+1,pre);
        }
        pre.pop_back();
    }
    return str;
}

std::string set::operator*(const set& s) const{
    std::string str = "( " + this->get_name() + " X " +s.get_name() +" ) = {";
	for(std::list<int>::const_iterator it1 =element.begin(); it1 != element.end(); it1++){
        for(std::list<int>::const_iterator it2 =s.element.begin(); it2 != s.element.end(); it2++){
            std::string n = str + "( " + std::to_string(*it1) + ","+ std::to_string(*it2) + " ),";
            str=n;
        }
	}
    str = str + " }";
    return str;
}

set::operator std::string(){
    std::string set;
    set= this->get_name();
    set +="={";
    std::list<int>::const_iterator cit = element.begin();
    if(!element.empty()){

        set +=std::to_string(*cit);
        cit++;
    }

    for (; cit != element.end(); cit++){
        set+=", "+ std::to_string(*cit);;
    }
    set+="}";
    return set;
}

bool set::search(const int n)const{
    for ( std::list<int>::const_iterator it =element.begin(); it != element.end(); it++){
        if(*it == n){
            return true;
        }
    }
    return false;
}
