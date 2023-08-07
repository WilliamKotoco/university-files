/*
Receber N nomes e ordenar por tamanho usando selection sort
*/
#include <stdio.h>
#include <string.h>
void sortAndPrint(char names[][40], int qtd);
void selectionSort(char names[][40], int qtd);

int main()
{
    int qtd;
    scanf("%d", &qtd);
    char names[qtd][40];
    for (int i = 0; i < qtd; i++)
    {
        scanf("%s", names[i]);
    }

    sortAndPrint(names, qtd);

    return 0;
}
void sortAndPrint(char names[][40], int qtd)
{
    int i;
    selectionSort(names, qtd);
    for (i = 0; i < qtd; i++)
    {
        printf("%s ", names[i]);
    }
}
void selectionSort(char names[][40], int qtd)
{
    int i, j, least;
    char aux[40];
    for (i = 0; i < qtd; i++)
    {
        least = i;
        for (j = i + 1; j < qtd; j++)
        {
            if (strlen(names[j]) < strlen(names[least]))
            {
                least = j;
            }
        }
        if (least != i)
        {
            strcpy(aux, names[i]);
            strcpy(names[i], names[least]);
            strcpy(names[least], aux);
        }
    }
}
