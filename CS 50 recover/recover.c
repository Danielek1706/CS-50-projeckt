#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])

{

//The data type which is represented by 8 bits
typedef uint8_t BYTE;
BYTE buffer[512];
int bytes_read, count = 0;
char filename[8];


// open memory card
 FILE *f = fopen(argv[1], "r");
 FILE *img = NULL;


while(&free)
 {
// fread: Used to read blocks of data from a file(data, size, number, inptr)
  bytes_read = fread(buffer, sizeof(BYTE), 512, f);
   if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
   {
   if (count == 0)
   {
    //Making a New JPEG
    sprintf(filename, "%03i.jpg", count);
    img = fopen(filename, "w");

    //Writing files
    //fwrite: is used to write blocks of data to a file (data, size, number, outptr)
    fwrite(buffer, sizeof(BYTE), bytes_read, img);
    count++;
   }
   else
   {
      fclose(img);
      sprintf(filename, "%03i.jpg", count);
      img = fopen(filename, "w");
      fwrite(buffer, sizeof(BYTE), bytes_read, img);
      count++;
   }
   }

  else if(count !=0)
  {
    fwrite(buffer, sizeof(BYTE), bytes_read, img);
    if(bytes_read == 0)
    {
        fclose(img);
        fclose(f);
        return 0;

    }
  }

 }
 fclose(img);
  fclose(f);

}
