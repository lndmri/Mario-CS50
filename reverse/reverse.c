#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"


int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Proper usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *ipt_audio = fopen(argv[1], "r");
    if (ipt_audio == NULL)
    {
        printf("File did not open correctly\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, ipt_audio);



    // Use check_format to ensure WAV format
    // TODO #4
    bool is_wav = check_format(header);


    // Open output file for writing
    // TODO #5

    if (is_wav)
    {
        FILE *opt_audio = fopen(argv[2], "w");
        if (opt_audio != NULL)
        {
            // Write header to file
            // TODO #6
            fwrite(&header, sizeof(WAVHEADER), 1, opt_audio);

            // Use get_block_size to calculate size of block
            // TODO #7
            int block_size = get_block_size(header);

            // each sample has 32 bytes

            // Write reversed audio to file
            // TODO #8

            int num_samples = header.subchunk2Size / (block_size);

            BYTE aux_array[header.subchunk2Size];

            for (int i = 0; i < header.subchunk2Size; i+=2)
            {
                fread(&aux_array[i], block_size, 2, ipt_audio);
            }
            BYTE reversed_array[header.subchunk2Size];
            for (int i = 0, j = header.subchunk2Size - 1 ; i < header.subchunk2Size ; i++, j--)
            {
                reversed_array[i] = aux_array[j];
                fwrite(&reversed_array[i], block_size, 1, opt_audio);

            }

            fclose(opt_audio);
        }

        else
        {
            printf("Output file did not open correctly\n");
            return 1;
        }

    }

    fclose(ipt_audio);


}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 2;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = header.bitsPerSample * header.numChannels / 8;
    return size;
}