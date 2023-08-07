/*
Escreva um algoritmo que leia a idade e altura de cada aluno de uma turma de 50
pessoas, e que calcule/imprima na tela:
(a) A idade média dos alunos com menos de 1.70m de altura.
(b) A altura média dos alunos com mais de 20 anos.
(c) A idade do aluno mais velho da turma.
(d) A idade do aluno mais novo da turma.
*/
#include <stdio.h>
#define max 50 // mudar para 50 depois
int main()
{
    int i, k, idades[max], alturas[max], acum1 = 0, acum2 = 0, cont1 = 0, cont2 = 0, maior_idade = 0, menor_idade = 0;

    for (int i = 0; i < max; i++)
    {
        printf("Digite a idade: ");
        scanf("%d", &idades[i]);
        printf("Digite a altura em cm: ");
        scanf("%d", &alturas[i]);

        if (maior_idade == 0 && menor_idade == 0)
        {
            maior_idade = idades[i];
            menor_idade = idades[i];
        }
        else
        {
            if (idades[i] > maior_idade)
            {
                maior_idade = idades[i];
            }
            else if (idades[i] < menor_idade)
            {
                menor_idade = idades[i];
            }
        }
    }

    for (int k = 0; k < max; k++)
    {
        if (alturas[k] < 170)
        {
            acum1 = acum1 + idades[i];
            cont1++;
        }

        if (idades[i] > 20)
        {
            acum2 = acum2 + alturas[i];
            cont2++;
        }
    }
    printf("\n a) %f", (float)acum1 / cont1);
    printf("\n b) %f", (float)acum2 / cont2);
    printf("\n c) %d", maior_idade);
    printf("\n d) %d", menor_idade);
    return 0;
}