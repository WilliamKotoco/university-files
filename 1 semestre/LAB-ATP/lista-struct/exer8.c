// 8. Crie um programa que converta coordenadas polares para cartesianas, isto  ́e:
// (a) Crie uma struct que represente um ponto em coordenadas polares: um raio (r), e
// um argumento (ˆangulo theta), dado em radianos.

// (b) Crie uma struct que represente um ponto em coordenadas cartesianas: duas coor-
// denadas reais, x e y.

// (c) No programa principal, leia um ponto em coordenada polar e converta-o para co-
// ordenadas cartesianas atrav ́es da f ́ormula: x = r cos(theta) e y = r sen(theta).

// Grave o resultado em uma vari ́avel do tipo coordenada cartesiana.
#include <stdio.h>
#include <math.h>
#define pi 3.14
int main()
{
    struct coordenadas_polares
    {
        float raio, angulo;
    };
    struct coordenadas_cartesianas
    {
        float x, y;
    };
    struct coordenadas_polares polares;
    struct coordenadas_cartesianas cartesianas;
    float angulo;

    printf("Digite o valor do raio: ");
    scanf("%f", &polares.raio);
    printf("\n Digite o valor do angulo: π x ");
    scanf("%f", &angulo);
    polares.angulo = pi * angulo;

    cartesianas.x = polares.raio * cos(polares.angulo);
    cartesianas.y = polares.raio * sin(polares.angulo);

    printf("Pontos no eixo cartesiano: (%f, %f)", cartesianas.x, cartesianas.y);
    return 0;
}