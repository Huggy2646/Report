package homework;
import java.io.File;
public class ex {
	public static void main(String[] args){
		File f = new File("c:/Windows/system.ini");
		System.out.println(f.getPath());
		System.out.println(f.getParent());
		System.out.println(f.getName());
		System.out.println(f.exists());
		long t = f.lastModified();
		System.out.println(t);
		System.out.printf("%tc",t);
	}//main

}// class