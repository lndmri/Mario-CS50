#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool strcompare (char *s, char *t);

int main(void)
{
    // Working with string Comparison

    char * string1 = get_string("String 1: ");
    char * string2 = get_string("String 2: ");

    if (strcompare(string1, string2))
    {
        printf("Equal\n");
    }
    else
    {
        printf("Different\n");
    }
}



bool strcompare (char *s, char *t)
{
    bool equal = true;
    if (strlen(s) == strlen(t))
    {
        for(int i = 0, n = strlen(s) + 1; i < n; i++)
        {
            if (*(s + i) == *(t + i))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
       return false;
    }

    return true;

}