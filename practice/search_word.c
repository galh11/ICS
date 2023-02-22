#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M (5) //size of board
#define VISITED '-'

bool in_board (int i, int j)
{
    return (i < M && j < M && i >=0 && j >= 0);
}

bool search_word_aux (char board[M][M], char* word, int i, int j) {
    if (!*word) return true; //last character is NULL, NULL = 0 so !NULL would be true
    if (!in_board(i, j) || board[i][j] != *word) return false;
    char current_letter = board[i][j];
    board[i][j] = VISITED;
    if (search_word_aux(board, word+1, i+1, j) ||
        search_word_aux(board, word+1, i, j+1) ||
        search_word_aux(board, word+1, i-1, j) ||
        search_word_aux(board, word+1, i, j-1))
    {
        board[i][j] = current_letter;
        return true;
    }
    board[i][j] = current_letter;
    return false;
}

bool search_word (char board[M][M], char* word) {
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (search_word_aux(board, word, i, j)) return true;
        }
    }

    return false;
}

int main(void)
{
    
    return 0;
}