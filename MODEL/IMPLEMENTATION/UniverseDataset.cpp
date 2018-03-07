
#include"MODEL/HEADER/UniverseDataset.h"

std::string DatasetUniverse::somme(const dataset& d)const{
    return "Somme =" + std::to_string(d.somme());
}
std::string DatasetUniverse::size(const dataset& d)const{
    return "Size =" + std::to_string(d.size());
}
std::string DatasetUniverse::average(const dataset& d)const{
    return "Average =" + std::to_string(d.average());
}
std::string DatasetUniverse::gl(const dataset& d)const{
    return "GL =" + std::to_string(d.GL());
}
std::string DatasetUniverse::variance(const dataset& d)const{
    return "Variance =" + std::to_string(d.variance());
}
std::string DatasetUniverse::ds(const dataset& d)const{
    return "DS =" + std::to_string(d.DS());
}
std::string DatasetUniverse::deviance(const dataset& d)const{
    return "Deviance =" + std::to_string(d.deviance());
}
std::string DatasetUniverse::deviation(const dataset& d)const{
    std::list<double> l =d.deviation();
    std::string str="deviation =(";
    std::list<double>::const_iterator cit=l.begin();
    for(;cit!=l.end();cit++){
        str = str + " " +std::to_string(*cit) + " ";
    }
    str=str+")";
    return str;
}
std::string DatasetUniverse::deviation2(const dataset& d)const{
    std::list<double> l =d.power2_deviation();
    std::string str="deviation^2 =(";
    std::list<double>::const_iterator cit=l.begin();
    for(;cit!=l.end();cit++){
        str = str + " " +std::to_string(*cit) + " ";
    }
    str=str+")";
    return str;
}
