package homework;

public class Homwork_5_1 {

	public static void main(String[] args) {
		
		int fac_r=10; // 팩토리얼 결과
		int n=50; // 십의자리수 와 일의자리수가 같은경우 출력할 때 사용하는 숫자
		
		for(int i=1; i<101; i++) // 3의 배수이면서 4의 배수가 아닌 수
		{
			if(i%3==0 && i%4!=0)
			{
				System.out.print(i+" ");
			}
		}
		System.out.println();
		
		while(true) // 십의자리수 와 일의자리수가 같은경우 출력
		{
			
			if(n<100)
			{
				if(n/10==n%10)
					System.out.print(n+" ");
			}
			else
			{
				;
				if((100-n)/10==(100-n)%10)
					System.out.print(n+" ");
				
			}
			if(n==150)
				break;
			n++;
			
		}
		System.out.println();
		
		for(int i=9; true;i--)
		{
			fac_r=fac_r*(i);
			if(i==1)
				break;
		}
		System.out.print(fac_r);
		
		
	}//main
}//class
