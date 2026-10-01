// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 65537;

// Hash table
node *table[N];

// Vamos contar o número de palavras!!
int eachWord = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int tamanho = strlen(word);
    char loweredWord[LENGTH + 1];
    // convert all words to lowercase
    for (int i = 0; i < tamanho; i++)
    {
        loweredWord[i] = tolower(word[i]);
    }
    loweredWord[tamanho] = '\0';

    unsigned int index = hash(loweredWord);
    // compare words of the text with words of the dictionary
    for (node *arrow = table[index]; arrow != NULL; arrow = arrow->next)
    {
        if (strcmp(arrow->word, loweredWord) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int stdHash = 5381;
    char cHash;
    int tamanho = strlen(word);
    for (int i = 0; i < tamanho; i++)
    {
        cHash = word[i];
        cHash = tolower(cHash);
        // djb2 hash function:
        stdHash = ((stdHash << 5) + stdHash) + cHash;
    }
    return (stdHash % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *arquivo = fopen(dictionary, "r");
    if (arquivo == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(arquivo, "%s", word) != EOF)
    {
        // Primeiro vou converter todas as letras da palavra para minusculas
        int tamanho = strlen(word);
        for (int i = 0; i < tamanho; i++)
        {
            word[i] = tolower(word[i]);
        }
        // criar uma nova node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(arquivo);
            for (int i = 0; i < N; i++)
            {
                node *arrow = table[i];
                while (arrow)
                {
                    node *tmp = arrow;
                    arrow = arrow->next;
                    free(tmp);
                }
                table[i] = NULL;
                eachWord = 0;
            }
            return false;
        }

        strcpy(n->word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;
        eachWord++;
    }
    fclose(arquivo);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return eachWord;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *arrow = table[i];
        while (arrow != NULL)
        {
            node *tmp = arrow;
            arrow = arrow->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
