#include <ctype.h>
#include <stdio.h>

/*
Author: Mario A Landa Pulido
U_Number: U63987600
Purpose: This program checks if user's input is in ascending order based on its ASCII values.
If the input contains any non alphabetic character the input is considered invalid.
*/

typedef unsigned int bool_t;

int main(void)
{
    char ch;
    char last_char = 'A';
    bool_t in_order = 1;
    bool_t is_valid = 1;

    printf("Enter input: ");

    // Loop to get input
    while ((ch = getchar()) != '\n')
    {
        if (!isalpha(ch))
        {
            is_valid = 0;
            break;
        }
        else
        {
            if (last_char > ch)
            {
                in_order = 0;
                break;
            }
        }

        last_char = ch;
    }

    if (is_valid)
    {
        if (in_order)
        {
            printf("in order\n");
        }
        else
        {
            printf("not in order\n");
        }
    }
    else
    {
        printf("invalid input\n");
    }

    return 0;
}