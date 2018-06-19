#include "MODEL/HEADER/numbers.h"

numbers::numbers(const std::string& nm): Name(nm) {}
std::string numbers::get_name() const{return Name;}
void numbers::change_name(std::string nm){Name=nm;}
numbers::~numbers(){}
