#include <stdio.h>
#define qtd 3 // mudar para 15 depois
int main()
{
    struct modelo_banco
    {
        char num[10];
        char nome[50];
        float saldo;
    };
    struct modelo_banco bancos[qtd];
    int opcao, existe = 0;
    char nome_busca[15];
    float menor_saldo;

    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o numero da conta: ");
        scanf(" %[^\n]s", &bancos[i].num);
        if (i != 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (bancos[j].num == bancos[i].num)
                {
                    existe = 1;
                    break;
                }
            }
        }
        if (existe == 1)
        {
            printf("\n Mentiroso. Ja existe numero com essa conta! ");
        }
        else
        {
            printf("\n Digite o nome: ");
            scanf(" %[^\n]s", &bancos[i].nome);
            printf("\n Digite o saldo: ");
            scanf("%f", &bancos[i].saldo);
            if (i == 0)
            {
                menor_saldo = bancos[i].saldo;
            }
            else
            {
                if (bancos[i].saldo < menor_saldo)
                {
                    menor_saldo = bancos[i].saldo;
                }
            }
        }
    }

    printf("\n Digite o nome de um cliente para a busca: ");
    scanf(" %[^\n]s", &nome_busca);
    for (int i = 0; i < qtd; i++)
    {
        if (bancos[i].nome == nome_busca)
        {
            printf("\n Dados bancarios de %s: ", nome_busca);
            printf("\n Numero da conta: %s", bancos[i].num);
            printf("\n Saldo: %f", bancos[i].saldo);
        }
    }
    printf("Menor saldo: %f", menor_saldo);
    return 0;
}