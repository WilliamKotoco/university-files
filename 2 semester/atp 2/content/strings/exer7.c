// compara duas strings sem usar strcmp
#include <stdio.h>
#include <string.h>
int comparacao(char *, char *);
int main()
{
    int flag;
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    flag = comparacao(str1, str2);
    if (flag == 0)
        printf("\n strings diferentes");
    else if (flag == 1)
        printf("\n strings iguais");
    return 0;
}
int comparacao(char *str1, char *str2)
{
    int i = 0;
    if (strlen(str1) != strlen(str2))
        return 0;
    // se as duas strings tem tamanho diferente, impossivel serem iguais
    else
    {
        while (str1[i] != '\0')
        {
            if (str1[i] != str2[i])
                return 0;
            i++;
        }
    }
    return 1;
}