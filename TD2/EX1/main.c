#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{

    int* arr = malloc(50 * sizeof(int));
    for (int i=0; i<50; i++)
    {
        arr[i] = i*12;
    }
    int target = 144;
    if (is_sorted_nondecreasing(arr,50))
    {
        clock_t start_j = clock();
        int jump_s = jump_search(arr, 50, target);
        clock_t end_j = clock();

        clock_t start_b = clock();
        int bin_s = binary_search(arr, 50, target);
        clock_t end_b = clock();

        printf("jump : %d , done in : %d ms\n", jump_s, 1000*(start_j-end_j));
        printf("binary: %d , done in : %d ms\n", bin_s, 1000*(start_b-end_b));

    }
    else
    {
        clock_t start_l = clock();
        int lin_s = linear_search(arr, 50, target);
        clock_t end_l = clock();
        printf("linear: %d , done in : %d ms\n", lin_s, 1000*(start_l-end_l));
    }


    return 0;
}
