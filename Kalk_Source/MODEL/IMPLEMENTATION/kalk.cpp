#include "MODEL/HEADER/kalk.h"

kalk::kalk():operand1(0),operand2(0),operation(0),result(0){
    Uset.push_back(new set("U"));
    Duni = new DatasetUniverse();
    Suni = new SetUniverse();
    Auni = new AdvancedUniverse();
    status="set";
    setVuoti=0;
    datasetVuoti=0;
    advancedVuoti=0;
}

std::string kalk::SetValue(std::string name){
    if(status == "set"){
        if(name == "U"){throw std::string(*(const_cast<set*>(static_cast<const set*>(*(Uset.begin())))));}
    }
    if(!operand1){
        return SetOperand(name,"Operand1");
    }
    else{
        if(!operation){
            return SetOperand(name,"Operand1");
        }
        else{
            return SetOperand(name,"Operand2");
        }
    }
}

std::string kalk::SetOperand(std::string& name, std::string op){
    numbers* p=0;
    if(status == "set"){
        for(std::list<const numbers*>::const_iterator cit=Uset.begin(); cit!=Uset.end(); cit++){
            if((*cit)->get_name() == name && dynamic_cast<const set*>(*cit)){
                if(op == "Operand1"){
                    if(operand1){delete operand1;operand1=0;}
                    operand1 = (*cit)->clone();
                    p= operand1;
                }
                else{
                    if(operand2){delete operand2;operand2=0;}
                    operand2 = (*cit)->clone();
                    p= operand2;
                }
            }
        }
    }
        if(status == "dataset"){
        for(std::list<const numbers*>::const_iterator cit=Uset.begin(); cit!=Uset.end(); cit++){
            if((*cit)->get_name() == name && dynamic_cast<const dataset*>(*cit)){
                if(op == "Operand1"){
                    if(operand1){delete operand1;operand1=0;}
                    operand1 = (*cit)->clone();
                    p= operand1;
                }
                else{
                    if(operand2){delete operand2;operand2=0;}
                    operand2 = (*cit)->clone();
                    p= operand2;
                }
            }
        }
    }
        if(status == "advanced"){
        for(std::list<const numbers*>::const_iterator cit=Uset.begin(); cit!=Uset.end(); cit++){
            if((*cit)->get_name() == name && dynamic_cast<const advanced*>(*cit)){
                if(op == "Operand1"){
                    if(operand1){delete operand1;operand1=0;}
                    operand1 = (*cit)->clone();
                    p= operand1;
                }
                else{
                    if(!operand2){delete operand2;operand2=0;}
                    operand2 = (*cit)->clone();
                    p= operand2;
                }
            }
        }
    }
    return *p;
}

void kalk::SetOperation(std::string name){
    if(!operand1){throw std::string("Exception : an operand must be chosen before an operation is selected.");}
    if(operation){delete operation;operation=0;delete operand2;operand2=0;}
    operation = new std::string(name);
}

void kalk::add_set(const numbers& s){
    std::string name =s.get_name();
    std::string str;
    bool sent=false;
    if(status == "set"){
        std::string name =s.get_name();
        for(std::list<const numbers*>::iterator it= Uset.begin(); it!=Uset.end() && !sent; it++){
            if((*it)->get_name() == name && dynamic_cast<const set*>(*it)){
                sent =true;
                str="Exception: a SET named '"+ name +"' already exists in the universe.";
            }
        }
        if(!sent){
            Uset.push_back(const_cast<numbers*>((s.clone())));
            set* n=const_cast<set*>(static_cast<const set*>(*(Uset.begin())));
            *n =Suni->Union(*n,*const_cast<set*>(dynamic_cast<const set*>(&s)));
            ((const_cast<numbers*>(*Uset.begin())))->change_name("U");
        }
    }
    if(status == "dataset"){
        for(std::list<const numbers*>::iterator it= Uset.begin(); it!=Uset.end() && !sent; it++){
            if((*it)->get_name() == name && dynamic_cast<const dataset*>(*it)){
                sent =true;
                str="Exception: a DATASET named '"+ name +"' already exists.";
            }
        }
        if(!sent){
            Uset.push_back(const_cast<numbers*>((s.clone())));
        }
    }
    if(status == "advanced"){
        for(std::list<const numbers*>::iterator it= Uset.begin(); it!=Uset.end() && !sent; it++){
            if((*it)->get_name() == name){
                if(dynamic_cast<const dataset*>(*it)){
                    sent =true;
                    if(typeid(*it)==typeid(const dataset*)){
                        str="Exception: a DATASET named '"+ name +"' already exists.";
                    }
                    else{
                        str="Exception: a ADVANCED named '"+ name +"' already exists.";
                    }
                }
            }
        }
        if(!sent){
            Uset.push_back(const_cast<numbers*>((s.clone())));
        }
    }
    const numbers* p=&s;
    delete p;
    if(sent){
        throw std::string(str);
    }
}

void kalk::sub_set(const std::string name){
    if(status == "set" && name == "U"){throw std::string("Exception: the 'U' Set cannot be eliminated.");}
    bool sent =false;
    std::list<const numbers*>::iterator it= Uset.begin();
    for(; it!=Uset.end() && !sent; it++){
        if( status == "set" && (*it)->get_name() == name  && dynamic_cast<const set*>(*it)){
            sent =true;
            std::list<int> l= (static_cast<const set*>(*it))->get_element();
            std::list<int>::const_iterator cit= l.begin();
            bool found =false;
            for(; cit!=l.end(); cit++){
                found =this->in(*cit,name);
                if(!found){const_cast<set*>(static_cast<const set*>(*Uset.begin()))->sub_value(*cit);}
            }
            delete *it;
            it=Uset.erase(it);
        }
        if( status == "dataset" && (*it)->get_name() == name  && dynamic_cast<const dataset*>(*it)){
            sent =true;
            delete *it;
            it=Uset.erase(it);
        }
        if( status == "advanced" && (*it)->get_name() == name  && dynamic_cast<const advanced*>(*it)){
            sent =true;
            delete *it;
            it=Uset.erase(it);
        }
    }
    if(!sent){throw std::string("Exception : "+status+" not found.");}
}

void kalk::add_elements(const std::string name,const std::list<int>& l)const{
    bool sent =false;
    std::list<const numbers*>::const_iterator cit= Uset.begin();
    for(; cit!=Uset.end() && !sent; cit++){
        if((*cit)->get_name() == name && dynamic_cast<const set*>(*cit)){
            sent =true;
            if(name != "U"){(const_cast<numbers*>(*cit))->add_list(l);}
            (const_cast<numbers*>(*Uset.begin()))->add_list(l);
        }
    }
    if(!sent){throw std::string("Exception : "+name+" not found.");}
}

void kalk::sub_elements(const std::string name,const std::list<int>& l){
    this->resetkalk();
    bool sent =false;
    if(name == "U"){
        sent=true;
        std::list<const numbers*>::const_iterator cit= Uset.begin();
        for(; cit!=Uset.end(); cit++){
            if(dynamic_cast<const set*>(*cit)){
                (const_cast<numbers*>(*cit))->sub_list(l);
            }
        }
    }
    else{
        std::list<const numbers*>::const_iterator cit= Uset.begin();
        for(; cit!=Uset.end() && !sent; cit++){
            if((*cit)->get_name() == name && dynamic_cast<const set*>(*cit)){
                sent =true;
                std::list<int>::const_iterator lcit= l.begin();
                for(;lcit!=l.end(); lcit++){
                    bool found=this->in(*lcit,name);
                    (const_cast<numbers*>(*cit))->sub_value(*lcit);
                    if(!found){(const_cast<numbers*>(*Uset.begin()))->sub_value(*lcit);}
                }
            }
        }
    }
    if(!sent){throw std::string("Exception : "+status+" not found.");}
}

bool kalk::in(const int n,std::string name)const{
    bool sent=false;
    std::list<const numbers*>::const_iterator cit= Uset.begin();
        cit++;
        for(; cit!=Uset.end() && !sent; cit++){
            if(dynamic_cast<const set*>(*cit) && (*cit)->get_name()!=name){
                sent=static_cast<const set*>(*cit)->search(n);
            }
        }
    return sent;
}

std::list<std::string> kalk::ListNumbers()const{
    std::list<std::string> l;
    if(status == "set"){
        for(std::list<const numbers*>::const_iterator cit= Uset.begin(); cit!=Uset.end(); cit++){
            if(dynamic_cast<const set*>(*cit)){
                l.push_back((*cit)->get_name());
            }
        }
    }
    if(status == "dataset"){
        for(std::list<const numbers*>::const_iterator cit= Uset.begin(); cit!=Uset.end(); cit++){
            if(dynamic_cast<const dataset*>(*cit)){
                l.push_back((*cit)->get_name());
            }
        }
    }
    if(status == "advanced"){
        for(std::list<const numbers*>::const_iterator cit= Uset.begin(); cit!=Uset.end(); cit++){
            if(dynamic_cast<const advanced*>(*cit)){
                l.push_back((*cit)->get_name());
            }
        }
    }

    return l;
}

void kalk::clear(){
    std::list<const numbers*>::iterator it=Uset.begin();
    if(status == "set"){
        (const_cast<numbers*>(*it))->clear();
        it++;
        for(;it!=Uset.end(); it++){
            if(dynamic_cast<const set*>(*it)){
                it=Uset.erase(it);
                it--;
            }
        }
        setVuoti=0;
    }
    if(status == "dataset"){
        for(;it!=Uset.end(); it++){
            if(dynamic_cast<const dataset*>(*it) && !dynamic_cast<const advanced*>(*it)){
                it=Uset.erase(it);
                it--;
            }
        }
        datasetVuoti=0;
    }
    if(status == "advanced"){
        for(;it!=Uset.end(); it++){
            if(dynamic_cast<const advanced*>(*it)){
                it=Uset.erase(it);
                it--;
            }
        }
        advancedVuoti=0;
    }
    this->resetkalk();
}
std::string kalk::singleOperation(){
    if(!operand1){throw std::string("Exception :first operand not selected.");}
    if(!operation){throw std::string("Exception :operation not selected.");}
    if(result){delete result;result=0;}

    //OPERAZIONI CHE RICHIEDONO UN SOLO OPERANDO
    std::string str;
    if(status == "set"){
        const set* s1=dynamic_cast<const set*>(operand1);
        if(!s1){throw std::string("System exception: fatal error, restart kalk.");}
        if(*operation == "complement"){
            result = new set(Suni->Difference(*dynamic_cast<const set*>(*(Uset.begin())),*s1));
            result->change_name("!" + operand1->get_name());
            str=*result;
        }
        if(*operation == "powerset"){
            str=Suni->PowerSet(*s1);
        }
    }
    if(status == "dataset"){
        dataset* d=dynamic_cast<dataset*>(operand1);
        if(!d){throw std::string("System exception: fatal error, restart kalk.");}
        if(*operation == "somme"){
            str=Duni->somme(*d);
        }
        if(*operation == "size"){
            str=Duni->size(*d);
        }
        if(*operation == "average"){
            str=Duni->average(*d);
        }
        if(*operation == "gl"){
            str=Duni->gl(*d);
        }
        if(*operation == "variance"){
            str=Duni->variance(*d);
        }
        if(*operation == "ds"){
            str=Duni->ds(*d);
        }
        if(*operation == "deviance"){
            str=Duni->deviance(*d);
        }
        if(*operation == "deviation"){
            str=Duni->deviation(*d);
        }
        if(*operation == "deviation^2"){
            str=Duni->deviation2(*d);
        }
    }
    if(operand2){delete operand2;}
    if(operation){delete operation;}
    operand2=0;
    operation=0;
    return str;
}
std::string kalk::multiOperation(){

    if(!operand1){throw std::string("Exception :first operand not selected.");}
    if(!operation){throw std::string("Exception :operation not selected.");}
    if(!operand2){throw std::string("Exeption :second operand not selected.");}
    if(result){delete result;result=0;}
    std::string str;
        //OPERAZIONI CHE RICHIEDONO DUE OPERANDI
    if(status == "set"){
        if(result){delete result;result=0;}
        set* s1=dynamic_cast<set*>(operand1);
        set* s2=dynamic_cast<set*>(operand2);
        if(!s1 || !s2){throw std::string("System exception: fatal error, restart kalk.");}
        if(*operation == "union"){
            result = new set(Suni->Union(*s1,*s2));
            str=*result;
        }
        if(*operation == "intercetion"){
            result = new set(Suni->Intersection(*s1,*s2));
            str=*result;
        }
        if(*operation == "difference"){
            result = new set(Suni->Difference(*s1,*s2));
            str=*result;
        }
        if(*operation == "symmetricaldifference"){
            result = new set(Suni->SymmetricDifference(*s1,*s2));
            str=*result;
        }

        if(*operation == "cartesianproduct"){
            str=Suni->CartesianProduct(*s1,*s2);
        }
    }
    if(status == "advanced"){
        advanced* s1=dynamic_cast<advanced*>(operand1);
        advanced* s2=dynamic_cast<advanced*>(operand2);
        if(!s1 || !s2){throw std::string("System exception: fatal error, restart kalk.");}
        if(*operation == "coscarto"){
            str =Auni->coscarto(*s1,*s2);
        }

        if(*operation == "codevianza"){
            str =Auni->codevianza(*s1,*s2);
        }

        if(*operation == "covarianza"){
            str =Auni->covarianza(*s1,*s2);
        }

        if(*operation == "correlazione"){
            str =Auni->correlazione(*s1,*s2);
        }

        if(*operation == "correllazione^2"){
            str =Auni->coeff_determinazione(*s1,*s2);
        }

        if(*operation == "regressione"){
            str =Auni->regressione(*s1,*s2);
        }

        if(*operation == "intercetta"){
            str =Auni->intercetta(*s1,*s2);
        }

        if(*operation == "allinfo"){
            str =Auni->coscarto(*s1,*s2);
            str =str +" \r\n";
            str =str +Auni->codevianza(*s1,*s2);
            str =str +" \r\n";
            str =str +Auni->covarianza(*s1,*s2);
            str =str +" \r\n";
            str =str +Auni->correlazione(*s1,*s2);
            str =str +" \r\n";
            str =str +Auni->coeff_determinazione(*s1,*s2);
            str =str +" \r\n";
            str =str +Auni->regressione(*s1,*s2);
            str =str +" \r\n";
            str =str +Auni->intercetta(*s1,*s2);

        }
        if(*operation == "grafic"){
            advanced* s1=static_cast<advanced*>(operand1);
            advanced* s2=static_cast<advanced*>(operand2);

            double regression =s1->regressione(*s2);
            double intercection =s1->intercetta(*s2);
            QCustomPlot* customPlot= new QCustomPlot();
            // generate some data:
            QVector<double> x(100), y(100), x1(s1->dataset::size()), y1(s1->dataset::size());
            for (int i=0; i<100; ++i)
            {
              x[i] = i-50;
              y[i] = regression*x[i]+intercection;
            }
            std::list<int> l1=s1->get_element();
            std::list<int> l2=s2->get_element();
            std::list<int>::const_iterator cit1=l1.begin();
            std::list<int>::const_iterator cit2=l2.begin();
            for (int i=0; cit1!=l1.end(); ++i, cit1++, cit2++){
                x1[i]=*cit1;
                y1[i]=*cit2;
            }

            // create graph and assign data to it:
            customPlot->addGraph();
            customPlot->graph(0)->setData(x, y);
            customPlot->addGraph();
            customPlot->graph(1)->setData(x1,y1);
            customPlot->graph(1)->setLineStyle((QCPGraph::LineStyle)QCPGraph::lsNone);
            customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond,10));

            // give the axes some labels:
            customPlot->xAxis->setLabel("x");
            customPlot->yAxis->setLabel("y");
            // set axes ranges, so we see all data:
            customPlot->xAxis->setRange(-50, 50);
            customPlot->yAxis->setRange(-50, 50);
            customPlot->  setGeometry(400, 250, 542, 390);
            customPlot->replot();
            customPlot->show();
            double r = s1->correlazione(*s2);
            if(r == double(1) || r==double(-1)){
                str="correlazione perfetta :"+Auni->correlazione(*s1,*s2);
            }
            if((r>0 && r<1) || (r<0 && r>-1)){
                str="correllazione imperfetta"+Auni->correlazione(*s1,*s2);
            }
            if(r==double(0)){
                str="nessuna correlazione"+Auni->correlazione(*s1,*s2);
            }
        }
        if(*operation == "retta"){
            str = "Y = " + std::to_string(s1->regressione(*s2));
            double inter=s1->intercetta(*s2);
            if(inter > 0){
                str = str + "X +" +std::to_string(inter);
            }
            else{
                str = str + "X " +std::to_string(inter);
            }
        }
        if(operand1){delete operand1;}
        if(operand2){delete operand2;}
        if(operation){delete operation;}
        operand1=0;
        operand2=0;
        operation=0;
    }
    return str;
}

void kalk::SaveResult(){
    if(!result){throw std::string("Exception: it is not available any result at the moment");}
    this->sostitution(*(dynamic_cast<set*>(result->clone())));
}
void kalk::sostitution(const set& s){
    std::string name =s.get_name();
    bool sent=false;
    for(std::list<const numbers*>::iterator it= Uset.begin(); it!=Uset.end() && !sent; it++){
        if((*it)->get_name() == name && dynamic_cast<const set*>(*it)){
            sent =true;
            delete *it;
            *it=const_cast<set*>(&s);
        }
    }
    if(!sent){
        Uset.push_back(const_cast<set*>(&s));
    }
}
std::string kalk::getStatus()const{
    return status;
}

dataset* kalk::getDataset(std::string name)const{
    dataset* d=0;
    bool sent =false;
    std::list<int> l;
    std::list<const numbers*>::const_iterator cit= Uset.begin();
    for(; cit!=Uset.end() && !sent; cit++){
        if((*cit)->get_name() == name  && dynamic_cast<const dataset*>(*cit)){
            d=const_cast<dataset*>(static_cast<const dataset*>(*cit));
            sent=true;
        }
}
    if(!sent){throw std::string("Execption : DATASET not found");}
    return d;
}

void kalk::setStatus(std::string s){
    status =s;
}

void kalk::resetkalk(){
    if(operand1){delete operand1;}
    if(operand2){delete operand2;}
    if(operation){delete operation;}
    if(result){delete result;}
    operand1=0;
    operand2=0;
    operation=0;
    result=0;
}

kalk::~kalk(){
    this->resetkalk();
    delete Suni;
    delete Duni;
    delete Auni;
    for(std::list<const numbers*>::const_iterator cit =Uset.begin();cit!=Uset.end(); cit++){
        delete *cit;
    }
}

std::string kalk::getVoidNumbers(){
    unsigned int nVuoto=0;
    if(status == "set"){
        setVuoti++;
        nVuoto=setVuoti;
    }
    if(status == "dataset"){
        datasetVuoti++;
        nVuoto=datasetVuoti;
    }
    if(status == "advanced"){
        advancedVuoti++;
        nVuoto=advancedVuoti;
    }
    return status+"Void"+std::to_string(nVuoto);
}
