#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 8
#define DIAG (N*2 - 1)

void solutions_finder(int board[], int column, bool used[3][DIAG]);
void solution_print(int board[], int size);
void used_add (bool used[3][DIAG], int row, int column);
void used_remove (bool used[3][DIAG], int row, int column);
bool legal (bool used[3][DIAG], int row, int column);
/*
    for a given board NxN
    find number of solutions to place N queens
    such that no queen is threatend
*/

void solutions_finder(int board[], int column, bool used[3][DIAG])
{
    if (column >= N)
    {
        solution_print(board, N);
        return;
    }
    for (int row = 0; row < N; row++)
    {
        if (!legal(used, row, column))
    }
}

int main (void)
{
    int board[N];
    int used[3][DIAG]; //row, up-diag, down-diag

    /*
        initializing used arrays.
        note that there are only N rows so the
        remaining elemnts in used[0] will be discarded
    */

    for (int i=0; i < DIAG; i++)
        used[0][i] = used[1][i] = used[2][i] = false;
    
    printf("Solving the %d Queens Problem\n\n", N);
    solution_finder(board, 0, used);
    printf("\nDone!\n");

    return 0;
}