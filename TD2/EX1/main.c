#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{

    int arr[100];
    for (int i=0; i<50; i++)
    {
        arr[i] = i*12;
    }
    int target = 144;
    if (is_sorted_nondecreasing(arr,50))
    {
        int jump_s = jump_search(arr, 100, target);
        int bin_s = binary_search(arr, 50, target);
        printf("jump : %d\n", jump_s);
        printf("binary: %d\n", bin_s);

    }
    else
    {
        int lin_s = linear_search(arr, 50, target);
        printf("linear: %d\n", lin_s);
    }

    return 0;
}
