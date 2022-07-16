// Fa?a um programa capaz de ler as coordenadas (x e y) que definem cinco pontos em um plano cartesiano.
// Considere o primeiro ponto como refer?ncia e, em seguida, o programa deve imprimir o ponto lido que
// tem a menor dist?ncia em rela??o ao ponto de refer?ncia. Apresente tamb?m a dist?ncia entre os dois
// pontos.
#include <stdio.h>
#include <math.h>
#define qtd_pontos 3
int main()
{
    struct plano
    {
        int x;
        int y;
    };
    struct plano ponto[qtd_pontos], referencia;
    int distancia[qtd_pontos], indice, menor_dist, i;
    for (i = 0; i < qtd_pontos; i++)
    {
        printf("Digite o ponto x: ");
        scanf(" %d", &ponto[i].x);
        setbuf(stdin, NULL);

        printf("\n Digite o ponto y: ");
        scanf(" %d", &ponto[i].y);
        setbuf(stdin, NULL);

        if (i == 0)
        {
            referencia.x = ponto[i].x;
            referencia.y = ponto[i].y;
        }
    }
    for (i = 0; i < qtd_pontos; i++)
    {

        distancia[i] = sqrt(pow((referencia.x - ponto[i].x), 2) + pow((referencia.y - ponto[i].y), 2));
        if (i == 1)
        {
            menor_dist = distancia[i];
            // calcular o ponto de referencia - o ponto de referencia vai dar zero, preciso arrumar
            // um jeito de n?o calcular a distnacia para ponto[0]
        }
        else if (i > 1)
        {
            if (distancia[i] < menor_dist)
            {
                menor_dist = distancia[i];
                indice = i;
            }
        }
        printf("\n A distancia entre o ponto %d e a referencia eh de: %d", i, distancia[i]);
    }
    printf("\n A menor distancia eh a do ponto %d, marcada de %d ", indice, menor_dist);

    return 0;
}

