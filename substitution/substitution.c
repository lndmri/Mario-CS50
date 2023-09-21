#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int const KEY_SIZE = 26;
bool validate_key(string key);
void cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // Validate that one inline argument was passed
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //  Validate key
    if (validate_key(argv[1]))
    {

        //printf("KEY IS VALID\n");

        // Get string plaintext from user.

        string plaintext = get_string("Plaintext: ");

        printf("ciphertext: ");
        cipher(plaintext, argv[1]);
    }
    else
    {
        return 1;
    }


}

bool validate_key(string key)
{
    int len = strlen(key);

    // Validate if length is 26

    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Validate if all characters are letters

    for (int i = 0; i < len; i++)
    {
        if (!(isalpha(key[i])))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    // Validate if there are no repeated letters

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i == j)
            {
                continue;
            }
            // to Treat it case insensitive set the the comparison with both characters uppercase
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }

        }

    }

    return true;

}

void cipher(string plaintext, string key)
{
    int plaintext_len = strlen(plaintext);

    // for each letter in plaintext
    for (int i = 0; i < plaintext_len; i++)
    {
        //if character is NOT alphanumeric print it. || print also if it is space or blank || print also if it a digit
        if (!(isalnum(plaintext[i])) || isblank(plaintext[i]) || isdigit(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        // if char is lowercase
        // plaintext[i] - 'a'will give a value between 0-26 since 'a' is the first lowercase key in the alphabet
        // print that character from the key string lowercase
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(key[plaintext[i] - 'a']));
        }
        // if char is uppercase
        // plaintext[i] - 'A' will give a value between 0-26 since 'A' is the first lowercase key in the alphabet
        // print that character from the key string uppercase
        else if (isupper(plaintext[i]))
        {
            printf("%c", toupper(key[plaintext[i] - 'A']));
        }

    }

    printf("\n");

}