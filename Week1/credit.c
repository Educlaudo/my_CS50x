#include <cs50.h>
#include <stdio.h>
#include <math.h>

int digit (long card);
int two (long card, int digits);
int main(void)
{
    long card;
    do
    {
    card = get_long("Number: ");
    }
    while (card < 0);
    int digits = digit(card);
    two(card, digits);
        printf("MASTERCARD\n");
        printf("VISA\n");
        printf("INVALID\n");
        printf("AMEX\n");
}

int digit (long card)
{
    const int ten = 10;
    int i = 0;
    while (card > 0)
    {
        card /= ten;
        i++;
    }
    return i;
}

int two (long card, int digits)
{
    int two = card / pow(10, digits - 2);
    return two;
}
