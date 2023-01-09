#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int a[], int na, int b[], int nb, int c[])
{
    int ia = 0, ib = 0, ic = 0;
    while(ia < na && ib < nb)
    {
        if(a[ia] < b[ib])
        {
            c[ic] = a[ia];
            ia++;
        }
        else
        {
            c[ic] = b[ib];
            ib++;
        }
        ic++;
    }
    for(;ia < na; ia++, ic++)
        c[ic] = a[ia];
    for(;ib < nb; ib++, ic++)
        c[ic] = b[ib];
}

void merge_sort(int a[], int n)
{
    if(n==1) return;
    merge_sort(a, n/2);
    merge_sort(a+n/2, n-n/2);
    int *p=(int *)malloc(sizeof(int)*n);
    merge(a, n/2, a+n/2, n-n/2, p);
    for(int i=0; i<n; i++) a[i]=p[i];
    free(p);
}

int main(void)
{
    int a[9] = {9,4,8,5,6,7,2,3,1};
    merge_sort(a, 9);
    for (int i = 0; i < 9; i++)
        printf("%i\n", a[i]);
    return 0;
}

memcpy(destination, source, ammount of bites);