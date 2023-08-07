// ac¸a um programa que leia um nome e imprima as 4 primeiras letras do nome.
#include <stdio.h>
int main()
{
    int i;
    char nome[40];
    scanf("%s", nome);
    for (i = 0; i < 4; i++)
        printf("%c ", nome[i]);
    return 0;
}