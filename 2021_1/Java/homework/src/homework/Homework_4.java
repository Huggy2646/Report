package homework;
import java.util.Scanner;

public class Homework_4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a,b,c;
		for(int i=0; i<8; i++) {
			
			System.out.print("�� �� (����):");
			a=sc.nextInt();
			b=sc.nextInt();
			c=sc.nextInt();
			
			
			
			if(a<=0||b<=0||c<=0) 
				System.out.println("impossible");
			
			else if(a+b+c != 180)
				System.out.println("impossible");
			
			else if(a!=90 && b!=90 && c!=90)
				System.out.println("������ ���� �ﰢ��");
			
			else
				System.out.println("�����ﰢ��");
			
		}
		sc.close();	
				
	} 
}
