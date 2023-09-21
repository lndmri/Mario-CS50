#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    // an array of Strings;
    string strings[] = {"battleship", "boot", "cannon", "iron","thimble","top hat"};

    // search for string
    string s = get_string("String: ");

    for (int i = 0; i < strlen(s); i++)
    {
        if (strcmp(strings[i],s) == 0)
        {
            printf("Found\n");
            return 0;
        }

    }
    printf("Not Found\n");
    return 1;
}


