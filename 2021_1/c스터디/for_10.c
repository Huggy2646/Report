#include <stdio.h>
int main(void)
{
    int n =0;
    scanf("%d",&n);
    for(int i=1; i<n+1; i++)
    {
        for(int j=n-i; j>0; j--)
            printf(" ");
        for(int j=0; j<i; j++)
            printf("%c",42);
        
        printf("\n");
    }
    return 0;
}