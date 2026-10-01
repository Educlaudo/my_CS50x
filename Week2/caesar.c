#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string errorMessage = "Usage: ./caesar key\n";
    if (argc != 2)
    {
        printf("%s", errorMessage);
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("%s", errorMessage);
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");
    int textLength = strlen(text);
    printf("Ciphertext: ");
    for (int i = 0; i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                printf("%c", ((text[i] - 65 + key) % 26) + 65);
            }
            else if (!isupper(text[i]))
            {
                printf("%c", ((text[i] - 97 + key) % 26) + 97);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
