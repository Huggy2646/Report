#include <stdio.h>
#include <vector>
long long sum(std::vector<int> &a)
{
	long long ans = 0;
    
	return ans;
}
// long long sum(int *a,int n)
// {
//     long long result=0;
//     for(int i=0; i<n; i++)
//     {
//         result+=a[i];
//     }

//     return result;
// }

int main(void)
{
    int n=0;
    int value=0;
    int a[100];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&value);
        a[i]=value;
    }
    printf("%d",sum(n,a));
}

