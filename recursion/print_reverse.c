#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_reverse()
{
    char c = getchar();
    if (c == '\n' || c == EOF) return;
    print_reverse();
    putchar(c);
}

int main(void)
{
    print_reverse();
    return 0;
}