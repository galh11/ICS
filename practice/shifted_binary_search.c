#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int binary_search(int a[], int n, int x)
{
    int low = 0, high = n-1, mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (a[mid] == x) return mid;
        if (a[mid] < x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

/*
    we want to first find the "breaking point" of the array using binary search
    then we'd like to use binary search again on both subarrays to 
*/
int findshifted(int a[], int n, int x)
{
    int low = 0, high = n-1, mid;
    while (low <= high)
    {
        mid = (high + low)/2;
        if (a[low] >= a[mid]) high = mid - 1;
        else if (a[high] <= a[mid]) low = mid + 1;
        if (a[mid] < a[mid - 1]) break;
    }
    int index = binary_search(a, mid, x);
    if (index != -1) return index;
    index = binary_search(a+mid, n-mid, x);
    return (index != -1) ? index+mid : -1;
}

int main(void)
{
    
    return 0;
}