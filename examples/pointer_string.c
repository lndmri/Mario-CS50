#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *s = "hello";

    int len = strlen(s);

    char *t = malloc(len);

    for (int i = 0; i < len; i++)
    {
        t[i] = toupper(s[i]);
    }

    printf("%s\n",&t[1]);
    printf("%p\n",s);

}
