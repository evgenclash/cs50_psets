#include "helpers.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height ; i++ )
    {
        for ( int k = 0; k < width; k++)
        {
            int average = (image[i][k].rgbtRed + image[i][k].rgbtBlue + image[i][k].rgbtGreen )/3;
            image[i][k].rgbtRed = average;
            image[i][k].rgbtGreen = average;
            image[i][k].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height ; i++ )
    {
        for ( int k = 0; k < width; k++)
        {
            int sepiared = image[i][k].rgbtRed * 0.393 + image[i][k].rgbtGreen * 0.769 + image[i][k].rgbtBlue *0.189 ;
            if (sepiared > 255)
            {
                sepiared = 255;
            }

            int sepiagreen = image[i][k].rgbtRed * 0.349 + image[i][k].rgbtGreen * 0.686 + image[i][k].rgbtBlue *0.168 ;
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            int sepiablue = image[i][k].rgbtRed * 0.272 + image[i][k].rgbtGreen * 0.534 + image[i][k].rgbtBlue *0.131 ;
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }
            image[i][k].rgbtRed = sepiared;
            image[i][k].rgbtGreen = sepiagreen;
            image[i][k].rgbtBlue = sepiablue;
        }
    }

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   //use of a temporary array to swap values
    int temp[3];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            temp[0] = image[j][i].rgbtBlue;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtRed;

            // swap pixels with the ones on the opposite side of the picture and viceversa
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtBlue = temp[0];
            image[j][width - i - 1].rgbtGreen = temp[1];
            image[j][width - i - 1].rgbtRed = temp[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int blurred, blurblue, blurgreen;
    for (int i = 0; i < height ; i++ )
    {
        for ( int k = 0; k < width; k++)
        {
            if (i > 1 && i < height - 1) 
            {   
               
                if ( k > 1 && k < width-1)
                {
                    
                    blurred = (image[i][k-1].rgbtRed + image[i][k].rgbtRed + image[i][k+1].rgbtRed + image[i-1][k-1].rgbtRed +image[i-1][k].rgbtRed + image[i-1][k+1].rgbtRed + image[i+1][k-1].rgbtRed +image[i+1][k].rgbtRed + image[i+1][k+1].rgbtRed ) / 9;
                    blurgreen = (image[i][k-1].rgbtGreen +image[i][k].rgbtGreen + image[i][k+1].rgbtGreen + image[i-1][k-1].rgbtGreen +image[i-1][k].rgbtGreen + image[i-1][k+1].rgbtGreen + image[i+1][k-1].rgbtGreen +image[i+1][k].rgbtGreen + image[i+1][k+1].rgbtGreen ) / 9;
                    blurblue = (image[i][k-1].rgbtBlue +image[i][k].rgbtBlue + image[i][k+1].rgbtBlue + image[i-1][k-1].rgbtBlue +image[i-1][k].rgbtBlue + image[i-1][k+1].rgbtBlue + image[i+1][k-1].rgbtBlue +image[i+1][k].rgbtBlue + image[i+1][k+1].rgbtBlue ) / 9;
               }
              
                if (k == width)
                {
                    blurred = (image[i][k-1].rgbtRed +image[i][k].rgbtRed + image[i-1][k-1].rgbtRed +image[i-1][k].rgbtRed + image[i+1][k-1].rgbtRed +image[i+1][k].rgbtRed) / 6;
                    blurgreen = (image[i][k-1].rgbtGreen +image[i][k].rgbtGreen + image[i-1][k-1].rgbtGreen +image[i-1][k].rgbtGreen + image[i+1][k-1].rgbtGreen +image[i+1][k].rgbtGreen ) / 6;
                    blurblue = (image[i][k-1].rgbtBlue +image[i][k].rgbtBlue + image[i-1][k-1].rgbtBlue +image[i-1][k].rgbtBlue + image[i+1][k-1].rgbtBlue +image[i+1][k].rgbtBlue ) / 6;
                }
                if (k == 0)
                {
                    blurred = (image[i][k].rgbtRed + image[i][k+1].rgbtRed + image[i-1][k].rgbtRed + image[i-1][k+1].rgbtRed + +image[i+1][k].rgbtRed + image[i+1][k+1].rgbtRed ) / 6;
                    blurgreen = (image[i][k].rgbtGreen + image[i][k+1].rgbtGreen + image[i-1][k].rgbtGreen + image[i-1][k+1].rgbtGreen + image[i+1][k].rgbtGreen + image[i+1][k+1].rgbtGreen ) / 6;
                    blurblue = (image[i][k].rgbtBlue + image[i][k+1].rgbtBlue + image[i-1][k].rgbtBlue + image[i-1][k+1].rgbtBlue + image[i+1][k].rgbtBlue + image[i+1][k+1].rgbtBlue ) / 6;
                }

          }
            else if(i == height )
            {
                if ( k > 0 && k < width)
                {
                    blurred = (image[i][k-1].rgbtRed +image[i][k].rgbtRed + image[i][k+1].rgbtRed + image[i-1][k-1].rgbtRed +image[i-1][k].rgbtRed + image[i-1][k+1].rgbtRed ) / 6;
                    blurgreen = (image[i][k-1].rgbtGreen +image[i][k].rgbtGreen + image[i][k+1].rgbtGreen + image[i-1][k-1].rgbtGreen +image[i-1][k].rgbtGreen + image[i-1][k+1].rgbtGreen ) / 6;
                    blurblue = (image[i][k-1].rgbtBlue +image[i][k].rgbtBlue + image[i][k+1].rgbtBlue + image[i-1][k-1].rgbtBlue +image[i-1][k].rgbtBlue + image[i-1][k+1].rgbtBlue ) / 6;
                }
                else if ( k == width)
                {
                    blurred = (image[i][k-1].rgbtRed +image[i][k].rgbtRed + image[i-1][k-1].rgbtRed +image[i-1][k].rgbtRed ) / 4;
                    blurgreen = (image[i][k-1].rgbtGreen +image[i][k].rgbtGreen + image[i-1][k-1].rgbtGreen +image[i-1][k].rgbtGreen ) / 4;
                    blurblue = (image[i][k-1].rgbtBlue +image[i][k].rgbtBlue + image[i-1][k-1].rgbtBlue +image[i-1][k].rgbtBlue ) / 4;
                }
                else if (k == 0)
                {
                    blurred = (image[i][k].rgbtRed + image[i][k+1].rgbtRed +image[i-1][k].rgbtRed + image[i-1][k+1].rgbtRed ) / 4;
                    blurgreen = (image[i][k].rgbtGreen + image[i][k+1].rgbtGreen + image[i-1][k].rgbtGreen + image[i-1][k+1].rgbtGreen ) / 4;
                    blurblue = (image[i][k].rgbtBlue + image[i][k+1].rgbtBlue + image[i-1][k].rgbtBlue + image[i-1][k+1].rgbtBlue ) / 4;
                }
            }
            else if (i == 0)
            {
                if ( k > 0 && k < width)
                {
                    blurred = (image[i][k-1].rgbtRed +image[i][k].rgbtRed + image[i][k+1].rgbtRed + image[i+1][k-1].rgbtRed +image[i+1][k].rgbtRed + image[i+1][k+1].rgbtRed ) / 6;
                    blurgreen = (image[i][k-1].rgbtGreen +image[i][k].rgbtGreen + image[i][k+1].rgbtGreen + image[i+1][k-1].rgbtGreen +image[i+1][k].rgbtGreen + image[i+1][k+1].rgbtGreen ) / 6;
                    blurblue = (image[i][k-1].rgbtBlue +image[i][k].rgbtBlue + image[i][k+1].rgbtBlue + image[i+1][k-1].rgbtBlue +image[i+1][k].rgbtBlue + image[i+1][k+1].rgbtBlue ) / 6;
                }
                else if (k == width)
                {
                    blurred = (image[i][k-1].rgbtRed +image[i][k].rgbtRed  + image[i+1][k-1].rgbtRed +image[i+1][k].rgbtRed ) / 4;
                    blurgreen = (image[i][k-1].rgbtGreen +image[i][k].rgbtGreen + image[i+1][k-1].rgbtGreen +image[i+1][k].rgbtGreen  ) / 4;
                    blurblue = (image[i][k-1].rgbtBlue +image[i][k].rgbtBlue + image[i+1][k-1].rgbtBlue +image[i+1][k].rgbtBlue ) / 4;
                }
                else if (k == 0)
                {
                    blurred = (image[i][k].rgbtRed + image[i][k+1].rgbtRed + image[i+1][k].rgbtRed + image[i+1][k+1].rgbtRed ) / 4;
                    blurgreen = (image[i][k].rgbtGreen + image[i][k+1].rgbtGreen + image[i+1][k].rgbtGreen + image[i+1][k+1].rgbtGreen ) / 4;
                    blurblue = (image[i][k].rgbtBlue + image[i][k+1].rgbtBlue + image[i+1][k].rgbtBlue + image[i+1][k+1].rgbtBlue ) / 4;
                }
            }




            temp[i][k].rgbtRed = blurred;
            temp[i][k].rgbtGreen = blurgreen;
            temp[i][k].rgbtBlue = blurblue;
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}
