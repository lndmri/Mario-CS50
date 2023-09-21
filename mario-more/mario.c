#include <cs50.h>
#include <stdio.h>

// Generate grid level
void generate_grid_level(int n, int size);

int main(void)
{
    const int max_height = 8;
    const int min_height = 1;
    int height = 0;

    do
    {
        height = get_int("Height: ");
    }
    while (height < min_height || height > max_height);

    for (int i = 1; i <= height; i++)
    {
        generate_grid_level(i, height);
    }

}

void generate_grid_level(int n, int size)
{
    const int middle_spaces = 2;

    // First set of spaces
    for (int i = n; i < size; i++)
    {
        printf(" ");
    }

    // First set of hashes
    for (int i = 1; i <= n; i++)
    {
        printf("#");
    }

    // Two-space separation
    for (int i = 0; i < middle_spaces; i++)
    {
        printf(" ");
    }

    // Final set of hashes
    for (int i = 1; i <= n; i++)
    {
        printf("#");
    }

    printf("\n");
}