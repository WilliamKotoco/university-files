// c¸a um programa que receba uma palavra e a imprima de tras-para-frente.
#include <stdio.h>
void print_backwards(char *str);
int main()
{
    char str[100];
    scanf("%s", str);
    print_backwards(str);
    return 0;
}
void print_backwards(char *str)
{
    int i, tamanho = strlen(str);
    for (i = tamanho; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}