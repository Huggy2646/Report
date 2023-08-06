package homework;
import java.io.FileReader;
import java.io.FileWriter;
public class Homework_11_1 {

	public static void main(String arg[]) throws Exception {
		FileReader fr = new FileReader("C:\\Users\\View\\Desktop\\동아대학교\\과제\\2021_1학기\\Java/line_no.txt");
		FileWriter fw = new FileWriter("C:\\Users\\View\\Desktop\\동아대학교\\과제\\2021_1학기\\Java/line_yes.txt");
		int c =0;
		int count =1;
		fw.write(count+":");
		while((c=fr.read()) != -1)
		{
			fw.write(c);
			if(c == '\n')
			{
				count++;
				fw.write(count + ":");
				
			}
		}	
		
		fr.close();
		fw.close();
	}
}
