import java.util.*;

public class dataset extends numbers{
    private LinkedList<Integer> element = new LinkedList<Integer>();

    public dataset(String nm, LinkedList<Integer> l) {
        super(nm);
        element=new LinkedList<Integer>(l);
        if(element.size()<2){
        	for(int i=0; i<2-element.size();i++){
        		element.add(0);
        	}
        }
    }

    public void clear(){
    	element.clear();
    }

    public LinkedList<Integer> getElement(){
    	return element;
    }

    public void add_value(Integer n){
    	element.add(n);
    }

    public void sub_value(Integer n){
    	element.remove(n);
    	if(element.size() < 0){
        	for(int i=0; i<2-element.size();i++){
        		element.add(0);
        	}
    	}
    }

    public void add_list(LinkedList<Integer> l){
        for(int i=0; i<l.size(); i++) {
            this.add_value(l.get(i));
        }
    }

    public void sub_list(LinkedList<Integer> l){
        for(int i=0; i<l.size(); i++) {
            sub_value(l.get(i));
        }
    }

	@Override 
	public dataset clone() {
		return new dataset(getName(),getElement());
	}
	
	@Override
	public String name(){
		return String("dataset");
	}

	@Override
	public String toString(){
		String dataset=getName() + "={";
	    if(element.size() != 0){	
	        dataset = dataset + element.get(0);
	    }

	    for(int i=1; i<element.size(); i++){
	        dataset+=", "+ element.get(i);
	    }
	    dataset+="}";
	    return dataset;
	}


	@Override 
	public boolean equals(Object o) {
    	return (o instanceof dataset) && (getName() != ((dataset)o).getName()) && (element != ((dataset)o).element);
	}

	public int somme(){
		int somme =0;
	    for (int i=0; i<element.size(); i++){
			somme =somme + element.get(i);
		}
		return somme;
	}

	public int size(){
		return element.size();
	}

	double average(){
		double somme =somme();
		double size =size();
		return somme / size;
	}

	public int GL(){
		if(element.size() == 0){return 0;}
		return element.size()-1;
	}

	public double variance(){
		double deviance =deviance();
		int GL =GL();
		double variance =deviance/GL;
		return variance;
	}
	public double DS(){
		double variance =variance();
		return Math.sqrt(variance);
	}

	public double deviance(){
		LinkedList<Double> l =power2_deviation();
		double deviance =0;
	    for (int i=0; i<l.size(); i++){ 		
			deviance =deviance+l.get(i);
		}
		return deviance;
	}

	public LinkedList<Double> deviation(){
		LinkedList<Double> l= new LinkedList<Double>();
		double average =average();
	    for (int i=0; i<element.size(); i++){
	        l.add((element.get(i) - average));
		}
		return l;
	}


	public LinkedList<Double> power2_deviation(){
		LinkedList<Double> l =deviation();
		for (int i=0; i<l.size(); i++){
			l.set(i,Math.pow(l.get(i),2));
		}
		return l;
	}

	public void checkpoint(dataset s)throws IncorrectCase{
		boolean sent=false;
		for(int i=0; i<element.size() && sent==false; i++){
			if(element.get(i).intValue() != s.element.get(i).intValue()){
				sent=true;
			}
		}
        if(sent == false){
			int n1= element.get(1);
			for(int i=0; i<element.size() && sent!=false; i++){
				if(n1 != element.get(i).intValue()){sent=true;}
			}
			int n2= s.element.get(1);
			for(int i=0; i<element.size() && sent!=false; i++){
				if(n2 != element.get(i).intValue()){sent=true;}
			}
			if(sent == false){
				throw new IncorrectCase("exception : you cannot execute this operation on equals advanced dataset.");
			}
		}
	}

}
