package homework;

public class Rectangle {
	double a,b;
	public Rectangle(double a, double b) {
		this.a = a;
		this.b = b;
	}
	//�簢�� ���� 
	public double getArea(){
		return a*b;
	}
	//������ѷ�
	public double getCircumference(){
		return (2*a) + (2*b);
	}
	
	public double getArea(int n) {
		if(n!=4)
		{
			if (n==3)
				return (a*b)/2;
			
			else
				System.out.printf("%d���� ���� �ڵ� �ȵǾ����ϴ�. ==> ",n);
				return 0.0;	
		}
		else
			return getArea();

	}


}
