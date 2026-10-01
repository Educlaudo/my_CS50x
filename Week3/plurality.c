#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX];
int candcount;

bool vote(string name);
void printWinner(void);

int main(int argc, string argv[])
{
    // Checando se os argumentos são inválidos.
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidates...]\n");
        return 1;
    }
    candcount = argc - 1;
    if (candcount > MAX || candcount <= 1)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Identificar os candidatos na variável candidate.
    for (int i = 0; i < candcount; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Pedir o input dos votos.
    int numvote = get_int("Number of voters: ");
    for (int i = 0; i < numvote; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Diga o vencedor
    printWinner();
}

bool vote(string name)
{
    for (int i = 0; i < candcount; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void printWinner(void)
{
    int maxvotes = 0;
    for (int i = 0; i < candcount; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candcount; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
