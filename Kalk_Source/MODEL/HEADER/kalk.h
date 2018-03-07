#ifndef KALK_H
#define KALK_H

#include<iostream>
#include<list>
#include<string>
#include<typeinfo>
#include"numbers.h"
#include"UniverseSet.h"
#include "UniverseDataset.h"
#include"UniverseAdvanced.h"
#include "GUI/HEADER/qcustomplot.h"

class kalk{
private:
    numbers* operand1;
    numbers* operand2;
    std::string* operation;
    numbers* result;
    std::list<const numbers*> Uset;
    DatasetUniverse* Duni;
    SetUniverse* Suni;
    AdvancedUniverse* Auni;
    std::string status;
    unsigned int setVuoti;
    unsigned int datasetVuoti;
    unsigned int advancedVuoti;
public:
    kalk();
    std::string SetValue(std::string);
    std::string SetOperand(std::string&, std::string);
    void SetOperation(std::string);
    std::string multiOperation();
    std::string singleOperation();
    void SaveResult();
    dataset* getDataset(std::string)const;
    void add_set(const numbers&);
    void sub_set(const std::string);
    void add_elements(const std::string name,const std::list<int>&)const;
    void sub_elements(const std::string name,const std::list<int>&);
    void sostitution(const set&);
    bool in(const int,std::string)const;
    std::list<std::string> ListNumbers()const;
    void clear();
    std::string getStatus()const;
    void setStatus(std::string);
    void resetkalk();
    std::string getVoidNumbers();

    ~kalk();
};

#endif // KALK_H
