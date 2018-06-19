import java.util.*;

public class set extends numbers{
    private LinkedList<Integer> element = new LinkedList<Integer>();
    public set(String nm) {
    	super(nm);
	}

    public set(String nm, LinkedList<Integer> l) {
        super(nm);
		element = new LinkedList<Integer>(l);
    }

    public boolean contains(Integer n){
    	for(int i=0; i<element.size(); i++) {
    		if((element.get(i)).intValue() == n.intValue()){return true;}
    	}
    	return false;
    }

    public void clear(){
    	element.clear();
    }

    public LinkedList<Integer> getElement(){
    	return element;
    }

    public void add_value(Integer n){
    	if(!contains(n)){element.add(n);}
    }

    public void sub_value(Integer n){
    	element.remove(n);
    }

    public void add_list(LinkedList<Integer> l){
    	System.out.println(l.size());
        for(int i=0; i<l.size(); i++) {
            this.add_value(l.get(i));
        }
    }

    public void sub_list(LinkedList<Integer> l){
        for(int i=0; i<l.size(); i++) {
            sub_value(l.get(i));
        }
    }

	public void add_value_without_control(Integer n){
		element.add(n);
	}

	public void add_list_without_control(LinkedList<Integer> l){
        for(int i=0; i<l.size(); i++){
			add_value_without_control(l.get(i));
        }
	}

    public String combination(int n, int index, LinkedList<Integer> pre){
    	String str="";
	   	if(n == 0){return str="{ }";}
	   	if(n == 1){
	   		String pres="(";
	   		for(int j=0; j < pre.size(); j++){
	   			pres+=pre.get(j)+", ";
	   		}

	   		for(int i=index; i < element.size(); i++){
	   			str+= pres + element.get(i)+ ");";
	   		}
	   		pre.pollLast();
	   		return str;
	   	}
	   	else{
	   		for(int i=index; i<(element.size()-n+1); i++){
	   			pre.add(element.get(i));
	   			str+= combination((n-1),i+1,pre);
	   			
	   		}
	   		pre.pollLast();
	   	}
	    return str;
    }

	public String partition()throws IncorrectCase{
		if(element.size() > 15){throw new IncorrectCase("Exception: the size is too big, it must be minus than 15.");}
		String str = "PowerSet( "+getName()+" )= ";
		LinkedList<Integer> pre= new LinkedList<Integer>();
	    for(int i=0; i<=element.size(); i++){

	        str += combination(i,0, pre);
	        pre.clear();
	    }
	    return str + ");";
	}

	@Override 
	public set clone() {
		return new set(getName(),getElement());
	}
	
	@Override
	public String name(){
		return String("set");
	}

	@Override
	public String toString(){
		String set=getName() + "={";
	    if(element.size() != 0){	
	        set = set + element.get(0);
	    }

	    for(int i=1; i<element.size(); i++){
	        set+=", "+ element.get(i);
	    }
	    set+="}";
	    return set;
	}


	@Override 
	public boolean equals(Object o) {
    	return (o instanceof set) && (getName() != ((set)o).getName()) && (element != ((set)o).element);
	}

	public set Union(set s){
		set result = new set("( "+getName()+" + "+s.getName()+" )");
		result.add_list_without_control(element);
	    result.add_list(s.element);
		return result;
	}

	public set Difference(set s){
		set result = new set("( "+getName()+" - "+s.getName()+" )");
		result.add_list_without_control(element);
    	result.sub_list(s.element);
		return result;
	}

	public set Intercetion(set s){
		set result =new set("( "+getName()+" / "+s.getName()+" )");
	    for (int i=0; i < s.element.size(); i++){
	    	if(element.indexOf(s.element.get(i)) != -1){
	    		result.add_value_without_control(s.element.get(i));
			}
		}	
		return result;
	}

	public set SymmetricalDifference(set s){
		set result =new set("( "+getName()+" % "+s.getName()+" )");
	    for(int i=0; i<s.element.size(); i++){
	    	if(element.indexOf(s.element.get(i)) == -1){
	    		result.add_value_without_control(s.element.get(i));
			}
		}
	    for(int i=0; i<element.size(); i++){
	    	if(s.element.indexOf(element.get(i)) == -1){
	    		result.add_value_without_control(element.get(i));
	    	}
		}
		return result;
	}

	public String CartesianProduct(set s){
		String str = "( " + getName() + " X " +s.getName() +" ) = {";
	    for(int i=0; i<element.size(); i++){
	    for(int j=0; j<s.element.size(); j++){
	            str = str + "( " + element.get(i) + ","+ (s.element.get(j)) + " ),";
	        }
		}
	    str = str + " }";
	    return str;
	}
}
