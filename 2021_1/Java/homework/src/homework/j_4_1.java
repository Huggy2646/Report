package homework;
import java.util.Scanner;

public class j_4_1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int egg, trucks, boxes, plates; // ������� ����� ����, Ʈ��, �ڽ�, �����
		
		System.out.print("����� ������ �Է��Ͻÿ�:");
		egg = sc.nextInt();
		
		trucks = egg/6000;
		egg = egg%6000;
		
		boxes = egg/300;
		egg = egg%300;
		
		plates = egg/30;
		egg = egg%30;
		
		System.out.print(trucks+"Ʈ��, "+boxes+"�ڽ�, "+plates+"��, "+"����"+egg+"�Դϴ�.");
		
		sc.close();
		
	
	}

}
