#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1

// Checking the number of arguments
   if (argc != 3)
   {
    printf("Usage: reverse input.wav output.wav\n");
    return 1;
   }


    // Open input file for reading
    // TODO #2

// Open the input file
    char *infile = argv [1];
    FILE *input = fopen(infile, "rb");

    if (input == NULL)
    {
        printf ("Error not open %s.\n", infile);
        return 1;
    }

    // Read header
    // TODO #3

// Reading the header of a WAV file
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(header) == 0)
    {
        printf("Not a Wave File\n");
        return 1;
    }

     // Add audioFormat check
     if (header.audioFormat != 1)
     {

     printf("Not a Wave File\n");
     return 1;
     }


    // Open output file for writing
    // TODO #5

    char *outfile = argv [2];
    FILE *output = fopen(outfile, "wb");

    if (output == NULL)
    {
        printf ("Error not open %s.\n", outfile);
        return 1;
    }


    // Write header to file
    // TODO #6

    // Writing the header to the output file
     fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7

    // Calculate the block size
    int size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    if(fseek(input, size , SEEK_END))//fseek: sets the file pointer to a given offset.
    {
        return 1;
    }
    BYTE buffer[size];
    while(ftell(input) - size > sizeof(header)) //ftell: returns the current file pointer position.
    {   if(fseek(input,  - 2 * size, SEEK_CUR)) //Move to position
    {
        return 1;
    }
        fread(buffer, size, 1, input); //fread: reads from a file into a buffer.
        fwrite(buffer, size, 1, output); //fwrite: writes from the buffer to the file.
    }

   //// Closing the files
    fclose(output);
    fclose(input);

    printf("Operation successfully completed. The content of the file has been inverted.\n");

    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if(header.format[0] == 'W' && header.format [1] == 'A' && header.format [2] == 'V' && header.format [3] == 'E' )
   {
    return 1;
   }
   return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;

}
