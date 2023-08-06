package os;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class batch {
	
	public static void main(String[] args) throws IOException {
		FileReader reader = new FileReader("C:\\Users\\View\\Desktop\\1.inp.txt");
		BufferedReader bfr = new BufferedReader(reader);

		String ch;
		String arr2[];
		String arr[] = new String[100];
		int i=0;
		int stop=0;
		int end=0;
		int idle=0;
		int index =1;
		
		while((ch=bfr.readLine())!=null) {
			String value = ch;
			stop+=value.length();
			List<String> list = new ArrayList<>(Arrays.asList(arr));
			list.add(i,value);
			arr = list.toArray(arr);
			arr[i]=ch;
			i++;
			
		}
		arr2=Arrays.toString(arr).split(" ");


		for(int j=1;j<stop;j++) {
			String st=arr2[j];
			if(st=="null") {
				break;
			}
			else if(st!=" -1,") {
				try {
					end+=Integer.parseInt(arr2[j]);
				} catch (NumberFormatException e){
				    end+=0;
				}					
			}
			
		}
		
		for (int j=1; j<stop;j++) {
			String st = arr2[j];
			int v=0;
			if(st=="null")	break;
			try {
				v = Integer.parseInt(st);
				if(index%2==0) {
					idle+=v;
				}
			}
			catch (NumberFormatException e){
				index=0;
			}
			index++;
		}
		
		System.out.print(idle);
		System.out.print(end);
		
	}

}
