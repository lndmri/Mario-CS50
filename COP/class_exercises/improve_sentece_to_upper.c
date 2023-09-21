#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    printf("Enter a message: ");

    do
    {
        ch = getchar();
        
        if (isalpha(ch))
        {
            ch = toupper(ch);
        }
        printf("%c",ch);

    }
    while(ch != '\n');
}