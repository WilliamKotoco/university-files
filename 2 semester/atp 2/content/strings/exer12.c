// Fac¸a um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u) possui
// essa palavra. Entre com um caractere (vogal ou consoante) e substitua todas as vogais
// da palavra dada por esse caractere
#include <stdio.h>
#include <string.h>
int isVogal(char letra);
void trocar_caracteres(char *str1, char letra);
int main()
{
    char str1[100], letra;
    scanf("%s", str1);
    printf("Digite a letra desejada: ");
    scanf(" %c", &letra);
    printf("\n Antes da troca: %s", str1);
    trocar_caracteres(str1, letra);
    printf("\n Depois da troca: %s", str1);
}
int isVogal(char letra)
{

    if (toupper(letra) == 'A' || toupper(letra) == 'E' || toupper(letra) == 'I' || toupper(letra) == 'O' || toupper(letra) == 'U')
        return 1;
    else
        return 0;
}
void trocar_caracteres(char *str1, char letra)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (isVogal(str1[i]) == 1)
            str1[i] = letra;
        i++;
    }
}