// Faça um
// programa que receba (via teclado) as informações que permitem definir um retângulo  e informe: área e o
// comprimento de cada aresta.
#include <stdio.h>
int main()
{
    struct modelo_retangulo
    {
        int medidas[4];
    };
    struct modelo_retangulo retangulo;
    int valores_repetidos = 0, area;

    for (int i = 0; i < 4; i++)
    {
        printf("Digite as medidas: ");
        scanf("%d", &retangulo.medidas[i]);
    }
    // checar se tem dois valores iguais
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (retangulo.medidas[i] == retangulo.medidas[j])
            {
                valores_repetidos++;
            }
        }
    }
    // para ser um retangulo, todos os valores devem repetir duas vezes (quando j apontar para o mesmo valor que i
    // e quando o valor em j for igual ao valor de i, mesmo apontando para indices diferentes)
    if (valores_repetidos != 8)
    {
        printf("\n Nao pode formar um retangulo: ");
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            printf("\n LADO %d: %d", i, retangulo.medidas[i]);
            for (int j = 0; j < 4; i++)
            {
                if (retangulo.medidas[i] != retangulo.medidas[j])
                {
                    area = retangulo.medidas[i] * retangulo.medidas[j];
                }
            }
        }
        printf("A area eh de %d ", area);
    }
    return 0;
}