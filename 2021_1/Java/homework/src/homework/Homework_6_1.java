package homework;

public class Homework_6_1 {
	public static void main(String[] args)
	{
		int i=0,j=0;
		int sum=0;
		while(true)
		{
			i = (int)(Math.random()*10);
			j=(int)(Math.random()*10);
			
			if(i<7 && i!=0 && j<7 && j!=0)
			{
				System.out.println("("+i+","+j+")");
				sum=i+j;
					
				if(sum==5) 
				{
					System.out.print("Bye~~");
					break;
				}
				
					
				else
					continue;
			}
			
		}//while		
	}//main
}// class
