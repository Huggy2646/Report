package homework;
import java.util.Scanner;
import java.util.InputMismatchException;
public class midterm_examination_4 {

	public static void main(String[] args) {
		int num = 0;
		Duli:while(true)
		{
			try
			{
				Scanner sc = new Scanner(System.in);
				num = sc.nextInt();
				if(num<=0)
				{
					System.out.println("���� ������ ��Ź�帱����!");
					continue;
				}
					
				else if(num==1)
				{
					System.out.println("�Ҽ��� �ռ����� �ƴմϴ�. bye~");
					break;
				}
				else
				{
					for(int i = 2; i < num; i++)
					{
					       
						if(num % i == 0)
						{
							System.out.print("�ռ����Դϴ�. bye~");
							break Duli;
						}
					}
				}

				System.out.println("�Ҽ��Դϴ�. bye~");
				break;
				
			}
			catch (InputMismatchException e)
			{
				System.out.println("���Ԥ� ���� 1�� please~ "); continue;
				
			}
			
			
			
		}

	}

}