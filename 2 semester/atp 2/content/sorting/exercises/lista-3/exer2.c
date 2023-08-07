#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Ordenar letras dentro de uma string:
1- separar as letras da string
2- ordenar usando bubble sort
*/
void bubbleSort(char *letters, int qtd);
int main()
{
    int i = 0;
    char string[40];
    char *letters;
    scanf("%s", string);
    letters = malloc(strlen(string) * sizeof(char));
    while (string[i] != '\0')
    {
        letters[i] = string[i];
        i++;
    }
    bubbleSort(letters, strlen(string));

    for (int i = 0; i < strlen(string); i++)
    {
        printf("%c ", letters[i]);
    }

    return 0;
}
void bubbleSort(char *letters, int qtd)
{
    int i, j, aux, exchange = 1;
    j = qtd;
    while(exchange)
    {
        aux = letters[0];
        exchange = 0;
        for (i = 1; i < j; i++)
        {
            if (letters[i] < aux)
            {
                letters[i-1] = letters[i];
                exchange = 1;
            }
            else
            {
                letters[i-1] = aux;
                aux = letters[i];
            }
        }
        letters[i-1] = aux;
        j--;
    }

}
