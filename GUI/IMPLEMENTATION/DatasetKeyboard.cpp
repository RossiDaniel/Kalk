#include "GUI/HEADER/DatasetKeyboard.h"

DatasetKeyboard::DatasetKeyboard(){
    configure();
}

DatasetKeyboard::~DatasetKeyboard(){

}

std::vector<QString> DatasetKeyboard::getSingleOperationkeyboard()const{
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Somme");           //index 0
    VofButtonName.push_back("Size");            //index 1
    VofButtonName.push_back("Average");         //index 2
    VofButtonName.push_back("GL");              //index 3
    VofButtonName.push_back("Variance");        //index 4
    VofButtonName.push_back("DS");              //index 5
    VofButtonName.push_back("Deviance");        //index 6
    VofButtonName.push_back("Deviation");       //index 7
    VofButtonName.push_back("Deviation^2");     //index 8

    return VofButtonName;
}

std::vector<QString> DatasetKeyboard::getMultiOperationkeyboard()const{
    std::vector<QString> VofButtonName;
    return VofButtonName;
}

std::vector<QString> DatasetKeyboard::getExtraOperationkeyboard() const{
    std::vector<QString> VofButtonName;
    return VofButtonName;
}
