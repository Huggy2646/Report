#include <stdio.h>
int main(void)
{
    int h;
    int m;
    int trans_m;
    scanf("%d %d",&h,&m);
    if(h!=0)
    {
        trans_m=h*60+m-45;
        printf("%d %d",(trans_m)/60,(trans_m)%60);
    }
    
    else if(h==0 && m>=45)
    {
        trans_m=h*60+m-45;
        printf("%d %d",(trans_m)/60,(trans_m)%60);
    }
    
    else
    {
        trans_m=24*60+m-45;
        printf("%d %d",(trans_m)/60,(trans_m)%60);
    }
    
    return 0;
}