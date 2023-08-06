package homework;

public class Homework_6_2_1 {
	public static void main(String[] args)
	{
		int a[][]= {{5,10,2,7,5},{4,6,2,2,9},{1,9,2,8,4}};
		int b[][]= {{5,2,7,4,5},{10,6,9,2,3},{2,6,4,7,1}};
		int c[][]= new int[3][5];
		
		
		for(int i=0; i<a.length; i++)
		{
			for(int j=0; j<a[i].length; j++)
			{
				if(a[i][j]>b[i][j])
					c[i][j]=a[i][j];
				else
					c[i][j]=b[i][j];
				
				System.out.print(c[i][j]+"\t");				
			}
			System.out.println();
		}
		

	}//main

}// class
