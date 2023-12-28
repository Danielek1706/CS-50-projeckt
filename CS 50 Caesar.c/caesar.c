#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // definiuje funkcje, które są używane w klasyfikacji znaków. Funkcje, które są zdefiniowane w <ctype.h>
#include <stdlib.h> //biblioteka cstdlib zawiera funkcje ogólne takie jak konwersje, alokacja pamięci czy funkcje matematyczne.

int main(int argc, string argv[])
{

//Sprawdz, czy podano poprawną liczbę argumentów.
if (argc !=2)

   {

    printf("Usage: ./caesar key\n");
    return 1;
}
for  (int i = 0; i < strlen (argv[1]); i++) // Strlen - długość łańcucha.  argv jest wskaźnikiem do tablicy zawierającej argumenty, każdy jako osobny tekst.

{

    if(!isdigit(argv[1][i]))
    {

         printf("Usage: ./caesar key\n");
        return 1;
    }
}
    // Przekształć argument klucza na liczbę całkowitą
    int k = atoi(argv[1]);  // k to key.


    string plaintext = get_string("Plaintext: "); // Zwykły tekst.
    printf("Ciphertext: "); // Tekst szyfrujący.

    // Przejdź przez każdy znak w tekście
    for (int j = 0; j < strlen(plaintext);  j++)
{
// Zaszyfruj literę, zachowując wielkość

    if (isupper(plaintext[j])) // Funkcja isupper zwraca wartość różną od zera gdy argument, który został przekazany do funkcji jest dużą literą alfabetu.
{
    printf("%c", (plaintext[j] - 65 + k) % 26 + 65); // %c to specyfikator formatu używany do odczytywania lub zapisywania pojedynczego znaku.
}
 else if (islower(plaintext[j]))

 {
printf("%c", (plaintext[j] - 97 + k) % 26 + 97);

 }
else
{
    // // Jeśli to nie litera, po prostu wydrukuj bez zmian.
    printf("%c", plaintext[j]);
}

}

 // Przejdź do nowej linii
    printf("\n");


}






