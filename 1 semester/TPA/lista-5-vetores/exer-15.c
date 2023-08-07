/*
Elaborar um programa para calcular o reajuste de salário de uma empresa com 10
funcionários. O usuário deve responder se deseja continuar ou não a execução do algoritmo.
Considere que o funcionário deverá receber um reajuste de 15%, caso seu salário seja menor
que R$ 500,00. Se o salário for maior ou igual a R$ 500,00, mas menor ou igual a R$ 1000,00,
o reajuste será de 10%. Se salário for maior que R$ 1000,00, o reajuste deverá ser de 5%.
*/
#include <stdio.h>
#define qtdfunc 3 // mudar pra 10 depois
int main()
{
    char nome[qtdfunc][40];
    int cod[qtdfunc], i, continuar;
    float salarios[qtdfunc], salarios_reajustados[qtdfunc];
    do
    {

        for (int i = 0; i < qtdfunc; i++)
        {
            printf("\n Digite o codigo: ");
            scanf("%d", &cod[i]);
            printf("\n Digite o nome: ");
            scanf(" %[^\n]s", nome[i]);
            printf("\n Digite o salario do funcionario: ");
            scanf("%f", &salarios[i]);

            if (salarios[i] < 500)
                salarios_reajustados[i] = salarios[i] * 1.15;
            else if (salarios[i] >= 500 && salarios[i] <= 1000)
                salarios_reajustados[i] = salarios[i] * 1.10;
            else
                salarios_reajustados[i] = salarios[i] * 1.05;
        }
        printf("Digite [0] para parar, qualquer outro numero para continaur: ");
        scanf("%d", &continuar);
    } while (continuar != 0);
    printf("\n Codigo \t nome \t salario \t reajuste");
    for (int i = 0; i < qtdfunc; i++)
    {
        printf("\n\t\t%d\t%s\t\t\t\t%.2f\t\t\t%.2f", cod[i], nome[i], salarios[i], salarios_reajustados[i]);
    }
    return 0;
}