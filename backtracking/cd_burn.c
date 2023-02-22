#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    find largest sum that's below the max size
    @x - size of cd
    @n - number of files
*/
int bestburn(int sizes[], int n, int x, bool chosen[])
{
    int free1, free2; //free space in each array
    if (n==0) return x;
    if (x==0)
    {
        for (int i=0; i<n; i++) chosen[i] = false;
        return 0;
    }
    chosen[0] = false;
    free1 = bestburn(sizes+1,n-1,x,chosen+1);
    if (sizes[0] <= x)
    {
        bool *chosen2 = (bool*)malloc(n*sizeof(bool));

        chosen2[0] = true;
        free2 = bestburn(sizes+1, n-1, x-sizes[0], chosen2+1);

        if (free2 < free1)
        {
            for (int i=0; i<n; ++i)
                chosen[i] = chosen2[i];
            free(chosen2);
            return free2;
        }
        free(chosen2);
    }
    return free1;
}

int main(void)
{
    
    return 0;
}