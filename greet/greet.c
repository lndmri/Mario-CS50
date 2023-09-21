#include <cs50.h>
#include <stdio.h>

// Using Command Line Arguments

int main(int argc, string argv[])
{
    //string name = get_string("Name: ")

    //printf("Hello, %s\n",argv[1]);

    //Supposing that the human entered first name only
    if (argc == 2)
    {
      printf("Hello, %s\n",argv[1]);
    }

    //Supposing that the human entered first and last name
    else if (argc == 3)
    {
      printf("Hello, %s %s\n", argv[1], argv[2]);
    }
    // Supposing there was no command argument entered
    else
    {
        printf("Hello World\n");
    }
}