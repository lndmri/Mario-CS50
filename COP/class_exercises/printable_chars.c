#include <stdio.h>

int main(void)
{
    for (int i = 32; i <= 126; i++)
    {
        printf("%c %d\n", (char)i, i);
    }
    return 0;
}