#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.h"
#include "utils.h"

#define LEN 300

int main(void)
{
    //Read input
    FILE *file = fopen("./input.txt", "r");
    if (file == NULL) return 1;
    int *arr1 = malloc(LEN * sizeof(int));
    for(int i = 0; i < LEN; i++) fscanf(file, "%d", &arr1[i]);
    fclose(file);

    //Read expected output
    FILE *file2 = fopen("./output.txt", "r");
    if (file2 == NULL) return 1;
    int *expected = malloc(LEN * sizeof(int));
    for(int i = 0; i < LEN; i++) fscanf(file2, "%d", &expected[i]);
    fclose(file2);



    int *arr2 = malloc(300*sizeof(int));
    int *arr3 = malloc(300*sizeof(int));
    int *arr4 = malloc(300*sizeof(int));
    int *arr5 = malloc(300*sizeof(int));
    copy_array(arr1, arr2, 300);
    copy_array(arr1, arr3, 300);
    copy_array(arr1, arr4, 300);
    copy_array(arr1, arr5, 300);


    printf("--------------------\n");
    clock_t start1 = clock();
    selection_sort(arr1,300);
    clock_t end1 = clock();
    printf("selection_sort\n");
    if (check(arr1, expected, LEN)) printf("Correct answer\n");
    else printf("False answer\n");
    printf("time : %d ms\n", (end1-start1)*1000);


    printf("--------------------\n");
    clock_t start2 = clock();
    insertion_sort(arr2,300);
    clock_t end2 = clock();
    printf("insertion_sort\n");
    if (check(arr2, expected, LEN)) printf("Correct answer\n");
    else printf("False answer\n");
    printf("time : %d ms\n", (end2-start2)*1000);


    printf("--------------------\n");
    clock_t start3 = clock();
    bubble_sort(arr3,300);
    clock_t end3 = clock();
    printf("bubble_sort\n");
    if (check(arr3, expected, LEN)) printf("Correct answer\n");
    else printf("False answer\n");
    printf("time : %d ms\n", (end3-start3)*1000);


    printf("--------------------\n");
    clock_t start4 = clock();
    merge_sort(arr4,300);
    clock_t end4 = clock();
    printf("merge_sort\n");
    if (check(arr4, expected, LEN)) printf("Correct answer\n");
    else printf("False answer\n");
    printf("time : %d ms\n", (end4-start4)*1000);


    printf("--------------------\n");
    clock_t start5 = clock();
    quick_sort(arr5,300);
    clock_t end5 = clock();
    printf("quick_sort\n");
    if (check(arr5, expected, LEN)) printf("Correct answer\n");
    else printf("False answer\n");
    printf("time : %d ms\n", (end5-start5)*1000);



    return 0;
}
