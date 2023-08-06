#include <stdio.h>
int main(void)
{
    int arr[100];
    int n,x,value;
    scanf("%d %d",&n,&x);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&value);
        arr[i]=value;
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<x)
            printf("%d ",arr[i]);
        else
            continue;
    }
    return 0;
}

// #include <stdio.h>
// int main(void)
// {
//     int n,x,value;
//     scanf("%d %d",&n,&x);

//     for(int i=0; i<n; i++)
//     {
//         scanf("%d",&value);
//         if(value<x)
//             printf("%d ",value);
//         else
//             continue;
//     }

//     return 0;
// }