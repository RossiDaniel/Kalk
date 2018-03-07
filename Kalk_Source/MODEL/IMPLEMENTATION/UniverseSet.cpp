
#include"MODEL/HEADER/UniverseSet.h"

    set& SetUniverse::Union(const set& s1,const set& s2)const{
        return s1 + s2;
	}
	
    set& SetUniverse::Intersection(const set& s1, const set& s2)const{
        return s1 / s2;
	}

    set& SetUniverse::Difference(const set& s1, const set& s2)const{
        return s1 - s2;
	}

    set& SetUniverse::SymmetricDifference(const set& s1, const set& s2)const{
        return s1 % s2;
	}
	
    std::string SetUniverse::CartesianProduct(const set& s1, const set& s2)const {
        return s1 * s2;
	}
	
    std::string SetUniverse::PowerSet(const set& s1)const {
        return s1.partition();
	}
