package homework;

public class Rectangle {
	double a,b;
	public Rectangle(double a, double b) {
		this.a = a;
		this.b = b;
	}
	//사각형 면적 
	public double getArea(){
		return a*b;
	}
	//사격형둘레
	public double getCircumference(){
		return (2*a) + (2*b);
	}
	
	public double getArea(int n) {
		if(n!=4)
		{
			if (n==3)
				return (a*b)/2;
			
			else
				System.out.printf("%d각형 면적 코딩 안되었습니다. ==> ",n);
				return 0.0;	
		}
		else
			return getArea();

	}


}
