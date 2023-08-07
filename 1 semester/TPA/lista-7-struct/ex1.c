//  Faça um programa em Linguagem C para criar uma estrutura composta pelos campos
// : notaprova, notatrabalho, média e nome. O programa deve permitir a leitura
// do nome e notas de um aluno. Em // seguida, o programa deve calcular a média e
// armazenar no campo correspondente. Imprimir os dados
#include <stdio.h>
int main()
{
    typedef struct aluno
    {
        char nome[40];
        float nota1, notatrabalho, media;
    } aluno;
    aluno aluno1;
    printf("Digite seu nome: ");
    scanf("%s", &aluno1.nome);
    printf("\n Digite sua nota: ");
    scanf("%f", &aluno1.nota1);
    printf("\n Digite a nota do trabalho: ");
    scanf("%f", &aluno1.notatrabalho);
    aluno1.media = (aluno1.nota1 + aluno1.notatrabalho) / 2;
    printf("\n Nome: %s", aluno1.nome);
    printf("\n Nota1: %2.f", aluno1.nota1);
    printf("\n Nota2: %2.f", aluno1.notatrabalho);
    printf("\n Media: %2.f ", aluno1.media);
    return 0;
}