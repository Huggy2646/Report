package homework;

public class Homework_12_2 {

	public static void main(String[] args) {
		int [] aa= {99,77,55};
		int [] bb;
		String [] cc= {"달리","몽크","슈만","모짜르트"};
		String [] dd= new String[3]; 
		bb= aa;   aa[1] = 44;
		for(int i =0; i<dd.length; i++) dd[i] = cc[i];// 문 자열객체주소복사(new없으므로새로생성되는객체없음)
		dd[2] = "피카소"; 
		System.out.println(aa[1]+bb[1]+cc[2]+dd[2]);
		aa = null; cc = null;

	}

}
