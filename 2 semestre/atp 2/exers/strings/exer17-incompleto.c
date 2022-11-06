// Leia um vetor contendo letras de uma frase inclusive os espac¸os em branco. Retirar os
// espac¸os em branco do vetor e depois escrever o vetor resultante
#include <stdio.h>
#include <string.h>
void remover_espacos(char *str);
int main()
{
    char frase[1024];
    scanf("%[^\n]s", frase);
    printf("\n %s", frase);
    remover_espacos(frase);
    printf("\n %s", frase);
}
void remover_espacos(char *str)
{
    int i;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            str[i] = str[i + 1];
        i++;
    }
}