package homework;
import java.util.Scanner;
public class Main_2 {
	int kor, eng, mat;
	
	public void readScores()
	{
		System.out.print("국영수 점수:");
		Scanner sc = new Scanner(System.in);
		kor = sc.nextInt();
		eng = sc.nextInt();
		mat = sc.nextInt();
	}
	
	public double calculateAvg()
	{
		double ag=(kor+eng+mat)/3;
		return ag;
	}
	
	public static String printFace(double avg)
	{
		if(avg>=80)
			return "^_^";
		else if(80>avg && avg>=50)
			return "-_-";
		else
			return "ㅠㅠ";
	}
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		Main_2 m = new Main_2();
		m.readScores();
		double avg= m.calculateAvg();
		System.out.printf("평균: %.2f %n", avg);
		System.out.println(m.printFace(avg));

	}

}
