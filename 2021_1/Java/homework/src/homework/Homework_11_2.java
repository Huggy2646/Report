package homework;
import java.io.File;
import java.util.Scanner;
public class Homework_11_2 {

	public static void main(String[] args) {
		
		int dir_count=0;
		int file_count=0;
		System.out.print("���� �Է� ==>");
		Scanner sc = new Scanner(System.in);
		File f = new File(sc.next());
		File[]a = f.listFiles();
		if(f.exists())
		{
			for(int i=0; i<a.length; i++)
			{
				
				if(a[i].isDirectory())
					dir_count++;
				else
					file_count++;	
			}
			System.out.println("�ش� ���� �ȿ���");
			System.out.println(file_count+"���� ���ϰ�");
			System.out.println(dir_count+"���� ���丮�� �ֽ��ϴ�.");
		}
		else
			System.out.print("�������� �ʴ� �����Դϴ�.");
		
	}

}
