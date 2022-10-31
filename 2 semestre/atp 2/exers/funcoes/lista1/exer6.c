// Crie um programa em C, que contenha uma função recursiva que receba dois
// inteiros positivos k e n e calcule kn
// . Utilize apenas multiplicações. O programa principal
// deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
// função.
#include <stdio.h>
int multiplicacao(int k, int n);

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d", multiplicacao(k, n));
}
int multiplicacao(int k, int n)
{
    if (n == 0)
        return 1;
    else
    {
        return k * multiplicacao(k, n - 1);
    }
}