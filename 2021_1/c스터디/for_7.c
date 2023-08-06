#include <stdio.h>
int main(void)
{
    int t=0;
    int n,m,result=0;
    scanf("%d",&t);
    for(int i=1; i<t+1; i++)
    {
        scanf("%d %d",&n,&m);
        printf("Case #%d: %d\n",i,n+m);

    }
          

    return 0;
}