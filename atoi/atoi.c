#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int len = strlen(input);



    // base case
    // if length is one then return the digit - '0'
    if (len == 1)
    {
        return input[0] - '0';
    }

    // recursive case

    char last_digit = input[len - 1];
    char converted_char = last_digit - '0';

    // Remove the last char from the string by moving the null terminator one position to the left.
    input[len-1] = '\0';

    // Return this value plus 10 times the integer value of the new shortened string.
    return converted_char + 10 * convert(input);
}