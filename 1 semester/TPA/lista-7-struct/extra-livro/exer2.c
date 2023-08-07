#define dias 3 // mudar para 30
#define servicos_dia 3
#include <stdio.h>
int main()
{
    struct tipo_servico
    {
        char descricao[30];
        int codigo;
    };
    struct servicos
    {
        int comanda;
        int codigo_servico;
        int cod_cliente;
        float preco;
    };
    struct tipo_servico tipos[4];
    struct servicos servicosprestados[dias][servicos_dia];
    int data, indice;
    printf("Cadastrando os tipos de serviço: ");
    for (int i = 0; i < 4; i++)
    {
        printf("\n Digite a descricao do servico: ");
        scanf("%s", &tipos[i].descricao);
        printf("\n Digite o codigo do servico: ");
        scanf("%d", &tipos[i].codigo);
    }
    printf("\n Cadastrando os servicos");
    for (int i = 0; i < dias; i++)
    {
        for (int j = 0; j < servicos_dia; j++)
        {
            printf("\n Digite a comanda: ");
            scanf("%d", &servicosprestados[i][j].comanda);
            printf("\n Digite o codigo do servico: ");
            scanf("%d", &servicosprestados[i][j].codigo_servico);
            printf("\n Digite o codigo do cliente: ");
            scanf("%d", &servicosprestados[i][j].cod_cliente);
            printf("\n Digite o preco: ");
            scanf("%f", &servicosprestados[i][j].preco);
        }
    }

    printf("\n Digite uma data para filtrar a busca: ");
    scanf("%d", &data);
    for (int j = 0; j < servicos_dia; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (servicosprestados[data][j].codigo_servico == tipos[i].codigo)
            {
                indice = i;
            }
        }
        printf("\n Nome do servico: %s", tipos[indice].descricao);
        printf("\n comanda: %d", servicosprestados[dias][j].comanda);
        printf("\n Codigo do cliente: %d", servicosprestados[dias][j].cod_cliente);
        printf("\n Codigo do servico: %d", servicosprestados[dias][j].codigo_servico);
        printf("\n Preco: %f", servicosprestados[dias][j].preco);
    }
    return 0;
}