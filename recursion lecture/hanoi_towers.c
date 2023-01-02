#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FROM 1
#define TO 2
#define VIA 3

void hanoi(int n, int from, int to)
{
    if (n == 0) return;
    int via = FROM + TO + VIA - from - to;
    hanoi(n-1, from, via);
    printf("move from %i to %i\n", from, to);
    hanoi(n-1, via, to);
}

int main(void)
{
    hanoi(5, FROM, TO);
    return 0;
}