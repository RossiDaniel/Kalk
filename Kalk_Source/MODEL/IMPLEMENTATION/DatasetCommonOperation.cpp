
#include"MODEL/HEADER/DatasetCommonOperation.h"

std::string DatasetCommonOperation::somme(const dataset& d)const{
    return "Somme =" + std::to_string(d.somme());
}
std::string DatasetCommonOperation::size(const dataset& d)const{
    return "Size =" + std::to_string(d.size());
}
std::string DatasetCommonOperation::average(const dataset& d)const{
    return "Average =" + std::to_string(d.average());
}
std::string DatasetCommonOperation::gl(const dataset& d)const{
    return "GL =" + std::to_string(d.GL());
}
std::string DatasetCommonOperation::variance(const dataset& d)const{
    return "Variance =" + std::to_string(d.variance());
}
std::string DatasetCommonOperation::ds(const dataset& d)const{
    return "DS =" + std::to_string(d.DS());
}
std::string DatasetCommonOperation::deviance(const dataset& d)const{
    return "Deviance =" + std::to_string(d.deviance());
}
std::string DatasetCommonOperation::deviation(const dataset& d)const{
    std::list<double> l =d.deviation();
    std::string str="deviation =(";
    std::list<double>::const_iterator cit=l.begin();
    for(;cit!=l.end();cit++){
        str = str + " " +std::to_string(*cit) + " ";
    }
    str=str+")";
    return str;
}
std::string DatasetCommonOperation::deviation2(const dataset& d)const{
    std::list<double> l =d.power2_deviation();
    std::string str="deviation^2 =(";
    std::list<double>::const_iterator cit=l.begin();
    for(;cit!=l.end();cit++){
        str = str + " " +std::to_string(*cit) + " ";
    }
    str=str+")";
    return str;
}
