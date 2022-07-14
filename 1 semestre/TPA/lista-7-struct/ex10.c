// Um provedor de acesso à Internet mantém o seguinte cadastro de clientes: código do cliente, e-mail,
// número de horas de acesso, página (S-sim ou N-não). Elaborar um programa em C que calcule e mostre
// um relatório contendo o valor a pagar por cada cliente, sabendo-se que as primeiras 20 horas de acesso
// custam R$35,00 e cada hora excedente tem o custo de R$2,50. Os clientes que têm páginas devem ter um
// acréscimo de R$40,00 a sua conta. O provedor tem um total de 20 clientes. O programa deve exibir um
// relatório em que cada registro deve aparecer em uma linha. Além disso, o programa deve exibir o total a
// recebe
#include <stdio.h>
#define clientes 20
struct cliente
{
    char nome[40];
    char email[80];
    int horas;
    char pagina;
};
int main()
{
    float preco[clientes], total = 0;
    float preco_20_horas = 35;
    struct cliente cliente[clientes];
    for (int i = 0; i < clientes; i++)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]s", cliente[i].nome);
        setbuf(stdin, NULL);

        printf("\n Digite o email: ");
        scanf(" %[^\n]s", cliente[i].email);
        setbuf(stdin, NULL);

        printf("\n Digite a quantidade de horas: ");
        scanf("%d", &cliente[i].horas);
        setbuf(stdin, NULL);

        printf("\n  Digite S se tem pagina, qualquer outra coisa se nao tiver: ");
        scanf(" %c", &cliente[i].pagina);
    }
    for (int i = 0; i < clientes; i++)
    {
        // calculo das horas

        if (cliente[i].horas <= 20)
        {
            if (cliente[i].pagina == 's' || cliente[i].pagina == 'S')
            {
                preco[i] = preco_20_horas + 40;
            }
            else
            {
                preco[i] = preco_20_horas;
            }
        }
        else if (cliente[i].horas > 20)
        {
            if (cliente[i].pagina == 's' || cliente[i].pagina == 'S')
            {
                preco[i] = 40 + preco_20_horas + (2.5 * (cliente[i].horas - 20));
            }
            else
            {
                preco[i] = preco_20_horas + (2.5 * (cliente[i].horas - 20));
            }
        }

        total = total + preco[i];
        printf("\n %s pagara %2.f ", cliente[i].nome, preco[i]);
    }
    printf("\n Total que a loja recebe: %2.f ", total);

    return 0;
}
