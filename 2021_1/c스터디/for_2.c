#include <stdio.h>

int main(void)
{
    int t;
    int n,m;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",n+m);
    }

    return 0;
}