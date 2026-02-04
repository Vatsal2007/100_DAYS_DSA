#include <stdio.h>

int main()
{
    int n,i,k;
    int a[100];
    int c=0,flag=0;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter key: ");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        c++; 
        if(a[i]==k)
        {
            printf("key found at position %d\n",i+1);
            flag=1;
            break;}}
    if(flag==0)
        printf("key not found\n");
    printf("comparisons = %d",c);
    return 0;}

