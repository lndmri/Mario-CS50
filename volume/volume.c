// Modifies the volume of an audio file

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    uint8_t header[44];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer = 2;

    while (true)
    {
        // because fread returns 0 or a number shorter than nmeb (3 arg of the fread function) when EOF is reached.
        if (fread(&buffer, 16, 1, input) == 0)
        {
            // printf("END OF FILE");
            break;
        }

        // printf("%i\n", buffer);
        buffer *= 2;

        fwrite(&buffer, 16, 1, output);
        buffer = 2;
    }

    // Close files
    fclose(input);
    fclose(output);
}
