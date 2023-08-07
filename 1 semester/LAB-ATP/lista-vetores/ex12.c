// Crie um programa que leia uma string chamada string[31] e um caracter c. Imprima na tela a
// quantidade de vezes em que o caracter digitado em c aparece na string string[31]. (ex: o usuário
//  digitou na string "pessoal, tudo bem?" e digitou c = 'e', então o programa deverá retornar
//  a quantidade de vezes em que a letra 'e' foi digitada. Neste exemplo, a letra 'e' foi digitada duas vezes).
#include <string.h>
#include <stdio.h>
int main()
{
    int i, contador = 0;
    char string[31], c;
    printf("Digite a palavra: ");
    scanf(" %s", &string);
    fflush(stdout);
    printf("\n Digite a letra: ");
    scanf(" %c", &c);
    fflush(stdout);

    while (string[i] != '\0')
    {
        if (string[i] == c)
        {
            contador++;
        }
        i++;
    }
    printf("\n A letra %c apareceu %d vezes", c, contador);
    return 0;
}
