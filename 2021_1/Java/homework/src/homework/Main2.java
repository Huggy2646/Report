package homework;

public class Main2 {

	public static void main(String[] args) {
		Rectangle rc = new Rectangle(3.82,8.65);
		System.out.println("사각형 면적: " + rc.getArea());
		System.out.println("사각형 둘레: " + rc.getCircumference());
		System.out.println("삼각형 면적: " + rc.getArea(3));
		System.out.println("오각형 면적: " + rc.getArea(5));
		System.out.println("육각형 면적: " + rc.getArea(6));

	}

}
