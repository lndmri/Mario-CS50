#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
void caesar_encipher(int key, string plaintext);

int main(int argc, string argv[])
{
    // Check if 1 inline argument was passed
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // Validate key
    if (only_digits(argv[1]))
    {
        int key = atoi(argv[1]) % 26;
        // printf("Key is %i\n",key);


        // Get plaintext
        string plaintext = get_string("plaintext: ");

        // Encipher
        printf("ciphertext: ");
        caesar_encipher(key,  plaintext);

    }
    else
    {
        return 1;
    }


}

bool only_digits(string s)
{
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            printf("Argument must be a number\n");
            return false;
        }
    }
    return true;
}

void caesar_encipher(int key, string plaintext)
{
    int len = strlen(plaintext);
    //create char array
    char ciphertext[len];


    for (int i = 0; i < len; i++)
    {
        // if it is NOT alpha add it as it is to the ciphertext array
        if (!isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }

        // if it is uppercase get index in base 26 by substracting 'A' from the ascii value of plaintext i
        // add the key  to that index
        // convert that number to ascii again by adding 'A'
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            index = (index + key) % 26;
            ciphertext[i] = index + 'A';
        }

        if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            index = (index + key) % 26;
            ciphertext[i] = index + 'a';
        }

        printf("%c", ciphertext[i]);

    }

    printf("\n");
}