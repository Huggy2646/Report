package homework;
import java.util.Scanner;

public class j_4_1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int egg, trucks, boxes, plates; // 순서대로 계란의 갯수, 트럭, 박스, 계란판
		
		System.out.print("계란의 갯수를 입력하시오:");
		egg = sc.nextInt();
		
		trucks = egg/6000;
		egg = egg%6000;
		
		boxes = egg/300;
		egg = egg%300;
		
		plates = egg/30;
		egg = egg%30;
		
		System.out.print(trucks+"트럭, "+boxes+"박스, "+plates+"판, "+"낱개"+egg+"입니다.");
		
		sc.close();
		
	
	}

}
