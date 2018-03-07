#include "MODEL/HEADER/numbers.h"

numbers::ris::ris():is(false){}
numbers::ris::ris(bool a,std::list<int>::iterator b):is(a),iterator(b){}
numbers::ris::ris(bool a,std::list<int>::const_iterator b):is(a),single(b){}
numbers::ris::ris(bool a,std::list<int> c):is(a),various(c) {}
numbers::ris::~ris(){}

