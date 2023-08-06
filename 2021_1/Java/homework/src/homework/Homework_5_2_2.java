package homework;

public class Homework_5_2_2 {

	public static void main(String[] args) {
		
		for(int x=0; x<11; x++)
		{
			for(int y=0; y<11; y++)
			{
				if((4*x)+(5*y)==60)
				{
					System.out.println("("+x+","+y+")");
					break;
				}//if
			}//for2
		}// for1
	}// main
}//class
