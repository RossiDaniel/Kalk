
#include"MODEL/HEADER/AdvancedCommonOperation.h"

    std::string AdvancedCommonOperation::coscarto(const advanced& s1,const advanced& s2)const{
        std::list<double> coscart;
        std::string str("coscarto = (");

        coscart=s1.coscarto(s2);
        for(std::list<double>::const_iterator cit=coscart.begin(); cit!=coscart.end();cit++){
            str = str +" "+std::to_string(*cit)+ " ";
        }
        str =str +")";
        return str;
	}

    std::string AdvancedCommonOperation::codevianza(const advanced& s1,const advanced& s2)const{
        std::string str("codevianza = ");
        str= str + std::to_string(s1.codevianza(s2));
        return str;
	}
    std::string AdvancedCommonOperation::covarianza(const advanced& s1,const advanced& s2)const{
        std::string str("covarianza = ");
        str= str + std::to_string(s1.covarianza(s2));
        return str;
	}


    std::string AdvancedCommonOperation::correlazione(const advanced& s1,const advanced& s2)const{
        std::string str("correlazione = ");
        str= str + std::to_string(s1.correlazione(s2));
        return str;
	}

    std::string AdvancedCommonOperation::coeff_determinazione(const advanced& s1,const advanced& s2)const{
        std::string str("coefficente di determinazione = ");
        str= str + std::to_string(s1.coeff_determinazione(s2));
        return str;
	}

    std::string AdvancedCommonOperation::regressione(const advanced& s1,const advanced& s2)const{
        std::string str("regressione = ");
        str= str + std::to_string(s1.regressione(s2));
        return str;
	}

    std::string AdvancedCommonOperation::intercetta(const advanced& s1,const advanced& s2)const{
        std::string str("intercetta = ");
        str= str + std::to_string(s1.intercetta(s2));
        return str;
	}		
	

