#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    marking p = a[0]
    using two indices (t - top, b - bottom) we scan from both sides the remainder of the string
    progressing t if a[t] > p
    else progressing 
*/

int partition(int arr[], int n)
{
    swap(arr, arr+n/2); // some swap function
    int pivot = arr[0];
    int b = 1, t = n-1;
    while (b <= t)
    {
        while (b <= t && arr[t] >= pivot)
            t--;
        while (b <= t && arr[b] < pivot)
            b++;
        if (b < t)
        {
            swap(arr+b, arr+t);
            b++;
            t--;
        }
    }
    swap(arr, arr+t);
    return t;
}

void quick_sort (int arr[], int n)
{
    if (n <= 1) return;
    int left = partition(arr, n);
    int right = n - left - 1;
    quick_sort(arr, left);
    quick_sort(arr + left + 1, right);
}

int main ()
{
    return 0;
}