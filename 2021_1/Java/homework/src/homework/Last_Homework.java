package homework;
import java.io.File;
import java.util.Scanner;
public class Last_Homework {

	public static void main(String[] args) throws Exception  {
		File fr = new File("C:/Users/View/Desktop/���ƴ��б�/����/2021_1�б�/Java/13����/dictionary.txt");
		int c = 0;

		String value;
		String [] kor = new String[88];
		String [] eng = new String[88];
		Scanner sc = new Scanner(fr);

		for(int i =0; i<88; i++)
		{
			kor[i]=sc.next();
			eng[i]=sc.next();	
		}

		

		
		duli:while(true)
		{
			Scanner sc_1 = new Scanner(System.in);
			value = sc_1.next();
			if(value.equals("Q")||value.equals("q"))
			{
				System.out.println("���α׷��� �����մϴ�.");
				break;
			}
			for(int i =0;i<88;i++)
			{
				if(kor[i].equals(value))
				{
					System.out.println(eng[i]);
					continue duli;
					
				}
			}
			for(int i=0;i<88;i++)
			{
				if(eng[i].equals(value))
				{
					System.out.println(kor[i]);
					continue duli;
				}
			}
			System.out.println("������ ���� �ܾ��Դϴ�.");
			
		}
		
	}

}
