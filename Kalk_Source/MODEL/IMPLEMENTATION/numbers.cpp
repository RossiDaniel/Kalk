#include "MODEL/HEADER/numbers.h"

numbers::numbers(const std::string& nm): name(nm) {}
std::string numbers::get_name() const{return name;}
void numbers::change_name(std::string nm){name=nm;}
numbers::~numbers(){}
