#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define BLOCK_SIZE 512 //define is used to create macros, i.e. symbolic names for values, code fragments or expressions.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }

    typedef uint8_t BYTE; // representing an 8-bit unsigned integer
    BYTE buffer[BLOCK_SIZE];

    // Now we have a valid file to read.
    size_t bytes_read;
    bool first_jpeg = false;
    FILE *current_file;
    char current_filename[100];
    int current_filenumber = 0;
    bool found_jpeg = false;

    while (true)
    {
        bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file); // fread in C is used to read a block of data from a file. It is often used to load binary data, i.e. data that is not divided into lines of text, such as images, sounds, structures
        if (feof(file))
        {
            break; // Breaking the loop
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpeg = true;

            if (!first_jpeg)
            {
                first_jpeg = true;
            }
            else
            {
                if (current_file != NULL)
                {
                    fclose(current_file);
                }
            }

            sprintf(current_filename, "%03i.jpg", current_filenumber);
            current_file = fopen(current_filename, "wb");
            fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            current_filenumber++;
        }
        else
        {
            if (found_jpeg)
            {
                if (current_file != NULL)
                {
                    fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
                }
            }
        }
    }

    fclose(file);
    if (current_file != NULL)
    {
        fclose(current_file);
    }

    return 0;
}
