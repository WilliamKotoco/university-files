// Faça um programa capaz de ler as coordenadas (x e y) que definem cinco pontos em um plano cartesiano.
// Considere o primeiro ponto como referência e, em seguida, o programa deve imprimir o ponto lido que
// tem a menor distância em relação ao ponto de referência. Apresente também a distância entre os dois
// pontos.
#include <stdio.h>
#include <math.h>
#define qtd_pontos 5
int main()
{
    struct plano
    {
        int x;
        int y;
    };
    struct plano ponto[qtd_pontos], referencia;
    int distancia[qtd_pontos], indice, menor_dist;
    for (int i = 0; i < qtd_pontos; i++)
    {
        printf("Digite o ponto x: ", &ponto[i].x);
        printf("\n Digite o ponto y: ", &ponto[i].y);
        if (i == 0)
        {
            referencia.x = ponto[i].x;
            referencia.y = ponto[i].y;
        }
    }
    // criando um for separado para calcular a distancia, vai ficar bonitinho
    for (int i = 0; i < qtd_pontos; i++)
    {

        distancia[i] = sqrt(pow((referencia.x - ponto[i].x), 2) + pow((referencia.y - ponto[i].y), 2));
        if (i == 0)
        {
            menor_dist = distancia[i];
            // calcular o ponto de referencia - o ponto de referencia vai dar zero, preciso arrumar
            // um jeito de não calcular a distnacia para ponto[0]
        }
        else
        {
            if (distancia[i] < menor_dist && distancia[i])
            {
                        }
        }
    }

    return 0;
}