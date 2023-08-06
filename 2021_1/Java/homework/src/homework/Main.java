package homework;
import java.util.Scanner;
import java.text.DecimalFormat;
public class Main {

	public static void main(String[] args) 
	{
		double korean=0;
		double english=0;
		double math=0;
		double avg = 0;
		
		DecimalFormat form = new DecimalFormat("#.##");
		Scanner sc = new Scanner(System.in);
		
		System.out.print("국영수 점수:");
		korean = sc.nextInt();
		english = sc.nextInt();
		math = sc.nextInt();
		
		avg = (korean+english+math)/3;
		System.out.println("평균:"+form.format(avg));
		
		if(avg>=80)
			System.out.print("^_^");
		else if(80>avg && avg>=50)
			System.out.print("-_-");
		else
			System.out.print("ㅠㅠ");

	}

}
