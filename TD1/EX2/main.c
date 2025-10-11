#include <stdio.h>
#include "primeNums.h"

void main()
{
    int n = 20;
    int primes = primeNumbers(n);
    int dyn_primes = dyn_primeNumbers(n);
    printf("primes= %d\n", primes);
    printf("dyn_primes= %d\n", dyn_primes);

}

