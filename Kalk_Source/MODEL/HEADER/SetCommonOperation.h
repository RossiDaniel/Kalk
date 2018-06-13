#ifndef SETCOMMONOPERATION_h
#define SETCOMMONOPERATION_h
#include"Set.h"

class SetCommonOperation{
public:
    set& Union(const set&,const set&)const;
    set& Intersection(const set&, const set&)const;
    set& Difference(const set&, const set&)const;
    set& SymmetricDifference(const set&, const set&)const;
    std::string CartesianProduct(const set&, const set&)const;
    std::string PowerSet(const set&)const;

};

#endif //SETCOMMONOPERATION_h
