package homework;
import java.util.Scanner;
public class homework_5_2_1 {

	public static void main(String[] args) {
		double num=0;
		double sum=0;
		double result=0;
		int turn = 0;
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			System.out.print("�Ǽ� �Է�:");
			num=sc.nextDouble();
			sum +=num;
			turn++;
			if(num==0)
			{
				result = sum/turn;
				System.out.println("�Է��Ͻ�"+turn+"�� ���� ����"+sum+"�̸�");
				System.out.println("�����"+result+"�Դϴ�.");
				break;
			}//if
			
				
		}//while
		
	}// main

}// class
