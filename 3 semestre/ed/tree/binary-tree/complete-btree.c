#include <stdio.h>
#include <math.h>
#define NUM 7
/*
Árvore binária completa é uma árvore estritamente binária na qual todas suas folhas estão no mesmo nível.
Como seu comportamento é previsível, inclusive o seu tamanho, é mais eficiente aplicar com
arrays.

Seu número de nós é de 2^h - 1, sendo h sua altura.

Os filhos do termo i estarão nos índices 2i +1
*/
void displayInfo(int *A);
int height(int *);
int grade(int *A);
void findSons(int *A, int element, int *n1, int *n2);
int verifyExistence(int *A, int element);



int main()
{
    int A[NUM] = {0, 9, 3, 5, 2, 90, 7};

    displayInfo(A);

    return 0;
}
void displayInfo(int *A)
{
    int element;
    int n1, n2;
    printf("A Árvore tem a altura de : %d", height(A));
    printf("\n O grau da árvore é de: %d", grade(A));
    printf("\n Digite qual número da árvore você quer informações: ");
    scanf("%d", &element);
    while (!verifyExistence(A,element))
    {
        printf("\n Número não existe!");
        printf("\n Digite qual número da árvore você quer informações: ");
        scanf("%d", &element);
    }
    findSons(A,element, &n1, &n2);


    printf(" Os filhos do elemento são %d %d", n1,n2);
}
int height(int *A)
{
    // número de nós é dado por 2^h - 1, tiramos a altura a partir dessa fórmula
    //
    return (log2(NUM) + 1); // considero 0 como sendo o primeiro nível, então devo adicionar mais um.
}
int grade(int *A)
{
    int acum = 1;
    // grau da árvore é o número de filhos do nó que mais tiver filhos.
    // como sabemos que é uma árvore estritamente binária, sabemos que o número de filhos dela
    // é diretamente proporcional ao nível. Como sabemos que o nível é um menos que a altura, visto que começamos do zero, teremos então:
    for (int i = 0; i < height(A) - 1; i++)
        acum = acum * 2;
    return acum;
}
int verifyExistence(int *A, int element)
{
    for (int i = 0; i < NUM; i++)
        if(element == A[i])
            return 1;
    return 0;
}
void findSons(int *A, int element, int *n1, int *n2)
{
    // altera o valor por referência, visto que terá dois filhos e não podemos retornar duas variáveis
    int ind;
    for (int i = 0; i < NUM; i++)
    {
        if(A[i] == element)
        {
            ind = i;
            break;
        }
    }
    *n1 = A[2*ind +1]; // começa do índice 0
    *n2 = A[2*ind + 2];
}