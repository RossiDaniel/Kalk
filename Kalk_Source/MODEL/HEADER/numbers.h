#ifndef NUMBERS_H
#define NUMBERS_H

#include<iostream>
#include<string>
#include<list>

class numbers{
private:
    std::string Name;
protected:
    class ris{
    public:
        bool is;
        std::list<int>::const_iterator single;
        std::list<int>::iterator iterator;
        std::list<int> various;

        ris();
        ris(bool a,std::list<int>::iterator b);
        ris(bool a,std::list<int>::const_iterator b);
        ris(bool a,std::list<int> c);
        ~ris();

        operator bool();
    };
public:
    numbers(const std::string& nm);
    virtual ~numbers();

    virtual ris* in_const(const int) const=0;
    virtual ris* in(const int) =0;

    std::string get_name() const;
    void change_name(std::string nm);

    virtual numbers* clone() const =0;
    virtual std::string name() const =0;
    virtual operator std::string()=0;
    virtual void clear()=0;

    virtual void add_value(const int) =0;
    virtual void sub_value(const int) =0;
	virtual void add_list(const std::list<int>&) =0;
	virtual void sub_list(const std::list<int>&) =0;
};

#endif //NUMBERS_H
