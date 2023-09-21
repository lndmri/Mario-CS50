#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string test = "Hello";

    int i = 0;
    while (test[i] != '\0'){

        printf("%c\n", test[i]);
        i++;
    }

    test[i-1] = '\0';
    printf("%s",test);

}
