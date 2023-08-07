/*
Faça um programa que leia dois vetores u e v no espaço (de três coordenadas de números reais),
e um número real alpha. Mostre então na tela:
(a) o vetor soma (u + v).
(b) o vetor resultante alpha * (u + v).
(c) o valor do produto escalar entre u e v (fórmula: ux * vx + uy * vy + uz * vz). */
#include <stdio.h>

int main()
{
    int u[3], v[3], resultante[3], vetor_alpha[3], produto = 0;
    float alpha;
    printf("Digite os componentes x,y e z:");
    scanf("%d %d %d", &u[0], &u[1], &u[2]);
    printf("\n Digite os componentes x,y e z:");
    scanf("%d %d %d", &v[0], &v[1], &v[2]);
    printf("Digite o numero real alpha: ");
    scanf("%f", &alpha);
    printf("\n Soma dos vetores: ");

    for (int i = 0; i < 3; i++)
    {
        produto = produto + v[i] * u[i];
        resultante[i] = u[i] + v[i];
        vetor_alpha[i] = resultante[i] * alpha;
        printf("%d ", resultante[i]);
    }
    printf("\n Mostrando o vetor alpha: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", vetor_alpha[i]);
    }
    printf("\n Produto escalar: %d", produto);
}