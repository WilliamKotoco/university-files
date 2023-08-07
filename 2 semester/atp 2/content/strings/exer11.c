// Fac¸a um programa que receba do usuario uma string. O programa imprime a string sem ´
// suas vogais.
#include <stdio.h>
#include <string.h>
void tirar_vogais(char *str);
int isVogal(char letra);
int main()
{
    char str[100];
    scanf("%s", str);
    printf("\n com vogais: %s \n", str);
    tirar_vogais(str);
    printf("\n sem vogais: %s", str);
    return 0;
}
void tirar_vogais(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {

        if (isVogal(str[i]) == 1)
            str[i] = ' ';
        i++;
    }
}
int isVogal(char letra)
{

    if (toupper(letra) == 'A' || toupper(letra) == 'E' || toupper(letra) == 'I' || toupper(letra) == 'O' || toupper(letra) == 'U')
        return 1;
    else
        return 0;
}
