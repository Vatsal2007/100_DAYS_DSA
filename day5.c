#include <stdio.h>

int main()
{
    int p,q,i=0,j=0;
    scanf("%d",&p);
    int a[p];
    for(int x=0;x<p;x++) scanf("%d",&a[x]);
    scanf("%d",&q);
    int b[q];
    for(int x=0;x<q;x++) scanf("%d",&b[x]);

    while(i<p && j<q)
    {
        if(a[i]<=b[j]) printf("%d ",a[i++]);
        else printf("%d ",b[j++]);
    }

    while(i<p) printf("%d ",a[i++]);
    while(j<q) printf("%d ",b[j++]);

    return 0;
}
