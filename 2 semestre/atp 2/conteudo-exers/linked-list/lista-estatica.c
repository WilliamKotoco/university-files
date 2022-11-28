
/*
A lista estática trabablha da mesma maneira que a lista dinâmica, mas dessa vez usando vetores
*/
#include<stdio.h>
#include<string.h>
struct fruteira 
{
    char nome[40];
    int cor; 
    int sabor;
    int prox; // aponta para o proximo indice, é um endereço que aponta para indices
};
void inicializar (struct fruteira *fruta);
void  add_fruta(struct fruteira *fruta, int *header);
void insere_na_lista(struct fruteira *fruta, int *header, int i);

int main()
{
/*
Temos que lembrar que pouco importa a ordem dos indices, entao podemos ter head sendo no
indice 4 por exemplo

para os elementos que não estão sendo usados, colocaremos -1 para tratar.
*/
struct fruteira frutas[20];
int op;
int header = -1;
inicializar(frutas); //inicializa todos os indicex prox como -1
scanf("%d", &op);
switch (op)
{
    case 1:
        add_fruta(frutas, &header);

}
}
void inicializar(struct fruteira *fruta)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        fruta[i].prox = -1;
    }
}
void add_fruta(struct fruteira *fruta, int *header)
{
    printf("\n chegou aqui");
    int i;
    while (fruta[i].prox != -1 && i < 20)
        i++; // pega o primeiro lugar disponivel para adicionar a fruta
    if (i == 19)
        return;   // lista ta cheia, vamos só retornar nulo

printf("\n Digite o nome: ");
scanf("%s", fruta[i].nome);
printf("\n Digite a fruta, o sabor e a cor");
scanf("%d %d", &fruta[i].cor, &fruta[i].sabor);
insere_na_lista(fruta, header, i);
}
void insere_na_lista(struct fruteira *fruta, int *header, int i)
{
    int j, antes; 
    j = *header;   // header é sempre o primeiro elemento da lista
    while (j>0 && (strcmp(fruta[j].nome,fruta[i].nome) < 0)) // header maior que zero e a fruta na posicao j vir antes da fruta q colocamos agr
        {
        antes = j;
        j = fruta[j].prox;
        }
    fruta[i].prox = j; // colocamos a fruta atras do j
    if (j == *header) // nao houve alteracao no J, entao o i é o primeiro da lista
        *header = i;
    else
        fruta[antes].prox = i;   // insere a fruta antes do j e depois do antes

}