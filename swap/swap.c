#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    swap(&x, &y);

    //after swap
    printf("x is %i, y is %i\n", x, y);
}

// passing the variables as reference and not as values (copies)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}