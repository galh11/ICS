#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8

/*
    for a given board NxN
    find number of solutions to place N queens
    such that no queen is threatend
*/

void binary(int board[], int n, int col)
{
    if (col == n)
    {
        print(board, n);
        return;
    }
    for(int i=0; i<K; i++)
    {
        if (!legal(board, n, col, i))
            continue;
        board[col] = i;
        binary(board, n, col+1);
    }
}

void queens_wrapper(int n)
{
    int* board = malloc(n*sizeof(int));
    if (!board)
        return;
    binary(board, n, 0);
    free(board);
}

int main(void)
{

    return 0;
}