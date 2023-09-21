#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }


    // alocate memory for string t
    // malloc -> memory allocation in bytes

    char *t = malloc(strlen(s)+ 1);

    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }

    if (strlen(t))
    {
        t[0] = toupper(t[0]);
    }

    printf("%s \n",s);
    printf("%s \n",t);

}