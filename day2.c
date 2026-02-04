#include <stdio.h>
int main()
{
    int n,i,pos;
    int a[100];
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter pos to delete: ");
    scanf("%d",&pos);
    for(i=pos-1;i<n-1;i++)
        a[i]=a[i+1];
    n--;
    printf("array after delete:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;}
