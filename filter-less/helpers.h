#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

// Helper function for blur
// void scan_average(int height, int width, int pos_row, int pos_column, RGBTRIPLE *image, RGBTRIPLE *image_copy);