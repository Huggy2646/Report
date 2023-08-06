package homework;
import java.util.Scanner;
/// 세개의 정수를 입력받아 최댓값을 출력하시오
public class Homework{
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("정수 3개를 입력하시오.");
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		int num3 = sc.nextInt();
		int winner;
		
		// num1과 num2의 숫자크기 비교
		// 두 개를 빼었을 때 0보다 작으면 오른쪽이 크고 크면 왼쪽이 큰 수 이고, 큰 수는 winner에 저장된다.
		// 더블if문으로 만들어서 num1과 num2를 비교하고 큰 수쪽이 판단 되었을 때 그 수와 num3와 비교하여
		// 큰 수가 winner에 저장된다.
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
			
		
		
		System.out.println("최댓값은"+winner+"이다.");
		
		sc.close();
		
	}
}

/*반복문 이용
public class Homework{
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("숫자를 입력하시오!");
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
		System.out.println("최댓값은"+numlist[2]+"이다.");
		
		sc.close();
	}
}
*/

