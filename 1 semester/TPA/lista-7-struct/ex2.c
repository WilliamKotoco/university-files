//   Repita o exercício anterior, porém considere que a struct deve permitir
// o armazenamento dos dados de 10 alunos.
#include <stdio.h>
#define n 10
int main()

{
    typedef struct aluno
    {
        char nome[n][40];
        float nota1[n], notatrabalho[n], media[n];
    } aluno;
    aluno aluno1;
    for (int i = 0; i < n; i++)
    {
        printf("Digite seu nome: ");
        scanf("%s", &aluno1.nome[i]);
        printf("\n Digite sua nota: ");
        scanf("%f", &aluno1.nota1[i]);
        printf("\n Digite a nota do trabalho: ");
        scanf("%f", &aluno1.notatrabalho[i]);
        aluno1.media[i] = (aluno1.nota1[i] + aluno1.notatrabalho[i]) / 2;
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n Nome: %s", aluno1.nome[i]);
        printf("\n Nota1: %2.f", aluno1.nota1[i]);
        printf("\n Nota2: %2.f", aluno1.notatrabalho[i]);
        printf("\n Media: %2.f ", aluno1.media[i]);
    }
    return 0;
}