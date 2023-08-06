package homework;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
public class Homework_10 {
	public static double avg (FileReader fr) throws Exception
	{
		int c=0;
		double result=0;
		double count =0;
		while((c=fr.read())!=-1)
		{
			if(c=='A')
			{
				result+=4;
				count++;
			}
			else if(c=='B')
			{	
				result+=3;
				count++;
			}
			else if(c=='C')
			{
				result+=2;
				count++;
			}	
			else
				if(c!='\r' && c!='\n')
					count++;
				else
					continue;
		}
//		System.out.println(result);
//		System.out.println(count);
		result = result/count;
		fr.close();
		return result;
	}

	public static void main(String arg[]) throws Exception
	{
		DecimalFormat form = new DecimalFormat("#.##");
		double br_avg=0;
		double sa_avg=0;
		double jg_avg=0;
		String winner=null;
		
		FileReader br = new FileReader("C:\\Users\\View\\Desktop\\���ƴ��б�\\����\\2021_1�б�\\Java\\bread.txt");
		FileReader sa = new FileReader("C:\\Users\\View\\Desktop\\���ƴ��б�\\����\\2021_1�б�\\Java\\salad.txt");
		FileReader jg = new FileReader("C:\\Users\\View\\Desktop\\���ƴ��б�\\����\\2021_1�б�\\Java\\jjigae.txt");
		
		br_avg=avg(br);
		System.out.println("bread�� ����:"+form.format(br_avg));
		
		sa_avg=avg(sa);
		System.out.println("salad�� ����"+form.format(sa_avg));
		
		jg_avg=avg(jg);
		System.out.println("jjigae�� ����"+form.format(jg_avg));
		
		if (br_avg<jg_avg && sa_avg<jg_avg)
			winner="jjigae";
		else if(br_avg<sa_avg && jg_avg<sa_avg)
			winner="salad";
		else
			winner="bread";
			
		System.out.println("���ڴ�"+winner+"�Դϴ�!!");		
	}
}
