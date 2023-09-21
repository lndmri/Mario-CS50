#include <stdio.h>

int main(void)
{
    int i = 4;
    int j = 6;
    int *p = &i;
    int *q = &j;

    printf("i is %d, p is %p\n", i, p);
    return 0;
}