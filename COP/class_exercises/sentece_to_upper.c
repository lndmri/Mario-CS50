#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a message: ");

    ch = getchar();

    while (ch != '\n')
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }

        printf("%c",ch);

        ch = getchar();

    }

    printf("\n");

}