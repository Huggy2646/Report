package homework;
public class midterm_examination_3 {
	
	public static void main(String[] args) {
		

		double a[] = {64.4, 27.8, 13.9, 72.2, 13.6, 3.8, 64.0, 75.8, 51.0, 47.6, 79.9, 
				80.3, 28.4, 80.2, 65.5, 12.8, 0.3, 95.3, 7.6, 75.7, 98.9, 97.6, 13.1, 
				95.5, 8.9, 89.3, 69.7, 18.6, 23.4, 60.7, 37.1, 69.6, 36.0, 7.8,2.8, 
				70.1, 23.9, 27.5, 37.7, 6.3, 9.4, 16.5, 70.6, 24.7, 43.0, 31.4, 57.5, 
				28.9, 99.9, 38.3, 51.9};
		double sum = 0;
		double avg = 0;
		double s_of_dev_s = 0; // square of deviation sum ���������� ��
		int length = a.length;
		int maxindex = --length;
		

		for(int i =0; i<a.length; i++) //��, for1
		{
			sum = sum+a[i];
		} // for1
		
		avg = sum / a.length; // ���
		
		for(int i =0; i<maxindex; i++) // �ִ밪�� �迭tail��~, for2
		{
			int j = i;
			j = ++j;
			if(a[i]<a[j])
				continue;
			else
			{
				double storage = a[i];
				a[i]=a[j];
				a[j]=storage;
			}
			
				
		}//for2
		
		
		for(int i=maxindex; i>0; i--) // �ּҰ��� �迭head��~, for3
		{
			int j = i;
			j= --j;
			if(a[i]< a[j])
			{
				double storage = a[i];
				a[i] = a[j];
				a[j] = storage;
			}
			else
				continue;
			
		}//for3
		
		for(int i=0; i<a.length; i++) // ������ ��
		{
			s_of_dev_s = s_of_dev_s+((avg-a[i])*(avg-a[i]));
		}
		
		System.out.println("��:"+sum); // ��
		System.out.println("���:"+avg); // ���
		System.out.println("�ּҰ�:"+a[0]); // �ּҰ�
		System.out.println("�ִ밪:"+a[maxindex]); // �ִ밪
		System.out.println("�л�:"+s_of_dev_s/a.length); // �л�
		System.out.println("ǥ������:"+Math.sqrt(s_of_dev_s/a.length)); //ǥ������
	}//main

}// class