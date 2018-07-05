
#include "MODEL/HEADER/AdvancedCommonOperation.h"

    AdvancedCommonOperation::AdvancedCommonOperation():customPlot(0){}

    void AdvancedCommonOperation::cleanGrafic(){
        if(customPlot){
            delete customPlot;
            customPlot=0;
        }
    }

    AdvancedCommonOperation::~AdvancedCommonOperation(){
        if(customPlot){
            customPlot->close();
        }
    }

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

    std::string AdvancedCommonOperation::Grafic(const advanced& s1,const advanced& s2){
        std::string str;
        double regression =s1.regressione(s2);
        double intercection =s1.intercetta(s2);
        customPlot= new QCustomPlot();
        QObject::connect(customPlot,SIGNAL(destroyed()),this,SLOT(cleanGrafic()));
        // generate some data:
        QVector<double> x(100), y(100), x1(s1.dataset::size()), y1(s1.dataset::size());
        for (int i=0; i<100; ++i)
        {
          x[i] = i-50;
          y[i] = regression*x[i]+intercection;
        }
        std::list<int> l1=s1.get_element();
        std::list<int> l2=s2.get_element();
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
        double r = s1.correlazione(s2);
        std::cout<<r<<" "<<double(1);
        if(r == double(1) || r==double(-1)){
            str="correlazione perfetta :"+correlazione(s1,s2);
        }
        if((r>0 && r<1) || (r<0 && r>-1)){
            str="correllazione imperfetta"+correlazione(s1,s2);
        }
        if(r==double(0)){
            str="nessuna correlazione"+correlazione(s1,s2);
        }
        return str;
    }

    std::string AdvancedCommonOperation::Allinfo(const advanced& s1,const advanced& s2)const{
        std::string str;
        str =coscarto(s1,s2);
        str =str +" \r\n";
        str =str +codevianza(s1,s2);
        str =str +" \r\n";
        str =str +covarianza(s1,s2);
        str =str +" \r\n";
        str =str +correlazione(s1,s2);
        str =str +" \r\n";
        str =str +coeff_determinazione(s1,s2);
        str =str +" \r\n";
        str =str +regressione(s1,s2);
        str =str +" \r\n";
        str =str +intercetta(s1,s2);
        str =str +" \r\n";
        str =str +retta(s1,s2);

        return str;
    }

    std::string AdvancedCommonOperation::retta(const advanced& s1,const advanced& s2)const{
        std::string str;
        str = "Y = " + std::to_string(s1.regressione(s2));
        double inter=s1.intercetta(s2);
        if(inter > 0){
            str = str + "X +" +std::to_string(inter);
        }
        else{
            str = str + "X " +std::to_string(inter);
        }
        return str;
    }

