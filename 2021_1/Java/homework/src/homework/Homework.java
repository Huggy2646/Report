package homework;
import java.util.Scanner;
/// ������ ������ �Է¹޾� �ִ��� ����Ͻÿ�
public class Homework{
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("���� 3���� �Է��Ͻÿ�.");
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		int num3 = sc.nextInt();
		int winner;
		
		// num1�� num2�� ����ũ�� ��
		// �� ���� ������ �� 0���� ������ �������� ũ�� ũ�� ������ ū �� �̰�, ū ���� winner�� ����ȴ�.
		// ����if������ ���� num1�� num2�� ���ϰ� ū ������ �Ǵ� �Ǿ��� �� �� ���� num3�� ���Ͽ�
		// ū ���� winner�� ����ȴ�.
		if(num1-num2<0){
			
			winner=num2;
			if(num2-num3<0)
				winner=num3;
			else
				winner=num2;
		}
		
		else {
			winner=num1;
			if(num1-num3<0)
				winner=num3;
			else
				winner=num1;
		}
			
		
		
		System.out.println("�ִ���"+winner+"�̴�.");
		
		sc.close();
		
	}
}

/*�ݺ��� �̿�
public class Homework{
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("���ڸ� �Է��Ͻÿ�!");
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		int num3 = sc.nextInt();
		
		int numlist[] = {num1,num2,num3};
		
		for(int i=0; i<2; i++){
			if(numlist[i]>numlist[i+1]){
				int num=numlist[i];
				numlist[i]=numlist[i+1];
				numlist[i+1]=num;
						
			}
		}
		System.out.println("�ִ���"+numlist[2]+"�̴�.");
		
		sc.close();
	}
}
*/

