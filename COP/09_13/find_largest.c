#include <stdio.h>

int main(void)
{
    int largest, size;

    printf("Enter array length: ");
    scanf("%d",size);

    int nums[size];

    printf("Enter array elements: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d",nums[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ",nums[i]);
    }

     printf("exit");
}