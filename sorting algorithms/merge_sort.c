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

void merge_sort(int a[], int n, int* helper)
{
    if(n==1) return;
    merge_sort(a, n/2, helper);
    merge_sort(a+n/2, n-n/2, helper);
    merge(a, n/2, a+n/2, n-n/2, helper);
    for(int i = 0; i < n; i++) a[i] = helper[i]; // memcpy(destination, source, ammount of bites);
}

void merge_sort_aux (int a[], int n)
{
    int *helper = malloc(n*sizeof(int));
    if (!helper) return;
    merge_sort(a, n, helper);
    free(helper);
}

int main(void)
{
    int a[9] = {9,4,8,5,6,7,2,3,1};
    merge_sort_aux(a, 9);
    for (int i = 0; i < 9; i++)
        printf("%i\n", a[i]);
    return 0;
}

/*
    time complexity = theta(nlogn) :

    T(n) = 2n + 1 + T(n/2) T(n/2)


    T(n) = 2n + 2T(n/2) ,   T(0) = T(1) = 1


    T(n/2) = 2(n/2) + 2T(n/(2^2))

    insert in original equation:

    T(n) = 2n + 2n + (2^2)T(n/(2^2)) = (2^2)n + (2^2)T(n/(2^2))


    T(n/(2^2)) = (2^2)(n/(2^2)) + (2^2)T((n/(2^2))/(2^2))


    T(n) = (2^2)n + (2^2)((2^2)(n/(2^2)) + (2^2)T((n/(2^2))/(2^2)))
    .
    .
    .

    T(n) = k*2n + (2^k)T(n/(2^k))

    n/(2^k) = 1 ---> k = log_2(n)

    T(n) = 2n*log_2(n) + (2^log_2(n))T(n/(2^log_2(n))) = 2n*log_2(n) + nT(1) = nlogn
*/