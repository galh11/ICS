#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K 3

void print(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// print all binary words in legnth n
void binary(int word[], int n, int index)
{
    if (index == n)
    {
        print(word, n);
        return;
    }
    for(int i=0; i<K; i++)
    {
        word[index] = i;
        binary(word, n, index+1);
    }
}

// print all binary words in legnth n with different letters
void binary_with_different_letters(int word[], int n, int index, int used[])
{
    if (index == n)
    {
        print(word, n);
        return;
    }
    for(int i=0; i<K; i++)
    {
        // if (!legal(word, index, i))
        //     continue;
        if (used[i] == 1) //prefer helper arrays over loops
            continue;
        used[i] = 1;
        word[index] = i;
        binary_with_different_letters(word, n, index+1, used);
        used[i] = 0;
    }
}

void biniary_wrapper(int n)
{
    int* word = malloc(n*sizeof(int));
    if(!word)
        return;
    int used[K] = {0};
    binary_with_different_letters(word, n, 0, used);
    free(word);
}

int main(void)
{
    binary_wrapper(3);
    return 0;    
}