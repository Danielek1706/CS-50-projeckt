// Modifies the volume of an audio file

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
    uint8_t headerbuffer[44];
    //A uint8_t is a data type that represents an 8-bit unsigned number

    fread( headerbuffer, sizeof(uint8_t), 44, input); // fread is used to read data blocks from a file

    fwrite (headerbuffer, sizeof(uint8_t), 44, output); // fwrite is used to write data blocks to a file

    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer;

    while(fread(&buffer, sizeof(int16_t),1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
