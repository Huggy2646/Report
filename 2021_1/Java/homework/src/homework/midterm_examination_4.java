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
					System.out.println("양의 정수로 부탁드릴께요!");
					continue;
				}
					
				else if(num==1)
				{
					System.out.println("소수도 합성수도 아닙니다. bye~");
					break;
				}
				else
				{
					for(int i = 2; i < num; i++)
					{
					       
						if(num % i == 0)
						{
							System.out.print("합성수입니다. bye~");
							break Duli;
						}
					}
				}

				System.out.println("소수입니다. bye~");
				break;
				
			}
			catch (InputMismatchException e)
			{
				System.out.println("고객님ㅠ 정수 1개 please~ "); continue;
				
			}
			
			
			
		}

	}

}