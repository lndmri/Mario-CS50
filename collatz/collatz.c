#include <cs50.h>
#include <stdio.h>


// implementing a recursive function
int collatz(int n, int steps);

int main(void)
{
    int steps = collatz(get_int("Number: "), 0);
    printf("%i steps\n", steps);
}

// recursive function
int collatz(int n, int steps)
{
    // base case
    // if number is one return steps
    if (n == 1)
    {
        return steps;
    }
    // recursive cases
    // process according to collatz conjecture recursively implemented if number is different than one and it is analazing it is even or odd

    else if (n != 1 &&  n % 2 == 0)
    {
        steps++;
        return collatz(n/2, steps);
    }
    else if (n != 1 &&  n % 2 == 1)
    {
        steps++;
        return collatz((3*n + 1), steps);
    }

    return steps;


}