import java.util.*;

public class advanced extends dataset{
    private int size;
    private double average;
    private int GradeOfLiberty;
    private double variance;
    private double DeviationStandard;
    private double deviance;
    private LinkedList<Double> deviation = new LinkedList<Double>();
    private LinkedList<Double> power2_deviation = new LinkedList<Double>();

    public advanced(String name, LinkedList<Integer> l){
        super(name,l);
        update();
    }

    public void clear(){
        super.clear();
        update();
    }

    @Override 
    public dataset clone() {
        return new dataset(getName(),getElement());
    }

    @Override 
    public boolean equals(Object o) {
        return (o instanceof advanced) && super.equals(o);
    }
    
    public void add_list(LinkedList<Integer> l){
        super.add_list(l);
        update();
    }
    public void update(){
        size=size();
        average=average();
        GradeOfLiberty=GL();
        variance=variance();
        DeviationStandard=DS();
        deviance=deviance();
        deviation=deviation();
        power2_deviation=power2_deviation();
    }

    public LinkedList<Double> coscarto(advanced s2) throws IncorrectCase{
        LinkedList<Double> coscarto =new LinkedList<Double>();
        if(size != s2.size){throw new IncorrectCase("exception :size of datasets is different.");}
        checkpoint(s2);
        LinkedList<Double> it1= deviation();
        LinkedList<Double> it2= s2.deviation();
        for(int i=0; i<size; i++){
            coscarto.add((it1.get(i))*(it2.get(i)));
        }
        return coscarto;
    }

    public double codevianza(advanced s2) throws IncorrectCase{
        double codevianza =0;
        LinkedList<Double> coscarti =coscarto(s2);
        for(int i=0; i< coscarti.size(); i++){
                codevianza = codevianza + coscarti.get(i);
            }
        return codevianza;
    }

    public double covarianza(advanced s2)throws IncorrectCase{
        double covarianza =0;
        double code =codevianza(s2);
        covarianza =code / GradeOfLiberty;
        return covarianza;
    }

    public double correlazione(advanced s2)throws IncorrectCase{
        double correlazione =0;
        double cova =covarianza(s2);
        correlazione =(cova*10000)/((DeviationStandard*100)*(s2.DeviationStandard*100));
        return correlazione;
    }

    public double coeff_determinazione(advanced s1)throws IncorrectCase{
        double coeff =0;
        double corre =correlazione(s1)*100;
        coeff =(corre*corre)/10000;
        return coeff;
    }

    public double regressione(advanced s2)throws IncorrectCase{
        double regressione =0;
        double corre =correlazione(s2);
        double ds1 = DeviationStandard*100;
        double ds2 = s2.DeviationStandard*100;
        regressione = corre * (ds2/ds1);
        return regressione;
    }

    public double intercetta(advanced s2)throws IncorrectCase{
        double intercetta =0;
        double regre =regressione(s2);
        intercetta  = s2.average - (regre*average);
        return intercetta;
    }
}
