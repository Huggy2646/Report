#include <stdio.h>
int main(void)
{
    int n =0;
    scanf("%d",&n);
    for(int i=1; i<n+1; i++)
    {
        for(int j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}