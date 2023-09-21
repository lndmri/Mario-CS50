#include <stdio.h>
#include <cs50.h>
#include <strings.h>
#include <string.h>



int main(void)
{
    int n = 50;
    int *p = &n;
    // printing the pointer (address)
    printf("%p\n",p);

    // printing what the pointer is pointing to (use *p)
    printf("%i\n",*p);

    // Strings are actually pointers to the first location where the string exists
    //library cs50.h states that typedef char* string
    // if we domt include the library we will have to treat strings as char * (pointer)

    char *s = "Hi!";

    // printing memory location (pointer)

    printf("%p\n",s);


    // Printing what is inside

    printf("%s\n",s);

    // printing individual chars treating the memory location as an array

    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    // printing individual chars using memory location

    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}

