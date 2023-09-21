#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    bool prime;
    // TODO

    // This variable square root will reduce
    // The search in half since any number no prime
    // If has divisors have a pair of divisors before and after its sqrt
    int square_root = sqrt(number) + 1;

    if (number == 1)
    {
        return false;
    }
    // Loop excluding 1 and number itself

    for (int i = 2; i < square_root; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
