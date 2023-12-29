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
                     { int currentX = i + x;
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


    return;
}

// Detect edges
// Function to apply edge detection effect to the entire image
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];

     // Copy the image to a temporary array
     for (int i = 0; i < height; i++)
     {
         for (int j = 0; j < width; j++)
         {
            temp[i][j] = image[i][j];
         }
     }

     int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
     int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};


     // Iterate through every pixel in the image
        for (int i = 0; i < height; i++)
        {
             for (int j = 0; j < width; j++)
             {
                int redX =0;
                int greenX =0;
                int blueX = 0;
                int redY = 0;
                int greenY = 0;
                int blueY = 0;

                // Loop through each pixel for neighbouring pixels
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        // Check for valid pixels
                        if (i - 1 + x <0 || i - 1 + x > height - 1 || j - 1 + y < 0 || j - 1 + y > width - 1)
                        {
                            continue;
                        }
                        // Calculate Gx for each colour
                        redX = redX + (image[i - 1 + x][j - 1 + y]. rgbtRed * Gx[x][y]);
                        greenX = greenX + (image[i - 1 + x][j - 1 + y]. rgbtGreen * Gx[x][y]);
                        blueX = blueX + (image[i - 1 + x][j - 1 + y]. rgbtBlue * Gx[x][y]);

                        // Calculate Gy for each colour
                        redY = redY + (image[i - 1 + x][j - 1 + y]. rgbtRed * Gy[x][y]);
                        greenY = greenY + (image[i - 1 + x][j - 1 + y]. rgbtGreen * Gy[x][y]);
                        blueY = blueY + (image[i - 1 + x][j - 1 + y]. rgbtBlue * Gy[x][y]);

                    }
                }

                // Calculater square root of Gx2 and Gy2

                int red = round(sqrt((redX * redX) + (redY * redY)));
                int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
                int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));


// Cap valvue at 255 if exceeds
if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

                   // Copy values into temp image
                    temp[i][j].rgbtRed = red;
                    temp[i][j].rgbtGreen = green;
                    temp[i][j].rgbtBlue = blue;


             }
        }

   // Copy new pixels into original image

    for (int i = 0; i < height; i++)
    {
         for (int j = 0; j < width; j++)
         {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen= temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
         }
    }

    return;
}
