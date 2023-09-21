#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


void scan(int width, int height, int pos_row, int pos_column, int arr[3][3]);

int main(void)
{
    int numbers[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           scan(3,3,i,j,numbers);
        }
    }

}

void scan(int width, int height, int pos_row, int pos_column, int arr[3][3])
{
    int row = 0;
    int column = 0;

    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            row = pos_row + i;
            column = pos_column + j;

            if (row < width && row >= 0 && column < width && column >= 0)
            {
                printf("%i \n",arr[row][column]);
            }

        }
    }
    printf("END\n");
}