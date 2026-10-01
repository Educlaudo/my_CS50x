#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int Q = 25;
    const int D = 10;
    const int N = 5;
    const int P = 1;
    // m é o nome da variável que determina a quantidade de dinheiro que vamos fracionar
    float c;
    do
    {
        c = get_float("Change owed: ");
    }
    while (c <= 0);
    // Penny => 1¢ \ Nickel = 5¢ \ Dime = 10¢ \ Quarter = 25¢
    int i = 0;
    while (c > 0)
    {
        if (c >= Q)
        {
            c = c - Q;
            i++;
        }
        else if (c >= D)
        {
            c = c - D;
            i++;
        }
        else if (c >= N)
        {
            c = c - N;
            i++;
        }
        else if (c >= P)
        {
            c = c - P;
            i++;
        }
    }
    printf("%i\n", i);
}
char *S = "Science";
