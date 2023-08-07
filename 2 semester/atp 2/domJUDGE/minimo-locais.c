/*
Encontrar os minimos locais de uma matriz na regiao delimitada por alfa e beta

fazer uma funcao que percorre a matriz entre as regieos de origin e end e pega o minimo local

*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int minimum(int tamanho, int matriz[tamanho][tamanho], int origin, int end);

int main()
{
    int tamanho, total_regioes, i, j, origin, end;
    scanf("%d %d", &tamanho, &total_regioes);
    int matriz[tamanho][tamanho];
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int l = 0; l < total_regioes; l++)
    {
        scanf("%d %d", &origin, &end);
        printf("%d \n", minimum(tamanho, matriz, origin, end));
    }

    return 0;
}
int minimum(int tamanho, int matriz[tamanho][tamanho], int origin, int end)
{
    int minimum = INT_MAX, m, n;
    /*
    Vai percorrer de matriz[origin][origin] até matriz[end][end] e ir pegar o minimo local
    */
    for (m = origin - 1; m <= end - 1; m++)
    {
        for (n = origin - 1; n <= end - 1; n++)
        {
            if (matriz[m][n] < minimum)
                minimum = matriz[m][n];
        }
    }
    return minimum;
}