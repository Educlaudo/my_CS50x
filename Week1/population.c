#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    int i = 0;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    int n = start;
    while (n < end)
    {
        n = n + (n / 3) - (n / 4);
        i++;
    }
    printf("Years: %i\n", i);
}
