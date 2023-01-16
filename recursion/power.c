#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double power(double x, int n)
{
    if (n == 0) return 1;
    x *= power(x, n-1);
    return x;
}
