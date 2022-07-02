//  Crie um tipo registro chamado Cadastro que tenha os campos Nome (Alfanumérico
// ), Ender (Endereco),  Dnasc (Data), Telefone (Alfanumérico).
// No mesmo programa, crie os tipos Data e Endereco. Crie um  vetor Contato do
//  tipo Cadastro com 10 elementos. Faça um programa que leia todos os elementos de
//  Contato e em seguida os imprima.
#define n 10
#include <stdio.h>
int main()
{
    struct cadastro
    {
        char nome[40];
        char endereco[40];
        char data[40];
        char telefone[40];
    };
    struct cadastro contato[n];
    for (int i = 0; i < n; i++)
    {
        printf("Digite seu nome: ");
        scanf("%s", contato[i].nome);
        printf("\n Digite seu CEP: ");
        scanf("%s", &contato[i].endereco);
        printf("\n Digite data nascimento: ");
        scanf("%s", &contato[i].data);
        printf("\n Digite seu telefone: ");
        scanf("%s", &contato[i].telefone);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("\nNome: %s ", contato[i].nome);
        printf("\nTelefone: %s ", contato[i].telefone);
        printf("\n CEP: %s ", contato[i].endereco);
        printf("\n Data nascimento: %s", contato[i].data);
    }

    return 0;
}