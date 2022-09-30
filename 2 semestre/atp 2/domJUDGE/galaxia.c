#include <stdio.h>
#include <stdlib.h>

struct coordenadas
{
    double x, y, z;
};
struct planetas
{
    char nome[21];
    double peso;
    struct coordenadas coord;
};

// void coletandoDados(int n, struct planetas planeta);
int main()
{
    int N, M, i;
    
    scanf("%d", &N);
    scanf("%d", &M);
    ;
    for (i = 0; i < N; i++)
    {
        scanf("%[^\n]s", &plan[i].nome);
        scanf("%f", &plan[i].peso);
        scanf("%f %f %f", &plan[i].coord.x, &plan[i].coord.y, &plan[i].coord.z);
    }

    return 0;
}
struct planetas plan[N];
struct coordenadas coord

    // testes
    // for (i = 0; i < N; i++)
    // {
    //     printf("\n Nome: %S", plan[i].nome);
    //     printf("\n Peso: %f", plan[i].peso);
    //     printf("\n Coordenadas: %f %f %f ", plan[i].coord.x, plan[i].coord.y, plan[i].coord.z);
    // }