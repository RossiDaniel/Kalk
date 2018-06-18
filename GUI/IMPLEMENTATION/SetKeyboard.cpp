#include "GUI/HEADER/SetKeyboard.h"

SetKeyboard::SetKeyboard(){
    configure();
}

SetKeyboard::~SetKeyboard(){}

std::vector<QString> SetKeyboard::getSingleOperationkeyboard()const{
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Complement");          //index 0
    VofButtonName.push_back("PowerSet()");          //index 1
    return VofButtonName;
}

std::vector<QString> SetKeyboard::getMultiOperationkeyboard()const{
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Union");               //index 0
    VofButtonName.push_back("Intercetion");         //index 1
    VofButtonName.push_back("Difference");          //index 2
    VofButtonName.push_back("SymmetricalDif");     //index 3
    VofButtonName.push_back("CartesianProd");       //index 4
    return VofButtonName;
}

std::vector<QString> SetKeyboard::getExtraOperationkeyboard()const{
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("Save");                //index 0
    VofButtonName.push_back("=");                   //index 1
    return VofButtonName;
}

