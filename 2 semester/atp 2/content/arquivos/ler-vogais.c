#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int qtd_vogais = 0;
    char ch;
    FILE *fp;

    fp = fopen("arquivo.txt", "r");
    if (fp == NULL)
    {
        printf("\n Arquivo nao existe");
        exit(1);
    }

    do
    {
        ch = fgetc(fp);
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            qtd_vogais++;
            ch++;
        }
    } while (ch != EOF);
    fclose(fp);
    printf("\n tem %d vogais", qtd_vogais);

    return 0;
}