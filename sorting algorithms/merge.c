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

/* time complexity:
    for a: na iterations
    for b: nb iterations
    in total: theta(na+nb) = theta(n)
*/

int main(void)
{
    int a[5] = {1,3,5,7,9};
    int b[4] = {2,4,6,8};
    int c[9];
    merge(a, 5, b, 4, c);
    for (int i = 0; i < 9; i++)
        printf("%i\n", c[i]);
    return 0;
}