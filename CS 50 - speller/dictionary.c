// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
//// Hash function
unsigned int hash_value;
unsigned int word_count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash (word);
    node *cursor = table[hash_value];

    while (cursor !=0)
    {
        if (strcasecmp(word, cursor->word) == 0) //The strcasecmp function in C is used to compare two strings of characters (strings) on a case-insensitive basis. This means that the function treats uppercase and lowercase letters as identical when comparing.
        {
            return true;
        }
        cursor  = cursor->next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
     unsigned long total = 0; //The unsigned long is used to represent unsigned integers with a larger range than the unsigned int.
     for(int i = 0; i < strlen(word); i++)
     {
        total +=  tolower(word[i]); //The tolower is used to convert a capital letter into a lowercase letter.
     }
     return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

     // Open dictionary file
     FILE *file = fopen(dictionary, "r");
     if (file == NULL)
     {
        printf("unable to open %s\n", dictionary);
        return false;
     }

 // Buffer to store each word
     char word[LENGTH + 1];


  // Read each word from the dictionary and insert into hash table
    while (fscanf(file, "%s", word) != EOF)

    {
// Allocate memory for node
     node *n = malloc(sizeof(node));


    if (n == NULL)
    {
        return false;
    }
// Copy the word into the node
    strcpy(n->word, word);
    hash_value = hash(word);
    n->next = table[hash_value];
    table[hash_value] = n;
    word_count++;
}

 // Close dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
