#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // if you use valgrind ./memory you would get the memory report utilized in the program
    // Golden rule: if you use malloc, then use a free to clear the memory allocated.
    int *x = malloc(3 * sizeof(int));

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);

    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n",scores[i]);
    }
}