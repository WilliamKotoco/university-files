// 9) Crie uma função recursiva que receba um número inteiro positivo N e calcule o
// somatório dos números de 1 a N.
#include <stdio.h>
int somatorio(int num, int limite);
int main()
{
    int num, limite;
    scanf("%d", &num);
    scanf("%d", &limite);

    printf("%d\n", somatorio(num, limite));
}
int somatorio(int num, int tamanho)
{
    // essa funcao considera que o imbecil nao vai fazer um somatorio de N ate 0
    if (tamanho == 1)
        return num;
    else
    {
        return num + somatorio(num, tamanho - 1);
    }
}
