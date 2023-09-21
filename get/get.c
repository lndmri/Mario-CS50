#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i",&x);
    printf("%i\n",x);

    // strings are pointers already so you do not need to referece its address in scanf since
    char s[4];
    printf("s: ");
    scanf("%s",s);
    printf("%s\n",s);
}