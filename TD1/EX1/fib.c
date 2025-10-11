#include <stdio.h>


//naif : O(2^n)
int fib_naive(int n)
{
    if (n<=1) return n;
    return fib_naive(n-1) + fib_naive(n-2);
}

//dynamique : O(n)
#define MAX 1000
int memo[MAX];

int fib_dyn(int n)
{
    if (n<=1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_dyn(n-1) + fib_dyn(n-2);
    return memo[n];
}




/*
void main()
{
    int n = 10;
    for (int i=0; i<MAX; i++)
    {
        *(memo + i) = -1;
    }
    int fibo1 = fib_naive(n);
    int fibo2 = fib_dyn(n);
    printf("%d\n", fibo1);
    printf("%d\n", fibo2);
}
*/

