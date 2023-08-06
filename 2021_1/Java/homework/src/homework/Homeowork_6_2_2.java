package homework;

public class Homeowork_6_2_2 {
	public static void main(String[] args)
	{
		int a[][] = new int[3][5];
		int b[][] = new int[3][5];
		int c[][] = new int[3][5];
		for(int i=0; i<a.length; i++)
			for(int j=0; j<a[i].length; j++)
			{
				a[i][j]=(int)(Math.random()*10+1);
				b[i][j]=(int)(Math.random()*10+1);
				
				if(a[i][j]>b[i][j])
					c[i][j]=a[i][j];
				else
					c[i][j]=b[i][j];
				
			}
		
		System.out.println("배열 a");
		for(int []i:a)
		{	
			for(int j:i)
			{
				System.out.print(j+" ");
			}
			System.out.println();
		}
		
		System.out.println("\n배열 b");
		for(int []i:b)
		{	
			for(int j:i)
			{
				System.out.print(j+" ");
			}
			System.out.println();
		}
		
		System.out.println("\n배열 c");
		for(int []i:c)
		{	
			for(int j:i)
			{
				System.out.print(j+" ");
			}
			System.out.println();
		}
	}

}
