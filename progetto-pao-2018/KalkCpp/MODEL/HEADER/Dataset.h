#ifndef DATASET_H
#define DATASET_H
#include"numbers.h"

class dataset: public numbers{
private:
        std::list<int> element;
public:
	dataset(const std::string&, const std::list<int>&);

    ris* in_const(const int)const;
    ris* in(const int);

    std::list<int> get_element() const{return element;}
	void clear(){element.clear();}

    dataset* clone() const;
    operator std::string();
    std::string name() const;

    void add_value(const int);
    void sub_value(const int);
	void add_list(const std::list<int>&);
    void sub_list(const std::list<int>&);

	int somme()const;
	int size() const ;
	double average()const;
	int GL()const;
	double variance()const;
	double DS()const;
	double deviance()const;
	std::list<double> deviation()const;
	std::list<double> power2_deviation()const;	
    void checkpoint(const dataset& s)const;
	bool operator!=(const dataset&)const;
	dataset& operator=(const dataset*);
    std::list<int> operator*(const dataset&) const;

};

#endif //DATASET_H
