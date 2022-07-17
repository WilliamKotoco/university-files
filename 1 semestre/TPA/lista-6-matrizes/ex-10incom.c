// Construa um programa para corrigir uma prova com 10 questões de múltipla escolha (a, b, c, d ou e), em
// uma turma com três alunos. Cada questão vale 1 ponto. O programa deve ler o gabarito, a matrícula
// (número inteiro) de cada aluno e suas respostas. Calcule e escreva: Para cada aluno, escreva sua
// matrícula, suas respostas e sua nota. O percentual de aprovação, assumindo média 7.0.

/*
todo: ler o gabarito
todo: criar um vetor alunos_respostas, com as respostas
todo: criar um vetor matriculas, cada indice associado com o vetor aluno_respostas
todo: o mesmo com o vetor notas

*/
#include <stdio.h>
#define qtd_alunos 3
int main()
{
    char gabarito[11];
    char aluno_respostas[qtd_alunos][10];
    int matriculas[qtd_alunos];
    int notas[qtd_alunos];
    char nomes[qtd_alunos][40];
    printf("digite, em ordem e sem espaco, o gabarito");
    scanf("%s", &gabarito);

    for (int i = 0; i < qtd_alunos; i++)
    {
        for (int j = 0; j < qtd_alunos; j++)
        {
            printf("Digite as respostas, em ordem e sem espacamento: ");
            scanf(" &[^\n]s", aluno_respostas[i][j]);
        }
        printf("Digite a matricula: ");
        scanf("%d", matriculas[i]);
    }

    return 0;
}
