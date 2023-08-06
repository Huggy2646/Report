package homework;
import java.util.InputMismatchException;
import java.util.Scanner;
public class Homework_7 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a=0;
		int b=0;
		int count=0;
		
		
		
		while(true) {
			
			if(count!=3) {
				System.out.println("정수 2개를 입력하시오");
				try {

					a=sc.nextInt();
					b=sc.nextInt();
					int mult = a*b;
					System.out.print(a+"*"+b+"="+mult);

				}
				catch(InputMismatchException e) {
					System.out.println("==> 정수만 입력해주세요\n");
					sc.next();
					count+=1;
					continue;
					
				} // catch
			}// if
			else
				System.out.println("\n3회틀림.ᅲᅲ종료합니다."); break;
				
		}// while
		
		
	}// main
}//class