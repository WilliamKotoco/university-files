// Faça um programa que receba o nome inteiro de uma pessoa (ex: "Michael Jackson
// da Silva Jr.") e que o formate na seguinte forma: "M. J. d. S. J.", isto é, apenas com
// as iniciais de cada nome/preposiçao. Grave essa formatação em uma nova string,
// imprimindo-a na tela
#include <string.h>
#include <stdio.h>
int main()
{
    int i = 0, k = 0;
    char nome[120], abreviacao[20];
    printf("Digite o nome completo: ");
    scanf(" %[^\n]s", &nome);
    while (nome[i] != '\0')
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (j == 0)
        {
            abreviacao[k] = nome[j];
            abreviacao[k + 1] = '.';
            k += 2;
        }
        else if (nome[j] == ' ')
        {
            abreviacao[k] = nome[j + 1];
            abreviacao[k + 1] = '.';
            k += 2;
        }
    }
    printf("A abreviacao é %s", abreviacao);
    return 0;
}