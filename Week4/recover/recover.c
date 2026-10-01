#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int BLOCK_SIZE = 512;

    // Verificar se o argumentos são válidos
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Abrir o cartão de memória
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Criar o buffer e outras variáveis necessárias
    uint8_t buffer[BLOCK_SIZE];
    int i = 0;
    FILE *img = NULL;
    char card[8];

    // Enquanto houver blocos para ler
    while (fread(buffer, 1, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        // Checar os 4 primeiros bytes do arquivo
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(card, "%03i.jpg", i);
            img = fopen(card, "w");
            if (img == NULL)
            {
                printf("Could not create image file.\n");
                fclose(f);
                return 3;
            }
            i++;

        }
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    //fechar os arquivos abertos
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(f);
    return 0;
}
