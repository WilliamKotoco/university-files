// Crie um programa que calcula o comprimento de uma string (nao use a func¸ ˜ ao strlen)
#include <stdio.h>
int tamanho(char *str);
int main()
{
    char string[40];
    scanf("%s", string);
    printf("%d", tamanho(string));
}
int tamanho(char *str)
{
    int i;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}