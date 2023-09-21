#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int even_arr[] = {1,2,3,4,5,6,7,8,9,10};
    int odd_arr[] = {1,2,3,4,5,6,7,8,9};

    // int *temp1 = 0;
    // int *temp2 = 0;

    int temp;

    for (int i = 0, arr_size = (sizeof(even_arr)/4) - 1; i < arr_size; i++, arr_size--)
    {
        if (arr_size <= i)
        {
            break;
        }

        // USING POINTERS - > Not necessary
        // temp1 = malloc(sizeof(int));
        // temp2 = malloc(sizeof(int));
        // *temp1 = even_arr[i];
        // *temp2 = even_arr[arr_size];
        // even_arr[i] = *temp2;
        // even_arr[arr_size]= *temp1;

        // free(temp1);
        // free(temp2);

        temp = even_arr[i];
        even_arr[i] = even_arr[arr_size];
        even_arr[arr_size] = temp;


    }

    for (int i = 0, arr_size = sizeof(even_arr)/4; i < arr_size ; i++)
    {
        printf("%i ",even_arr[i]);
    }

    printf("\n");


     for (int i = 0, arr_size = (sizeof(odd_arr)/4) - 1; i < arr_size; i++, arr_size--)
    {
        if (arr_size <= i)
        {
            break;
        }

        temp = odd_arr[i];
        odd_arr[i] = odd_arr[arr_size];
        odd_arr[arr_size] = temp;
        // temp1 = malloc(sizeof(int));
        // temp2 = malloc(sizeof(int));
        // *temp1 = odd_arr[i];
        // *temp2 = odd_arr[arr_size];
        // odd_arr[i] = *temp2;
        // odd_arr[arr_size]= *temp1;

        // free(temp1);
        // free(temp2);

    }

    for (int i = 0, arr_size = sizeof(odd_arr)/4; i < arr_size ; i++)
    {
        printf("%i ",odd_arr[i]);
    }

    printf("\n");

}