#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    int i = 0;
    while (i<n)
    {
        if (arr[i] == target) return i;
        i++;
    }

    return -1;
}


//jump search ; first method

int jump_search(int *arr, int n, int target)
{
    int jump = (int)sqrt(n);
    int i = jump;

    while ((i< n-1) && arr[i]<target) i = i+jump;

    for (int ind=(i-jump); ind<=i; ind++)
    {
        if (arr[ind] == target) return ind;
    }
    return -1;
}

//jump search ; second method

/*

int jump_search(int *arr, int n, int target)
{
    int jump = (int)sqrt(n);
    int m = jump;
    int i = 0;
    while (arr[min_int(n,m) -1]<target )
    {
        i = m;
        m = m + jump;
        if (i>= n) return -1;
    }

    for (int ind=i; ind<min_int(n,m); ind++)
    {
        if (arr[ind] == target) return ind;
    }
    return -1;
}
*/

int binary_search(int *arr, int n, int target)
{
    int left = 0;
    int right = n-1;
    while (left<=right)
    {
        int mid = (left + right)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) right = mid -1;
        else left = mid + 1;
    }

    return -1;
}
