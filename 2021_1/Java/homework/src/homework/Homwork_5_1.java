package homework;

public class Homwork_5_1 {

	public static void main(String[] args) {
		
		int fac_r=10; // ���丮�� ���
		int n=50; // �����ڸ��� �� �����ڸ����� ������� ����� �� ����ϴ� ����
		
		for(int i=1; i<101; i++) // 3�� ����̸鼭 4�� ����� �ƴ� ��
		{
			if(i%3==0 && i%4!=0)
			{
				System.out.print(i+" ");
			}
		}
		System.out.println();
		
		while(true) // �����ڸ��� �� �����ڸ����� ������� ���
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
