// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string word = "Hello";

    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        word[i] = 'x';
    }

    printf("Changed word: %s\n", word);
}


/*
string replace(string word);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
    }
    else
    {
        printf("No command line has been inputed\n");
        return 1;
    }

}

string replace(string word)
{
    int len = strlen(word);

    for(int i = 0; i < len; i++)
    {
        switch(word[i])
        {
            case 'a':  word[i] = '6'; break;
            case 'e':  word[i] = '3'; break;
            case 'i':  word[i] = '1'; break;
            case 'o':  word[i] = '0'; break;
            default: break;
        }

    }
    return word;
}
*/