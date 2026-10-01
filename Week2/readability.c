#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double letters(string text);
le words(string text);
double sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    double W = words(text);
    double L = letters(text) / W * 100;
    double S = sentences(text) / W * 100;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

double letters(string text)
{
    double nL = 0;
    int tamanho = strlen(text);
    for (int i = 0; i < tamanho; i++)
    {
        if (isalpha((unsigned char) text[i]))
        {
            nL++;
        }
    }
    return nL;
}

double words(string text)
{
    double nW = 1;
    int tamanho = strlen(text);
    for (int i = 0; i < tamanho; i++)
    {
        if (isspace((unsigned char)text[i]))
        {
            nW++;
        }
    }
    return nW;
}

double sentences(string text)
{
    double nS = 0;
    int tamanho = strlen(text);
    for (int i = 0; i < tamanho; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            nS++;
        }
    }
    return nS;
}
// There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.
