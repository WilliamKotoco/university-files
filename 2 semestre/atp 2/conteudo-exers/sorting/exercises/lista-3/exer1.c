#include<stdio.h>
#include<string.h>

/*
Usar insertion sort para ordenar uma lista de nomes
*/
void sortAndPrint(char names[][],int qtd);

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
void sortAndPrint(char names[][40],int qtd)
{
    int i;
    sortList(names, qtd);
    for (i=0;i<qtd;i++)
    {
        printf("\n %s ", names[i]);
    }
}