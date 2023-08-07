// Faça um programa que, utilizando registros, leia o nome e data de nascimento
// (dia mês ano) de n pessoas (n = 40), calcule e mostre a idade de cada pessoa
//  e o nome da pessoa mais velha. Suponha que não temos
// duas (ou mais) pessoas com a mesma idade.
#define n 40
#include <stdio.h>
int main()
{
    struct pessoa
    {
        char nome[40];
        int dia, mes, ano, idade;
    };

    struct pessoa cliente[n];
    int idade, ano_atual = 2022, maior_idade = 0, indice;
    for (int i = 0; i < n; i++)
    {
        printf("Digite o nome: ");
        scanf("%s", &cliente[i].nome);
        printf("Digite o dia, mes e ano de nascimento: ");
        scanf("%d %d %d", &cliente[i].dia, &cliente[i].mes, &cliente[i].ano);
        cliente[i].idade = ano_atual - cliente[i].ano;
        if (maior_idade == 0)
        {
            maior_idade = cliente[i].idade;
            indice = i;
        }
        else
        {
            if (idade > maior_idade)
            {
                maior_idade = cliente[i].idade;
                indice = i;
            }
        }
    }
    printf("Mostrando as idades: ");
    for (int i = 0; i < n; i++)
    {
        printf("\n %d", cliente[i].idade);
    }
    printf("\n A maior idade é do cliente: %s", cliente[indice].nome);
    return 0;
}