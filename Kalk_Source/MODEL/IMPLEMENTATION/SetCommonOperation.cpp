
#include"MODEL/HEADER/SetCommonOperation.h"

    set& SetCommonOperation::Union(const set& s1,const set& s2)const{
        return s1 + s2;
	}
	
    set& SetCommonOperation::Intersection(const set& s1, const set& s2)const{
        return s1 / s2;
	}

    set& SetCommonOperation::Difference(const set& s1, const set& s2)const{
        return s1 - s2;
	}

    set& SetCommonOperation::SymmetricDifference(const set& s1, const set& s2)const{
        return s1 % s2;
	}
	
    std::string SetCommonOperation::CartesianProduct(const set& s1, const set& s2)const {
        return s1 * s2;
	}
	
    std::string SetCommonOperation::PowerSet(const set& s1)const {
        return s1.partition();
	}
