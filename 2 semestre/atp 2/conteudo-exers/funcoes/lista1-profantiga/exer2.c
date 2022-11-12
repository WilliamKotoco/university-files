// Crie um programa em C, que contenha uma função recursiva que receba dois
// inteiros positivos k e n e calcule kn
// . Utilize apenas multiplicações. O programa principal
// deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
// função. Agora estende-se para k sendo menor que zero.
#include <stdio.h>
float potencia(float k, float n);

int main()
{
    float k, n;
    scanf("%f %f", &k, &n);
    printf("%.2f", potencia(k, n));
}
float potencia(float k, float n)
{
    if (n == 0)
        return 1;
    else
    {
        if (n > 0)
            return k * potencia(k, n - 1);
        else
            return (1 / potencia(k, -n));
    }
}