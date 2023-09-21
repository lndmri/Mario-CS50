#include <stdio.h>
typedef unsigned int bool_t;

/*
Author: Mario A Landa Pulido
U_Number: U63987600
Purpose: This program checks if a number is special. A number is special if it contains at least a digit '3' and is divisible by 3
*/

int main(void)
{
    int number;
    bool_t has_three = 0;
    printf("Enter input: ");
    scanf("%d", &number);

    int temp = number;

    // Checking if number has a 3
    while (temp)
    {
        if (temp % 10 == 3)
        {
            has_three = 1;
            break;
        }
        temp /= 10;
    }

    if ((has_three) && (number % 3 == 0))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}