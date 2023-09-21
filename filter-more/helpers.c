#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int rgbt_average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Have to adjust to float so it expresion does not truncates as int after division
            rgbt_average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float) 3);
            image[i][j].rgbtBlue = rgbt_average;
            image[i][j].rgbtGreen = rgbt_average;
            image[i][j].rgbtRed = rgbt_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue = 0;
    int sepiaGreen = 0;
    int sepiaRed = 0;
    uint8_t originalBlue = 0;
    uint8_t originalGreen = 0;
    uint8_t originalRed = 0;
    int MAX_COLOR = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;
            originalRed = image[i][j].rgbtRed;

            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            // printf("Original: B %u\tG %u\tR %u\n",originalBlue,originalGreen,originalRed);
            // printf("Sepia: B %u\tG %u\tR %u\n",sepiaBlue,sepiaGreen,sepiaRed);

            if (sepiaBlue > MAX_COLOR)
            {
                sepiaBlue = MAX_COLOR;
            }

            if (sepiaGreen > MAX_COLOR)
            {
                sepiaGreen = MAX_COLOR;
            }

            if (sepiaRed > MAX_COLOR)
            {
                sepiaRed = MAX_COLOR;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0, row_size = width - 1; j < row_size; j++, row_size--)
        {
            if (row_size <= j)
            {
                break;
            }

            temp = image[i][j];
            image[i][j] = image[i][row_size];
            image[i][row_size] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // make copy of image array
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }
    // for each element of the image array
    // for each row
    for (int a = 0; a < height; a++)
    {
        // for each column
        for (int b = 0; b < width; b++)
        {
            int row = 0;
            int column = 0;
            int counter = 0;
            int average_red = 0;
            int average_green = 0;
            int average_blue = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    row = a + i;
                    column = b + j;

                    if (row < width && row >= 0 && column < width && column >= 0)
                    {
                        average_red += image_copy[row][column].rgbtRed;
                        average_green += image_copy[row][column].rgbtGreen;
                        average_blue += image_copy[row][column].rgbtBlue;
                        counter++;
                    }
                }
            }

            average_red = round(average_red / (float) counter);
            average_green = round(average_green / (float) counter);
            average_blue = round(average_blue / (float) counter);

            image[a][b].rgbtRed = average_red;
            image[a][b].rgbtGreen = average_green;
            image[a][b].rgbtBlue = average_blue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the Gx and Gy Array

    int Gx_arr[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_arr[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // make copy of image array
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }
    // for each element of the image array
    // for each row
    for (int a = 0; a < height; a++)
    {
        // for each column
        for (int b = 0; b < width; b++)
        {
            int row = 0;
            int column = 0;
            int gx_red = 0;
            int gx_green = 0;
            int gx_blue = 0;
            int gy_red = 0;
            int gy_green = 0;
            int gy_blue = 0;
            int out_red = 0;
            int out_green = 0;
            int out_blue = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    row = a + i;
                    column = b + j;

                    if (row < width && row >= 0 && column < width && column >= 0)
                    {
                        gx_red += image_copy[row][column].rgbtRed * Gx_arr[i + 1][j + 1];
                        gx_green += image_copy[row][column].rgbtGreen * Gx_arr[i + 1][j + 1];
                        gx_blue += image_copy[row][column].rgbtBlue * Gx_arr[i + 1][j + 1];

                        gy_red += image_copy[row][column].rgbtRed * Gy_arr[i + 1][j + 1];
                        gy_green += image_copy[row][column].rgbtGreen * Gy_arr[i + 1][j + 1];
                        gy_blue += image_copy[row][column].rgbtBlue * Gy_arr[i + 1][j + 1];
                    }
                }
            }

            out_red = round(sqrt(gx_red * (float) gx_red + gy_red * (float) gy_red));
            out_green = round(sqrt(gx_green * (float) gx_green + gy_green * (float) gy_green));
            out_blue = round(sqrt(gx_blue * (float) gx_blue + gy_blue * (float) gy_blue));

            if (out_red > 255)
            {
                out_red = 255;
            }
            if (out_green > 255)
            {
                out_green = 255;
            }
            if (out_blue > 255)
            {
                out_blue = 255;
            }

            image[a][b].rgbtRed = out_red;
            image[a][b].rgbtGreen = out_green;
            image[a][b].rgbtBlue = out_blue;
        }
    }
    return;
}
