    #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct coordenadas
{
    long int x, y, z;
};
struct planeta
{
    char nome[20];
    double peso;
    struct coordenadas cord;
};
// prototipos das funcoes
void entrada_dados(struct planeta *p_planeta, int qtd);
void opcoes(struct planeta *p_planeta, int qtd_info);
void case_1(struct planeta *p_planeta);
double calc_dis(struct planeta *p_planeta, int i_plan1, int i_plan2);
int buscar_planeta(struct planeta *p_planeta, char *nome_busca);
void case_2(struct planeta *p_planeta);
void case_3(struct planeta *p_planeta);

int main()
{
    struct planeta *p_planeta;
    int qtd, qtd_info, op, i;
    char nome_busca[2][20];
    scanf("%d %d", &qtd, &qtd_info);
    p_planeta = malloc(qtd * sizeof(struct planeta));
    entrada_dados(p_planeta, qtd);
    opcoes(p_planeta, qtd_info);
    return 0;
}

void entrada_dados(struct planeta *p_planeta, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        scanf("%s %lf %ld %ld %ld ", p_planeta[i].nome, &p_planeta[i].peso, &p_planeta[i].cord.x, &p_planeta[i].cord.y, &p_planeta[i].cord.z);
    }
}

void opcoes(struct planeta *p_planeta, int qtd_info)
{
    int i, op;

    for (i = 0; i < qtd_info; i++)
    {
        scanf("%d ", &op);
        switch (op)
        {
        case 1:
            case_1(p_planeta);
            break;
        case 2:
            case_2(p_planeta);
            break;
        case 3:
            case_3(p_planeta);
            break;
        }
    }
}
void case_1(struct planeta *p_planeta)
{
    char nome_busca[2][20];
    int i, i_plan1, i_plan2;
    double dist;
    scanf("%s %s", nome_busca[0], nome_busca[1]);
    i_plan1 = buscar_planeta(p_planeta, nome_busca[0]);
    i_plan2 = buscar_planeta(p_planeta, nome_busca[1]);
    dist = calc_dis(p_planeta, i_plan1, i_plan2);
    printf(" %.2lf\n", dist);
}
int buscar_planeta(struct planeta *p_planeta, char *nome_busca)
{
    int i = 0;
    while (strcmp(p_planeta[i].nome, nome_busca) != 0)
    {
        i++;
    }
    return i;
}
double calc_dis(struct planeta *p_planeta, int i_plan1, int i_plan2)
{
    long int p1x, p1y, p1z, p2x, p2y, p2z;
    double distancia;
    p1x = (double)p_planeta[i_plan1].cord.x;
    p1y = (double)p_planeta[i_plan1].cord.y;
    p1z = (double)p_planeta[i_plan1].cord.z;
    p2x = (double)p_planeta[i_plan2].cord.x;
    p2y = (double)p_planeta[i_plan2].cord.y;
    p2z = (double)p_planeta[i_plan2].cord.z;
    distancia = sqrt((p2x - p1x) * (p2x - p1x) + (p2y - p1y) * (p2y - p1y) + (p2z - p1z) * (p2z - p1z));
    return distancia;
}
void case_2(struct planeta *p_planeta)
{
    int i_planeta;
    char nome_busca[20];
    scanf(" %s", nome_busca);
    i_planeta = buscar_planeta(p_planeta, nome_busca);
    printf(" %ld %ld %ld\n", p_planeta[i_planeta].cord.x, p_planeta[i_planeta].cord.y, p_planeta[i_planeta].cord.z);
}
void case_3(struct planeta *p_planeta)
{
    int i_planeta;
    char nome_busca[20];
    scanf(" %s", nome_busca);
    i_planeta = buscar_planeta(p_planeta, nome_busca);
    printf("%.2lf\n", p_planeta[i_planeta].peso);
}
