#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int qtd_vogais;
    char ch;
    FILE *fp;

    fp = fopen("arquivo.txt", "w");
    if (fp == NULL)
    {
        printf("\n Arquivo nao existe");
    }
    do
    {
    ch = getc(fp);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        qtd_vogais++;
    }
    }while(ch != EOF);
    fclose(fp);
    printf("\n tem %d vogais", qtd_vogais);
    return 0;
    
}