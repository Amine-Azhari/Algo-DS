#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        int min = arr[i];
        int ind = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j]<min)
            {
                min = arr[j];
                ind = j;
            }
        }
        swap_int(&arr[i],&arr[ind]);
    }
}

void insertion_sort(int *arr, int n)
{
    for (int i=0; i<n;i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubble_sort(int *arr, int n)
{
    while(!is_sorted_nondecreasing(arr,n))
    {
        for (int i=0;i<n-1;i++)
        {
            if (arr[i]>arr[i+1])
            {
                swap_int(&arr[i], &arr[i+1]);
            }
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    int i=l;
    int j=m+1;
    int k=l;

    while (i<=m && j<=r)
    {
        if (arr[i]<arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=m)
    {
        tmp[k] = arr[i];
        i++;
        k++;
    }

    while(j<=r)
    {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    //copying tmp elements in arr
    //so we can restart same process again

    for (i=l;i<=r;i++)
    {
        arr[i] = tmp[i];
    }
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
    if (l<r)
    {
     int m=(l+r)/2;

    mergesort_rec(arr,tmp,l,m); // we start with the left sub-array
    mergesort_rec(arr,tmp,m+1,r); //then same for the right array

    merge(arr, tmp, l, m, r); //then merge both left and right
    }
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}



int partition(int *arr, int l, int r)
{
    // partition function

    int pivot = arr[r];

    int i = l-1;

    for (int j=l; j<r; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            if (arr[i] != arr[j])
            {
                swap_int(&arr[i],&arr[j]);
            }
        }
    }

    swap_int(&arr[i+1], &arr[r]);
    return i+1;

}

void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
    if (l<r)
    {
        int part = partition(arr, l, r);

        quick_sort_rec(arr, l, part-1);
        quick_sort_rec(arr, part+1, r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}
