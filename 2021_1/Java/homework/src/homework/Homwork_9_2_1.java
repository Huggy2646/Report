package homework;
import java.util.Scanner;
public class Homwork_9_2_1 {
	
    public static void main(String[] args) {
    	while(true)
    	{
    		Scanner sc = new Scanner(System.in);
            int num=sc.nextInt();
            if(num==0)
            {
            	System.out.print("bye");
            	break;
            }
            else if(num<0)
            {
            	System.out.print("양의정수를 입력해주세요");
            	continue;
            }
            else
            	System.out.println(flip(num));
    	}
        
    }
    
    public static int flip(int num){
        int result=0;
        while(num!=0){
            result= result * 10 + num % 10;
            num /= 10;
        }
        return result;
    }
}


