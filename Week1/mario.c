#include <cs50.h>
#include <stdio.h>
// jump vai ser a variável que adicionará espaços, e hash adicionará #.
void jump(int j);
void hash(int b);

int main(void)
{
    // preciso fazer com que caso a variável (h < 1 || h > 8) então, a deve se repetir "Height: "
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    int j = h - 1;
    int b = h - j;
    // Como esse é o "mario2" no caso o desafio mais difícil do exercício do mario, eu tenho printar
    // duas pirâmides espelhadas, separadas por dois espaços.
    do
    {
        jump(j);
        hash(b);
        // percebi que era só adicionar "printf("  ")" para os dois espaços e pedir para printar o
        // mesmo número de # da pirâmide anterior.
        printf("  ");
        hash(b);
        // E voilà! Com apenas mais duas linhas de código (25 e 26), eu resolvo a versão difícil do problema do mario.c.
        j--;
        b++;
        printf("\n");
    }
    while (j >= 0);
}

// Para ficar mais bonito e mais legível e usar menos linhas de códigos, decidi definir duas
// funções: A função "jump" serve para printar determinado número de espaços, para a pirâmide ficar invertida.
void jump(int j)
{
    for (int i = 0; i < j; i++)
    {
        printf(" ");
    }
}
// A função "hash" serva para printar determinado número de '#'s, os nossos bloquinhos.
void hash(int b)
{
    for (int i = 0; i < b; i++)
    {
        printf("#");
    }
}
