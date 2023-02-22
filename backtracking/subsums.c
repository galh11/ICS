#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    subsum1: checks if there's a sum of different elements in the array
    that equals x.
    returns true or false
*/
bool subsum1(unsigned int a[], int n, unsigned int x)
{
    if (x==0) return true;
    if (n<=0) return false;

    if (a[0]<=x && subsum1(a+1, n-1, x-a[0]))
        return true;
    
    return subsum1(a+1, n-1, x);
}

/*
    subsum2: checks if there's a sum of different elements in the array
    that equals x.
    if fails returns -1,
    else, returns number of elements.
*/
int subsum2(unsigned int a[], int n, unsigned int x)
{
    if (x==0) return 0;
    if (n<=0) return -1;

    if (a[0]<=x)
    {
        int k = subsum2(a+1, n-1, x-a[0]);
        if (k > -1) return k+1;
    }
    return subsum2(a+1, n-1, x);
}

/*
    subsum3: checks if there's a sum of different elements in the array
    that equals x.
    if fails returns -1,
    else, returns the elements.
*/
int subsum3(unsigned int a[], int n, unsigned int x, unsigned int b[], int index)
{
    if (x==0) return 0;
    if (n<=0) return -1;

    if (a[0]<=x)
    {
        int k = subsum3(a+1, n-1, x-a[0], b+1, index+1);
        if (k > -1)
        {
            b[0] = index;
            return k+1;
        }
    }
    return subsum3(a+1, n-1, x, b, index+1);
}

int subsum3_aux(unsigned int a[], int n, unsigned int x, unsigned int b[])
{
    return subsum3(a, n, x, b, 0);
}

int main(void)
{
    
    return 0;
}