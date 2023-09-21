#include <cs50.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Program Logic

// open card
//     while (not end of file)
//     read from card 512 bytes each time

//     if found jpeg header

//         if first jpeg
//         create a jpeg on write mode  (name file with sprintf)
//         writing the buffer into it

//         else (not first jpeg)
//             close existent jpeg
//             create a new one
//             write the bits

//     else
//         if already writing on a jpeg keep writing
// end while

// Close any remaining file

int main(int argc, char *argv[])
{
    // Oe are going to make our buffer of type uint8_t but we will use BYTe for ease of use
    typedef uint8_t BYTE;
    const int BLOCK_SIZE = 512;

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // Open Card FIle
    FILE *card = fopen(argv[1], "r");

    BYTE buffer[512];
    char filename[8];

    bool jpeg_open = false;
    int counter = 0;
    FILE *img = NULL;

    //  while loop
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {


            if (!jpeg_open)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                jpeg_open = true;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                jpeg_open = true;
            }

            counter++;
        }

        else
        {
            if (jpeg_open)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
            else
            {
                continue;
            }
        }

        // printf("jpeg %i\n", counter);
    }

    fclose(img);
    fclose(card);


}
