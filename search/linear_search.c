#include <cs50.h>
#include <stdio.h>


bool linear_search(int key, int arr[]);

int main(void)
{
    // An array of integers
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};


    int array_length = sizeof(numbers) / sizeof(numbers[0]);

    int key = get_int("Number: ");

    if (linear_search(key, numbers))
    {
        printf("Number is found!");
    }
    else
    {
        printf("Number is not found");
    }


}


bool linear_search(int key, int arr[])
{
    // This is good way to determine the size of an array.
    // Sizeof(expression) operator gives you the size in bytes of the expression inside
    // size of entire array / size of one element = amount of elements in the array

    int array_length = sizeof(arr) / sizeof(arr[0]);

     for (int i = 0; i < array_length; i++)
    {
        if (key == arr[i])
        {
            return true;
        }
    }

    return false;

}