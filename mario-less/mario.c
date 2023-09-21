#include <cs50.h>
#include <stdio.h>

void generate_grid_level(int n, int size);

int main(void)
{
    int const height_max = 8;
    int const height_min = 1;

    // Ask size of the grid.
    int grid_size = 0;
    do
    {
        grid_size = get_int("Height: ");

        if (grid_size > height_max || grid_size < height_min)
        {
            printf("Height needs to between 1 and 8 units\n");
        }
    }
    while (grid_size > height_max || grid_size < height_min);

    // printf("%i\n", grid_size);
    // Print the Grid

    for (int i = 1; i <= grid_size; i++)
    {
        generate_grid_level(i, grid_size);
    }

}

// Genarate Grid levels in a function.
// n is the number of #
void generate_grid_level(int n, int size)
{

    for (int j = size; j > n; j--)
    {
        printf(" ");
    }

    for (int i = 1; i <= n; i++)
    {
        printf("#");
    }
    printf("\n");
}
