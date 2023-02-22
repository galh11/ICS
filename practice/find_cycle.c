#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N (10)

int find_cycle_aux(int a[N][N], int v, int path[], int count, int goal)
{
    if (count == N-1) return a[v][goal]; //returns 1 if there's a path from last corner to first corner, else returns 0
    path[v] = 1; // marks where we've already been
    for(int i = 0; i < N; i++)
    {
        if (a[v][i] && !path[i]) // if there's a path and it was not crossed yet
        {
            if (find_cycle_aux(a, i, path, count+1, goal)) return 1;
        }
    }
    path[v] = 0; //unmark current corner from path.
    return 0;
}

int find_cycle(int a[N][N], int v)
{
    int path[N] = {0}; // to track where we've been
    int goal = v;
    return find_cycle_aux(a, v, path, 0, goal);
}

int main(void)
{
    
    return 0;
}