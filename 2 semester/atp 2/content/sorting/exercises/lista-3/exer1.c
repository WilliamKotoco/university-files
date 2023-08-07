#include<stdio.h>
#include<string.h>

/*
Usar insertion sort para ordenar uma lista de nomes
*/
void sortAndPrint(char names[][40],int qtd);
void sortList(char names [][40], int qtd);


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
void sortList(char names [][40], int qtd)
{
    int i, j;
    char aux[40];
    for (i=1; i< qtd; i++)
    {
        j = i;
        strcpy(aux, names[i]);
        while (j!= 0 && strcmp(names[j], names[j-1]) < 0)
        {
            strcpy(names[j], names[j-1]);
            j--;
        }
        strcpy(names[j], aux);
    }
}