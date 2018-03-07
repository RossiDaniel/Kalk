#ifndef SET_H
#define SET_H

#include"numbers.h"
#include<vector>

class set: public numbers{
private:
	std::list<int> element;
public:
    set(const std::string&);
    set(const std::string&, const std::list<int>&);

    ris* in_const(const int) const;
    ris* in(const int);
    bool search(const int n)const;

	std::list<int> get_element() const{return element;}
	void clear(){element.clear();}

    virtual set* clone() const;
    operator std::string();

	void add_value(const int);
	void add_list(const std::list<int>&);
	void add_value_without_control(const int n);
	void add_list_without_control(const std::list<int>&);
	void sub_value(const int);
	void sub_list(const std::list<int>&);

    std::string partition()const;
    std::string combination(int, int, std::vector<int>&)const;

	bool operator==(const set&);
	bool operator!=(const set&);
	set& operator=(const set*);

	set& operator+(const set&) const;
	set& operator-(const set&) const;
	set& operator/(const set&) const;
	set& operator%(const set&) const;
    std::string operator*(const set&) const;

};

#endif //SET_H
