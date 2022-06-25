/* Escreva um programa que leia uma string chamada string[8], e escreva na tela essa
 string invertida (ex: se foi digitado 'olá' --> impressão na tela será: álo).*/
#include <string.h>
#include <stdio.h>
int main()
{
    char string[8];
    printf("Digite a string: ");
    scanf("%s", &string);
    int j = strlen(string);

    for (int i = 0; i < j; i++) // j/2 porque vai passar até a metade da string se
    {
        string[i] = string[j - i - 1]; // pega o caractere da ponta oposta
        // tem que colocar o -1 porque o strlen não calcula o indicador
    }
    printf("String invertida: %s", string);

    return 0;
}
