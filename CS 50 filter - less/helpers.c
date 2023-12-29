#include "helpers.h"
#include <math.h>

// Convert image to grayscale

// Function to apply grayscale filter to entire image
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each pixel in the image
     for (int i = 0; i < height; i++)
     {
          for (int j = 0; j < width; j++)
          {
            // Convert pixels to float
            float Red = image [i][j].rgbtRed;
            float Green = image [i][j].rgbtGreen;
            float Blue = image [i][j].rgbtBlue;

            // Find the average value
            int average = round((Red + Green + Blue)/3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;

          }
     }

    return;
}

// Convert image to sepia
// Function to apply a sepia filter to the entire image
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     // Iterate through each pixel in the image
     for (int i = 0; i < height; i++)
     {
         for (int j = 0; j < width; j++)
         {
            // Convert pixels to float
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            // Find the updated pixel value
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            //Update the pixel value if sepiaRed, sepiaGreen or sepiaBlue exceeds 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

           image[i][j].rgbtRed = sepiaRed;
           image[i][j].rgbtGreen = sepiaGreen;
           image[i][j].rgbtBlue = sepiaBlue;
         }
     }



    return;
}

// Reflect image horizontally
// Function to invert the image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels from the left and right edges of the image
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
// A function that allows you to apply a blur effect to the entire image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a copy of the image
     RGBTRIPLE temp[height][width];

      // Copy the image to a temporary array
      for (int i = 0; i < height; i++)
      {
          for (int j = 0; j < width; j++)
          {
              temp[i][j] = image[i][j];
          }
      }

        // Iterate through every pixel in the image
         for (int i = 0; i < height; i++)
         {
             for (int j = 0; j < width; j++)
             {
                int totalRed, totalBlue, totalGreen;
                totalRed = totalBlue = totalGreen = 0;
                float counter = 0.00;

                //Get neighbouring pixels
                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y <2; y++)
                    {
                        int currentX = i + x;
                        int currentY = j + y;

                        //Check if neifhbouring pixel is valid
                         if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                         {
                            continue;
                         }

                         //Get image value
                         totalRed += image[currentX][currentY].rgbtRed;
                           totalGreen += image[currentX][currentY].rgbtGreen;
                             totalBlue += image[currentX][currentY].rgbtBlue;

//This could be a variable called "counter" used in the program code to keep track of the number of iterations in a loop, or to store numeric values that are incremented or decremented as the program runs.
                             counter++;


                    }


                    //Calculate average of neighbouring pixels
                    temp[i][j].rgbtRed = round(totalRed / counter);
                    temp[i][j].rgbtGreen = round(totalGreen / counter);
                    temp[i][j].rgbtBlue = round(totalBlue / counter);


                }


             }
         }

   //Copy new pixels into original image
   // Iterating through each pixel of the image
   for (int i = 0; i < height; i++)
   {
    for (int j = 0; j < width; j++)
    {
    image[i][j].rgbtRed = temp[i][j].rgbtRed;
    image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
    image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
    }
   }
    return;
}
