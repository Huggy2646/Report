package homework;

public class Homework_12_2 {

	public static void main(String[] args) {
		int [] aa= {99,77,55};
		int [] bb;
		String [] cc= {"�޸�","��ũ","����","��¥��Ʈ"};
		String [] dd= new String[3]; 
		bb= aa;   aa[1] = 44;
		for(int i =0; i<dd.length; i++) dd[i] = cc[i];// �� �ڿ���ü�ּҺ���(new�����Ƿλ��λ����Ǵ°�ü����)
		dd[2] = "��ī��"; 
		System.out.println(aa[1]+bb[1]+cc[2]+dd[2]);
		aa = null; cc = null;

	}

}
