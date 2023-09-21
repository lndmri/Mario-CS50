#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    // Get the String

    string message = get_string("Message: ");

    // Define Lenght
    int len = strlen(message);

    int asci_codes[len];

    // Loop for each letter in the message
    for (int i = 0; i < len; i++)
    {
        asci_codes[i] = message[i];

    }

    // Convert each number to binary
    int bulbs[BITS_IN_BYTE];

    // For each letter
    for (int i = 0; i < len; i++)
    {
        int num =  asci_codes[i];

        // For each bit (8 times)
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            // Save in the array each value of 0 or 1 depending on the division.
            if (num % 2)
            {
                bulbs[j] = 1;
                num /= 2;
            }
            else if (num % 2 == 0)
            {
                bulbs[j] = 0;
                num /= 2;
            }
            else if (num == 1)
            {
                bulbs[j] = 1;
                num /= 2;
            }

        }



        for (int k = 0; k <= BITS_IN_BYTE; k++)
        {
            print_bulb(bulbs[BITS_IN_BYTE - k]);
        }

        // Print New line after the first letter is processed
        printf("\n");

    }

}




void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
