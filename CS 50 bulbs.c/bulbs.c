#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO

    string message = get_string("Message: ");

   for( int i = 0, n = strlen(message); i < n; i++) // Strlen oblicza dlugosc łancucha.

  {
    int binary[] = {0, 0, 0, 0, 0, 0, 0, 0,};


  int decimal = message [i];  // decimal to stopień dokładności jest okreslany przez liczbe
                              // cyfr z prawej strony separatora dziesiętnego.


// Konwertowanie ACII na format binarny

int j = 0;


while (decimal > 0 )
{
  binary [j] = decimal % 2;
  decimal  = decimal / 2;
  j++;

}

for (int k = BITS_IN_BYTE - 1; k>=0; k--)

{

print_bulb(binary[k]);

}

printf("\n");

  }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
