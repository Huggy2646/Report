#include <stdio.h>
int main(void)
{
    int n=0;
    int result=0;
    
    scanf("%d",&n);
    
    for(int i=1 ; i<n+1; n--)
        result = result+n;

    printf("%d",result);

    return 0;
}