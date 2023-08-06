package homework;

public class Printer {
	public void println(int a)
	{
		System.out.println(a);
	}
	public void println(boolean a)
	{
		System.out.println(a);
	}
	public void println(double a)
	{
		System.out.println(a);
	}
	public void println(String a)
	{
		System.out.println(a);
	}
	public static void main(String[] args) {
		
		Printer pp = new Printer();
		
		pp.println(10);
		pp.println(true);
		pp.println(5.7);
		pp.println("ȫ�浿");

	}

}
