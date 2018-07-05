import java.util.LinkedList;

public class use{
	public static void main(String[] args) {
		LinkedList<Integer> a =new LinkedList<Integer>();
		for(int i=0; i<11; i++){
			a.add(i);
		}
		LinkedList<Integer> b =new LinkedList<Integer>();
		for(int i=2; i<13; i++){
			b.add(i);
		}
		LinkedList<Integer> c =new LinkedList<Integer>();
		for(int i=0; i<20; i++){
			c.add(i);
		}
		LinkedList<Integer> d =new LinkedList<Integer>();
		d.add(1);		d.add(1);


		LinkedList<Integer> e =new LinkedList<Integer>();
		for(int i=0; i<2; i++){
			e.add(1);
		}

		numbers numb1 =new set("A");
		set set1 = new set("setA",a);
		set set2 = new set("setB",b);
		set set3 = new set("setC",c);

		dataset dat1 = new dataset("datasetA",a);
		dataset dat2 = new dataset("datasetB",d);

		advanced adv1 = new advanced("advancedA",a);
		advanced adv2 = new advanced("advacnedB",b);
		advanced adv3 = new advanced("advancedC",c);
		advanced adv4 = new advanced("advancedD",d);
		advanced adv5 = new advanced("advancedE",d);
		advanced adv6 = new advanced("advancedF",e);


		//OPERAZIONI CON SET
		System.out.print("\n"+"Parte Set"+"\n");


		String str =(set1.Union(set2)).toString();
		System.out.print(str+"\n");

		str =(set1.Difference(set2)).toString();
		System.out.print(str+"\n");

		str =(set1.Intercetion(set2)).toString();
		System.out.print(str+"\n");

		str =(set1.SymmetricalDifference(set2)).toString();
		System.out.print(str+"\n");

		str =(set1.CartesianProduct(set3));
		System.out.print(str+"\n");

		try{
			str =set3.partition();
			System.out.print(str+"\n");		
		}
		catch(IncorrectCase EA){
			System.out.println(EA+"\n");
		}

		//OPERAZIONE CON DATASET
		System.out.print("\n"+"Parte Dataset Esempio 1"+"\n");


		str =("somme ="+dat1.somme()).toString();
		System.out.print(str+"\n");

		str =("size ="+dat1.size()).toString();
		System.out.print(str+"\n");

		str =("average ="+dat1.average()).toString();
		System.out.print(str+"\n");


		str =("GradeOfLiberty ="+dat1.GL()).toString();
		System.out.print(str+"\n");

		str =("variance ="+dat1.variance()).toString();
		System.out.print(str+"\n");


		str =("DeviationStandard ="+dat1.DS()).toString();
		System.out.print(str+"\n");

		
		str =("deviance ="+dat1.deviance()).toString();
		System.out.print(str+"\n");

		System.out.println(dat1.getName()+dat1.deviation()+"\n");
		System.out.println(dat1.getName()+dat1.power2_deviation()+"\n");

		//dataset creato con lista nulla
		System.out.print("\n"+"Parte Dataset Esempio 2"+"\n");


		str =("somme ="+dat2.somme()).toString();
		System.out.print(str+"\n");

		str =("size ="+dat2.size()).toString();
		System.out.print(str+"\n");

		str =("average ="+dat2.average()).toString();
		System.out.print(str+"\n");


		str =("GradeOfLiberty ="+dat2.GL()).toString();
		System.out.print(str+"\n");

		str =("variance ="+dat2.variance()).toString();
		System.out.print(str+"\n");


		str =("DeviationStandard ="+dat2.DS()).toString();
		System.out.print(str+"\n");

		
		str =("deviance ="+dat2.deviance()).toString();
		System.out.print(str+"\n");

		//OPERAZIONE CON ADVANCED
		System.out.print("\n"+"Parte Advanced Esempio 1"+"\n");

		try{
		str =("coscarto ="+adv1.coscarto(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}

		try{
		str =("codevianza ="+adv1.codevianza(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}

		try{
		str =("covarianza ="+adv1.covarianza(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}
	
		try{
		str =("correlazione ="+adv1.correlazione(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}

		try{
		str =("coeff_determinazione ="+adv1.coeff_determinazione(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}

		try{
		str =("regressione ="+adv1.regressione(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}

		try{
		str =("intercetta ="+adv1.intercetta(adv2)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}
		
		System.out.print("\n"+"Parte Advanced Esempio 2 eccezzioni"+"\n");

		try{
		str =("intercetta ="+adv4.intercetta(adv5)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}

		try{
		str =("intercetta ="+adv4.intercetta(adv5)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}		

		try{
		str =("intercetta ="+adv6.intercetta(adv5)).toString();
		System.out.print(str+"\n");			
		}
		catch(IncorrectCase Ic){
			System.out.println(Ic);
		}


	}
}
