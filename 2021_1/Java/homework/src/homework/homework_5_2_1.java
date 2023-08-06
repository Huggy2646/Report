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
			System.out.print("실수 입력:");
			num=sc.nextDouble();
			sum +=num;
			turn++;
			if(num==0)
			{
				result = sum/turn;
				System.out.println("입력하신"+turn+"개 수의 합은"+sum+"이며");
				System.out.println("평균은"+result+"입니다.");
				break;
			}//if
			
				
		}//while
		
	}// main

}// class
