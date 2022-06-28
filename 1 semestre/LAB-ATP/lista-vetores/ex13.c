// Construa um programa que leia o nome e o sobrenome de uma pessoa separadamente
// (em duas strings distintas). O programa então deverá concatenar (juntar) essas duas
// strings em uma terceira string. No final, impriminar na tela:
// (a) o conteúdo dessa nova string (isto é, o nome inteiro da pessoa).
// (b) a primeira letra do primeiro nome dessa pessoa.
// (c) o número de letras do nome completo dessa pesso
#include <stdio.h>
#include <string.h>
int main()
{
    char nome[40], sobrenome[40], concatenar[82];
    int i = 0, j = 0, final;
    printf("Digite o nome: ");
    scanf("%s", &nome);
    printf("\n Digite o sobrenome: ");
    scanf(" %s", &sobrenome);
    while (1)
    {

        concatenar[i] = nome[i];
        i++;
        if (nome[i] == '\0')
        {
            final = i;
            break;
        }
    }

    while (sobrenome[j] != '\0')
    {
        if (j == 0)
        {
            concatenar[final] = ' ';
            j++;
            final++;
        }
        concatenar[final] = sobrenome[j - 1];
        final++;
        j++;
    }

    printf("\n a) %s ", concatenar);
    printf("\n b) %c", concatenar[0]);
    printf("\n c) %d", strlen(concatenar));
    return 0;
}