#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    // Aqui embaixo, printamos o valor de "n".
    printf("%i\n", n);

    // Dessa vez, printamos o endereço de "n", usando o operador (&).
    printf("%p\n", &n);

    // Agora, vamos printar o valor que está armazenado aonde o ponteiro (*) "p",
    // está apontando, no caso, o endereço de "n" (&n), que armazena o valor 50.
    printf("%i\n", *p);

    // Neste caso, estamos printando o próprio ponteiro (*) "p", que armazena o
    // endereço de "n", pois está apontando para ele.
    printf("%p\n", p);

    // Nesta situação, printaremos o endereço do ponteiro (*) "p", que é novo.
    printf("%p\n", &p);
}
