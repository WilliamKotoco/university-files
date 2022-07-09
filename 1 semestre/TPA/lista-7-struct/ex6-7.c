// Construir um programa em linguagem C para controlar o estoque de um produto. Especificamente, o
// programa deve usar um registro composto por um campo (valor numérico) que representa baixas do
// produto por dia da semana. Assim, um vetor com seis posições indicará que cada uma define um dia útil
// da semana (incluindo o sábado). O programa deve permitir leitura e escrita dos dados. O modelo é dado a
// seguir:
#include <stdio.h>
#define dias 6
#define qtdprod 2 // mudar para 20
struct produto
{
    char nome[40];
    float preco;
    int baixas[dias];
};
int main()
{
    struct produto produtos[qtdprod];
    for (int i = 0; i < qtdprod; i++)
    {
        printf("Digite o nome do produto: ");
        scanf(" %[^\n]s", produtos[i].nome);
        setbuf(stdin, NULL);

        printf("\n Digite o preco: ");
        scanf(" %f", &produtos[i].preco);
        setbuf(stdin, NULL);

        for (int j = 0; j < dias; j++)
        {

            printf("\n Digite as vendas do dia %d: ", j);
            scanf(" %d", &produtos[i].baixas[j]);
        }
    }
    for (int i = 0; i < qtdprod; i++)
    {
        printf("\n Produto %d ", i);
        printf("\n Nome: %s ", produtos[i].nome);
        printf("\n Preco: %2.f ", produtos[i].preco);
        printf("\n Vendas por dia da semana: ");
        for (int j = 0; j < dias; j++)
        {
            printf("\n %d ", produtos[i].baixas[j]);
        }
    }

    return 0;
}