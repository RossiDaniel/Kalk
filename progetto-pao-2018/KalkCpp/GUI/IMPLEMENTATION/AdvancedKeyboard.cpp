#include "GUI/HEADER/AdvancedKeyboard.h"

AdvancedKeyboard::AdvancedKeyboard(){
    configure();
}

AdvancedKeyboard::~AdvancedKeyboard(){

}

std::vector<QString> AdvancedKeyboard::getSingleOperationkeyboard() const{
    std::vector<QString> VofButtonName;
    return VofButtonName;
}

std::vector<QString> AdvancedKeyboard::getMultiOperationkeyboard() const{
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("All Info");        //index 0
    VofButtonName.push_back("Coscarto");        //index 1
    VofButtonName.push_back("Codevianza");      //index 2
    VofButtonName.push_back("Covarianza");      //index 3
    VofButtonName.push_back("Correlazione");    //index 4
    VofButtonName.push_back("Coef. Determ.");   //index 5
    VofButtonName.push_back("Regressione");     //index 6
    VofButtonName.push_back("Intercetta");      //index 7
    VofButtonName.push_back("Retta");           //index 8
    VofButtonName.push_back("Grafic");          //index 9
    return VofButtonName;
}

std::vector<QString> AdvancedKeyboard::getExtraOperationkeyboard()const{
    std::vector<QString> VofButtonName;
    VofButtonName.push_back("=");               //index 0
    return VofButtonName;
}
