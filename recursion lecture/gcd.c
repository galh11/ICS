#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcd:
int gcd(int m, int n)
{
    if (n == 0) return m;
    return gcd(n, m%n);
}

int gcd_wrapper(int m, int n)
{
    if (m < 0) m = -m;
    if (n < 0) n = -n;
    return gcd(m, n);
}

// time complexity for gcd: theta(logn)