#include <stdio.h>
int main()
{
    int n,i;
    int a[100];
    int l,r,temp;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    l=0;
    r=n-1;
    while(l<r)
    {
        temp=a[l];
        a[l]=a[r];
        a[r]=temp;
        l++;
        r--;}
    printf("reversed array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
    }
