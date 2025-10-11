#include <stdio.h>
#include <time.h>
#include "fib.h"


void main()
{
    int n = 10;
    clock_t start1 = clock();
    int fibo1 = fib_naive(n);
    clock_t end1 = clock();
    int time1 = (end1 - start1)*1000;
    printf("Naive: %d , done in %d ms\n", fibo1, time1);


    clock_t start2 = clock();
    for (int i=0; i<MAX; i++)
    {
        *(memo + i) = -1;
    }
    int fibo2 = fib_dyn(n);
    clock_t end2 = clock();
    int time2 = (end2 - start2)*1000;
    printf("Dynamic: %d , done in %d ms\n", fibo2, time2);
}
