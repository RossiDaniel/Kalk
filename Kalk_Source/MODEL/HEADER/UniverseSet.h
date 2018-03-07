#ifndef SETUNIVERSE_H
#define SETUNIVERSE_H
#include"Set.h"

class SetUniverse{
public:
    set& Union(const set&,const set&)const;
    set& Intersection(const set&, const set&)const;
    set& Difference(const set&, const set&)const;
    set& SymmetricDifference(const set&, const set&)const;
    std::string CartesianProduct(const set&, const set&)const;
    std::string PowerSet(const set&)const;

};

#endif //SETUNIVERSE_H
