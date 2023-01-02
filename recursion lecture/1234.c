#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  will print:
                1
                2
                3
                4
*/
void babushka(int i)
{
    if(i < 1) return;
    babushka(i - 1); //calls itself 
    printf("%i\n", i);
}

int main(void)
{
    babushka(4);
    return 0;
}
