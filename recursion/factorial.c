#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  
    recursive algorithm to calculate n!
    n! = (n-1)!*n
*/

int factorial(int n)
{
    if (n == 0) return 1;
    n *= factorial(n-1);
    return n;
}

int main(void)
{
    printf("5! = %i\n", factorial(5));
    return 0;
}

/*  we should avoid adding input check-ups that are only relevant for the first call
    instead we should use a "wrapper" to do the check-ups before calling the recursive 
    function
*/