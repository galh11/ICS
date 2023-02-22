#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool solvemaze(int maze[N][N], int i, int j)
{
    if (maze[i][j] == 0 || maze[i][j] == 2) return false;
    if (i==N-1 && j==N-1) return true;

    maze[i][j] = 2;
    if (    ((i < N-1) && solvemaze(maze, i+1, j))  ||
            ((j < N-1) && solvemaze(maze, i, j+1))  ||
            ((i > 0) && solvemaze(maze, i-1, j))    ||
            ((j > 0) && solvemaze(maze, i, j-1))    )   {
        maze[i][j] = 1;
        return true;
    }
    maze[i][j] = 1;
    return false;
}

int main(void)
{
    
    return 0;
}