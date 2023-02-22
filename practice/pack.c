#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
    m - number of containers
    c - maximum load
    c*m - maximum load over-all
*/
bool pack_aux(int w[], int n, int m, int capacity[])
{
    if (!n) return true;
    for (int i = 0; i < m; i++)
    {
        if (w[0] > capacity[i]) continue;
        capcity[i] -= w[0];
        if (pack_aux(w+1, n-1, m, capacity)) return true;
        capacity[i] += w[0];
    }
    return false;
}
bool pack(int w[], int n, int m, int c)
{
    int* capacity =(int*) malloc(sizeof(int)*m);
    for( int i = 0; i < m; i++)
    {
        capacity[i] = c;
    }
    return pack_aux(w, n, m, capacity);
}

int main(void)
{
    
    return 0;
}