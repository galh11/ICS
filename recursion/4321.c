#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* will print:
                4
                3
                2
                1
*/
void babushka(int i)
{
    if(i < 1) return;
    printf("%i\n", i);
    babushka(i - 1); //calls itself 
}

int main(void)
{
    babushka(4);
    return 0;
}

