// . Considerando a estrutura dada a seguir para um vetor no R
// 3
// . Implemente um programa que calcule a
// soma de dois vetores

#include <stdio.h>
#include <math.h>
int main()
{
    struct vetor
    {
        int x, y, z
    };
    struct vetor vetor[2];
    int resultante[3], i;
    float resultado;
    for (i = 0; i < 2; i++)
    {
        printf("Digite x y z do vetor: ");
        scanf("%d %d %d", &vetor[i].x, &vetor[i].y, &vetor[i].z);
    }

    resultante[0] = vetor[0].x + vetor[1].x;
    resultante[1] = vetor[0].y + vetor[1].y;
    resultante[2] = vetor[0].z + vetor[1].z;
    resultado = sqrt(pow(resultante[0], 2) + pow(resultante[1], 2) + pow(resultante[2], 2));
    printf("Resultado: %2.f", resultado);
    return 0;
}
