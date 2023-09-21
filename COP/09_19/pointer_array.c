#include <stdio.h>

int main(void)
{
    printf("Enter 4 values:");
    int arr[4];
    int *p = &arr[0];


    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &arr[0]);
    }

    printf("Addresses occupied:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%p\n", &arr[i]);
    }

    // printing it another way.
    printf("Printing it another way:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%p\n", p+i);
    }
}