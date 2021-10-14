#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int num = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3;
            num = (int)(num + 0.5);
            image[i][j].rgbtRed = num;
            image[i][j].rgbtBlue = num;
            image[i][j].rgbtGreen = num;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (width % 2 == 1 && j == (width - 1) / 2)
            {
                BYTE* nums = &image[i][j].rgbtRed;
                BYTE* nums1 = &image[i][j].rgbtBlue;
                BYTE* nums2 = &image[i][j].rgbtGreen;
                BYTE swaps = *nums;
                BYTE swaps1 = *nums1;
                BYTE swaps2 = *nums2;
                *nums = swaps;
                *nums1 = swaps1;
                *nums2 = swaps2;
            }
            else
            {
                BYTE* num = &image[i][j].rgbtRed;
                BYTE* num1 = &image[i][j].rgbtBlue;
                BYTE* num2 = &image[i][j].rgbtGreen;
                BYTE* num3 = &image[i][width - j - 1].rgbtRed;
                BYTE* num4 = &image[i][width - j - 1].rgbtBlue;
                BYTE* num5 = &image[i][width - j - 1].rgbtGreen;
                BYTE swap = *num;
                BYTE swap1 = *num1;
                BYTE swap2 = *num2;
                *num = *num3;
                *num1 = *num4;
                *num2 = *num5;
                *num3 = swap;
                *num4 = swap1;
                *num5 = swap2;
            }
        }
    } 
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
