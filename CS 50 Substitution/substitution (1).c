#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_key(string key);

int main(int argc, string argv[])
{
    // Checking whether the program was started with the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // The user has not entered the correct key. Error message.
    if (!check_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetical characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);
    string key = argv[1];
    char ciphertext[length + 1];

    for (int i = 0; i < length; i++)
    {
        if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index]);
        }
        else if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[length] = '\0';
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool check_key(string key)
{
    int length = strlen(key);

    if (length != 26)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }

    return true;
}
