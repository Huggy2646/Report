package homework;
import java.io.File;
import java.util.Scanner;
public class Homework_11_2 {

	public static void main(String[] args) {
		
		int dir_count=0;
		int file_count=0;
		System.out.print("폴더 입력 ==>");
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
			System.out.println("해당 폴더 안에는");
			System.out.println(file_count+"개의 파일과");
			System.out.println(dir_count+"개의 디렉토리가 있습니다.");
		}
		else
			System.out.print("존재하지 않는 폴더입니다.");
		
	}

}
