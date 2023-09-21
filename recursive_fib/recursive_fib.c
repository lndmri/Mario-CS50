#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibonacci_sum (int n);

int main(int argc, string argv[])
{
    int n = atoi(argv[1]);u
    printf("%i\n",fibonacci_sum(n));

}

int fibonacci_sum (int n)
{
    // base case
    if (n < 2)
    {
        return n;
    }
    return fibonacci_sum(n - 1) + fibonacci_sum(n - 2);

}