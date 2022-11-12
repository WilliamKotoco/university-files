// Digite um nome, calcule e retorne quantas letras tem esse nome
#include <stdio.h>
void calcular_letras(char *str);
int isRepetida(char *str, char ch, int i);
int main()
{
    char nome[40];
    scanf("%s", nome);
    calcular_letras(nome);
    return 0;
}
void calcular_letras(char *str)
{
    int i, j, contador;
    int tamanho = strlen(str);
    char aux, letras[tamanho];
    for (i = 0; i < tamanho; i++)
    {
        contador = 0;
        aux = str[i];
        for (j = 0; j < tamanho; j++)
        {
            if (str[j] == aux)
                contador++;
        }
        if (isRepetida(str, str[i], i) == 0 || i == 0)
            printf("\n %c aparece %d vezes", aux, contador);
    }
}
int isRepetida(char *str, char ch, int i)
{
    int k;
    for (k = 0; k < i; k++)
    {
        if (str[k] == ch)
            return 1;
    }
    return 0;
}
