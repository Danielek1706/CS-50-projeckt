#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

// Sprawdzenie, czy program został uruchomiony z właściwą liczbą argumentów
    if (argc != 2)

    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
string key = argv[1];
for ( int i = 0; i < strlen(key); i++)

  {
    if (!isalpha(key[i])) //isalpha jest często używana do sprawdzania, czy dana wartość reprezentuje literę alfabetu
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
  }

//// Sprawdzenie, czy klucz ma odpowiednią długość

if (strlen(key) !=26)

     {
        printf("Key must contain 26 characters.\n"); //("Klucz musi mieć 26 znaków.\n")
        return 1;
     }


for (int i = 0; i < strlen(key); i++)
{
     for (int j = i + 1; j < strlen(key); j++)
     {
        if (toupper(key[i]) == toupper(key[j])) //Funkcja toupper w języku C jest używana do konwersji małych liter na duże litery.
        {
               printf("Usage: ./substitution key\n");
               return 1;

        }
     }
}

//Zapytaj użytkownika o zwykły tekst

string plaintext = get_string("plaintext: ");

//Konwersja wszystkich liter w kluczu na wielkie litery
for (int i = 0; i < strlen(key); i++)
 {
    if(islower(key[i])) // funkcja islower jest używana do sprawdzania, czy podany znak jest małą literą
    {
        key[i] = key[i] - 32;
    }

 }

//Drukuj szyfrogram
printf("cipheretext: ");

for (int i = 0; i < strlen(plaintext); i++)

     {
        if (isupper(plaintext[i]))
        {
          int letter = plaintext[i] - 65;
          printf("%c", key[letter]);

        }
        else if (islower(plaintext[i]))
        {
              int letter = plaintext[i] - 97;
              printf("%c", key[letter] + 32);

        }
        else printf("%c", plaintext[i]);
     }

   printf("\n");
}
