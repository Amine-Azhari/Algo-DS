#include "utils.h"
#include <stdbool.h>

bool is_sorted_nondecreasing(int *arr, int n)
{
    int i=1;
    while (i<n){
        if (arr[i]<arr[i-1]) return false;
        i++;
    }
    return true;
}

int min_int(int a, int b)
{
    if (a<b) return a;
    return b;
}
