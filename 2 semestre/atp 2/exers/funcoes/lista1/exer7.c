//  Crie um programa em C que receba um vetor de números reais com 100 elementos.
// Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.
#include <stdio.h>
void inverter_ordem(int *vetor, int inicio, int tamanho);
int main()
{
    const int tamanho = 10;
    int inicio = tamanho - tamanho;
    int vetor[tamanho], i;
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100;
        printf(" %d ", vetor[i]);
    }
    inverter_ordem(vetor, inicio, tamanho - 1); //-1 porque um vetor de 10 posicoes tem, na realidade, 9 indices
    printf("\n");
    for (i = 0; i < tamanho; i++)
    {
        printf(" %d ", vetor[i]);
    }
}
void inverter_ordem(int *vetor, int inicio, int tamanho)
{
    int aux;
    if (inicio < tamanho)
    {
        aux = vetor[inicio];
        vetor[inicio] = vetor[tamanho];
        vetor[tamanho] = aux;
        inverter_ordem(vetor, inicio + 1, tamanho - 1);
    }
}