#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // Color of my choosing
    RGBTRIPLE color_set;
    color_set.rgbtBlue = 0x5E;
    color_set.rgbtGreen = 0x26;
    color_set.rgbtRed = 0xE8;

    // maiking i the height / j is the width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = color_set.rgbtBlue;
                image[i][j].rgbtGreen = color_set.rgbtGreen;
                image[i][j].rgbtRed = color_set.rgbtRed;
            }
        }
    }
}
