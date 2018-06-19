#ifndef DATASETCOMMONOPERATION_H
#define DATASETCOMMONOPERATION_H
#include"Dataset.h"

class DatasetCommonOperation{
public:
    std::string somme(const dataset&)const;
    std::string size(const dataset&)const;
    std::string average(const dataset&)const;
    std::string gl(const dataset&)const;
    std::string variance(const dataset&)const;
    std::string ds(const dataset&)const;
    std::string deviance(const dataset&)const;
    std::string deviation(const dataset&)const;
    std::string deviation2(const dataset&)const;


};

#endif //DATASETCOMMONOPERATION_H
