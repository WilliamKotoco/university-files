// Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’
// (maiuscula ou min ´ uscula)
#include <stdio.h>
#include <stdlib.h>
void testar_nome(char *str);
int main()
{
    char nome[40];
    scanf("%s", nome);
    testar_nome(nome);
}
void testar_nome(char *str)
{
    if (str[0] == 'a' || str[0] == 'A')
        exit(1);
    else
        printf("%s", str);
}