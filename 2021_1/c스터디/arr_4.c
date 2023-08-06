#include <stdio.h>
void del(int arr[],int i,int arr_len)
{
    
    for(;i<arr_len-1;i++)
    {
        arr[i]=arr[i+1];
    }
}
int main(void)
{
    int a=0;
    int arr_len=10;
    int count=0;
    int arr[100];
    
    for(int i=0; i<arr_len; i++)
    {
        scanf("%d",&a);
        arr[i]=a%42;
        // printf("%d\n",a%42);
    }
       
    for(int i=0; i<arr_len; i++)
    {
        for(int j=i+1; j<arr_len;j++)
        {
            if(arr[i]==arr[j])
            {
                del(arr,i,arr_len);
                arr_len--;
                
            }   
        }
    }
    
    for(int i=0; i<arr_len;i++)
    {
        count++;
        printf("%d",arr[i]);
    }

    // printf("%d",count);
}