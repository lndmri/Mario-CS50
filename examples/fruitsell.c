#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // correct use
    if (argc != 2)
    {
        printf("Correct usage: ./fruitsell inptut_file\n");
        return 1;
    }

    FILE *infile_w = fopen(argv[1],"a");


     char *temp = "Sample";


    while (true)
    {
        temp = get_string("To stop data entry type 'exit'. Enter a fruit: ");
        char *fruit = malloc(strlen(temp) + 1); // +1 because we need to add "\n"
        fruit = strcpy(fruit,temp);
        int len = strlen(fruit);
        fruit[len] = '\n';

        if(strcmp(temp,"exit") == 0)
        {
            break;
        }

        fwrite(fruit, len +1, 1, infile_w);
        free(fruit);
    }

    fclose(infile_w);

    printf("Program finished\n");


}