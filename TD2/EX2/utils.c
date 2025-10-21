#include "utils.h"
#include <stdbool.h>

void swap_int(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

bool is_sorted_nondecreasing(int *arr, int n)
{
    int i = 1;

    while (i<n)
    {
        if (arr[i]<arr[i-1]) return false;
        i++;
    }
    return true;
}

void copy_array(int *src, int *dst, int n)
{
    // copy array elements src into dst
    for (int i=0; i<n; i++)
    {
        *(dst + i) = *(src + i);
    }
}

bool check(int *sorted,int *expected, int sortedSize)
{
    int i = 0;
    while(i< sortedSize)
    {
        if (sorted[i] != expected[i]) return false;
        i++;
    }
    return true;
}
