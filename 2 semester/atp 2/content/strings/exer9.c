// . Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string por ˆ
// outro caractere ‘1’.
#include <stdio.h>
#include <string.h>
int checkExistence(char *str1, char letra_antiga);
void trocar_caracteres(char *str1, char letra_antiga, char letra_nova);
int main()
{
    char str1[100], letra_antiga, letra_nova;
    scanf("%[^\n]s", str1);
    fflush(stdin);
    while (checkExistence(str1, letra_antiga) == 0)
    {
        printf("\n Qual letra deseja trocar ? ");
        scanf(" %c", &letra_antiga);
        if (checkExistence(str1, letra_antiga) == 0)
            printf("\n Nao existe essa letra na palavra");
    }
    printf("\n qual letra nova colocar no lugar ? ");
    scanf(" %c", &letra_nova);
    trocar_caracteres(str1, letra_antiga, letra_nova);
    printf("\n nova string: %s", str1);
    return 0;
}
int checkExistence(char *str1, char letra_antiga)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == letra_antiga)
            return 1;
        else
            i++;
    }
    return 0;
}
void trocar_caracteres(char *str1, char letra_antiga, char letra_nova)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == letra_antiga)
            str1[i] = letra_nova;
        i++;
    }
}