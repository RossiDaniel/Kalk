#include "MODEL/HEADER/abstractlogic.h"
AbstractLogic::AbstractLogic(QString name): nameType(name) {}
AbstractLogic::~AbstractLogic(){}
void AbstractLogic::getNameType(){
    emit setBarra(QString("Kalk is set on "+nameType+" type."));
}
