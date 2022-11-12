// Fac¸a um programa que conte o numero de 1’s que aparecem em um string. Exemplo: ´
// “0011001” -> 3
#include <stdio.h>
int qtd_1(char *str);
int main()
{
    char string[100];
    scanf("%s", string);
    printf("o numero 1 aparece %d vezes", qtd_1(string));
}
int qtd_1(char *str)
{
    int i, contador;
    while (str[i] != '\0')
    {
        if (str[i] == '1')
            contador++;
        i++;
    }
    return contador;
}