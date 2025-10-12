#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//naif
bool isPrime(int n)
{
    if (n <= 1) return false;
    int i = 2;
    int sqr = (int)sqrt(n);
    while(i<= sqr)
    {
        if (n%i == 0) return false;
        i++;
    }
    return true;
}


int primeNumbers(int n)
{
    int count = 0;
    for (int i=2; i<n; i++)
    {
        if (isPrime(i)) count++;
    }
    return count;
}

//dynamique

int dyn_primeNumbers(int n)
{
    bool status[n];
    int count = 0;
    status[0] = false; status[1] = false;
    for (int i=2; i<n; i++) status[i] = true;

    for (int i=2; i<n; i++)
    {
        if (status[i] == true)
        {
            for (int j=(i*i); j<n; j = j + i) status[j] = false;
        }
    }

    for (int i = 2; i<n; i++)
    {
        if (status[i]==true) count++;
    }

    return count;
}


