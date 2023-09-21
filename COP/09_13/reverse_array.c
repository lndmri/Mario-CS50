#include <stdio.h>

// given an array of numbers this program reverses it.

int main (void)
{
    int size, temp;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // DOING it with a for Loop

    // for (int i = 0, j = size -1; i < j; i++, j--)
    // {
    //     temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }

    // DOING it with a while Loop

    int start = 0, end = size - 1;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    for (int i = 0; i < size; i++)
    {
       printf("%d ", arr[i]);
    }

     printf("\n ");
}