#include <stdio.h>
#include <stdlib.h>
void ordenar(int *vetor, int M);
void inicializar_vetor(int *vetor, int M);
void recursao(int target, int *possiveis, int *listaAtual, int qtd, int indice, int array_size_at, int maior_at);
void trade_arrays(int *origem);
void adiciona(int *vetor, int item);
int getarraysize(int *vetor);
int getmaior(int *vetor, int tamanho);
int qtd_combinacoes = 0;
int *combinacoes;
int array_size, maior = 0;

int main()
{
    int N, M, i, j;
    // N é a quantidade de numeros a serem decompostos
    // M é a quanitdade de elementos que podem ser usados na composicao
    printf("Digite N e M: ");
    scanf("%d %d", &N, &M);
    int possiveis[M], elementos[N], listaAtual[M];
    int maior_elemento = 0, array_size = 0;
    combinacoes = malloc(M * sizeof(int));

    for (i = 0; i < M; i++)
    {
        scanf("%d", &possiveis[i]);
    }
    ordenar(possiveis, M); // ordena o vetor para poder jogar no backtracking, ficar mais fácil de comparar elementos iguais visto que estaram congiquos
    for (i = 0; i < N; i++)
    {
        scanf("%d", &elementos[i]);
    }
    for (i = 0; i < N; i++)
    {
        j = 0;
        inicializar_vetor(combinacoes, M); // inicaliza ao vetor combinacao como zero para tratar os valores nulos depois, e também poder zerar caso o algoritmo seja executado novamente
        inicializar_vetor(listaAtual, M);
        recursao(elementos[i], possiveis, listaAtual, M, 0, maior_elemento, array_size);
        printf("%d ", qtd_combinacoes);
        while (combinacoes[j] != 0)
        {
            printf("%d ", combinacoes[j]);
            j++;
        }
        printf("\n");
        qtd_combinacoes = 0;
        maior_elemento = 0;
        array_size = 0;
    }

    return 0;
}
void ordenar(int *vetor, int M)
{
    int i, j, temp;
    for (i = 0; i < M; i++)
    {
        for (j = i + 1; j < M; j++)
        {
            if (vetor[j] < vetor[i])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

void inicializar_vetor(int *vetor, int M)
{
    int k;
    for (k = 0; k < M; k++)
        vetor[k] = 0;
}
void recursao(int target, int *possiveis, int *listaAtual, int qtd, int indice, int array_size_at, int maior_at)
{

    int tamanho = getarraysize(listaAtual);

    int i;
    if (target == 0)
    {
        // verificacao se é o que tem mais elementos.
        if (array_size_at > array_size || (array_size == array_size_at && maior_at > maior))
        {
            trade_arrays(listaAtual);
            array_size = array_size_at;
            maior = maior_at;
        }
        array_size_at = 0;
        maior_at = 0;
        qtd_combinacoes++;
    }

    else if (target <= 0)
    {
        return; // errado, retorna nulo
    }
    for (i = indice; i < qtd; i++)
    {
        if (possiveis[i] > maior_at)
            maior_at = possiveis[i];
        if (indice == i || possiveis[i] != possiveis[i - 1]) // se for o primeiro ou o primeiro for diferente do anterior
        {
            adiciona(listaAtual, possiveis[i]); // funcao para adicioanr no primeiro lugar disponviel, para nao sobrepor a outros
            recursao(target - possiveis[i], possiveis, listaAtual, qtd, i + 1, array_size_at + 1, maior_at);
            listaAtual[tamanho] = 0; // remove o ultimo elemento para não repetir
        }
    }
}
void trade_arrays(int *origem)
{

    int i = 0;
    while (origem[i] != 0) // zero é o valor padrão, escolhido para ignorar
    {
        combinacoes[i] = origem[i];
        i++;
    }
}
void adiciona(int *vetor, int item)
{

    int i = 0;
    while (vetor[i] != 0)
        i++; // i vai ser o indice do primeiro lugar disponivel
    vetor[i] = item;
}
int getarraysize(int *vetor)
{

    int i = 0;
    while (vetor[i] != 0)
        i++;

    return i;
}
