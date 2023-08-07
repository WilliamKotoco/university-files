
/*
A lista estática trabablha da mesma maneira que a lista dinâmica, mas dessa vez usando vetores
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
int buscar_fruta(struct fruteira *fruta, int *header);
int buscar_na_lista(struct fruteira *fruta, char *nome, int *header);
void remove_frutas(struct fruteira *fruta, int *header);
void remover_na_lista(struct fruteira *fruta, int *header, char *nome);
void imprimir_frutas(struct fruteira *fruta, int header);

int main()
{
/*
Temos que lembrar que pouco importa a ordem dos indices, entao podemos ter head sendo no
indice 4 por exemplo

para os elementos que não estão sendo usados, colocaremos -1 para tratar.
*/
struct fruteira *frutas;
frutas = malloc(20 * sizeof(struct fruteira));
int op, flag = 0;
int header = -1;
while (flag == 0)
{
printf("\n Digite a opcao ");
scanf("%d", &op);
switch (op)
{
    case 1:
        inicializar(frutas);  //inicializa todos os indicex prox como -1
        add_fruta(frutas, &header);
        printf("\n Fruta adicionada com sucesso");    
        break; 
    case 2:
        printf("A Fruta está no indice %d",buscar_fruta(frutas, &header));
        break;
    case 3:
        remove_frutas(frutas, &header);
        printf("\n remocao feita com sucesso ");
    case 4:
        imprimir_frutas(frutas, header);
    default:
        flag = 1;

}
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
    int i = 0;
    while (fruta[i].prox != -1 && i < 20)
        i++; // pega o primeiro lugar disponivel para adicionar a fruta
    if (i == 19)
        return;   // lista ta cheia, vamos só retornar nulo

printf("\n Digite o nome: ");
scanf("%s", fruta[i].nome);
printf("\n Digite o sabor e a cor: ");
scanf("%d %d", &fruta[i].cor, &fruta[i].sabor);
insere_na_lista(fruta, header, i);
}
void insere_na_lista(struct fruteira *fruta, int *header, int i)
{
    int j, antes; 
    j = *header;   // header é sempre o primeiro elemento da lista
    while (j > 0 && (strcmp(fruta[j].nome,fruta[i].nome) < 0)) // j apontar para algo e a fruta na posicao j vir antes da fruta q colocamos agr
        {
        antes = j;
        j = fruta[j].prox;
        }
    fruta[i].prox = j; // colocamos a fruta atras do j
    if (j == *header) // nao houve alteracao no J, entao o i é o primeiro da lista
        *header = i;
    else
        fruta[antes].prox = i;   // insere a fruta antes do j e depois do antes
    printf("\n %d", fruta[i].prox);
}

int buscar_fruta(struct fruteira *fruta, int *header)
{
    int retorno;
    char nome[40];
    printf("\n Digite o nome da fruta: ");
    scanf( "%s", nome);
    retorno = buscar_na_lista(fruta, nome, header);
    return retorno;
}
int buscar_na_lista(struct fruteira *fruta, char *nome, int *header)
{
    printf("\n %d", *header);
    int counter = 0, j = *header, antes;
    int endereco;
    while (strcmp(fruta[j].nome, nome) != 0 && counter < 20)
        {
            antes = j;
            j = fruta[j].prox; // vai movimentando na lista
            counter++;
        }
    if (counter == 20 &&  strcmp(fruta[j].nome, nome) != 0)
        return -1;
    else
        {
            if (j == *header)
                return 1; // nesse caso vai indicar que é o primeiro
            else
            {
                endereco = fruta[antes].prox;
                return endereco;
            }
            
        }
    
}
void remove_frutas(struct fruteira *fruta, int *header)
{
    char nome[40];
    printf("Digite o nome da fruta: ");
    scanf("%s", nome);
    remover_na_lista(fruta, header, nome);
}
void remover_na_lista(struct fruteira *fruta, int *header, char *nome)
{
    // printf("\n a");
    int counter = 0, j = *header, antes;
    while(counter < 20 && strcmp(fruta[j].nome, nome) != 0)
    {
        antes = j;
        j = fruta[j].prox;
    }
 if (counter == 20 &&  strcmp(fruta[j].nome, nome) != 0)
    {
        printf("Fruta nao encontrada");
        return;
    }
    fruta[antes].prox = fruta[j].prox; // a fruta anterior vai apontar para o proximo da fruta j, visto que vamos remover a fruta j
    
        if (j == *header)
        {
            *header = fruta[j].prox;  // caso o j sera o header, precisaremos alocar um novo header apontando para o começo da lista
        }
        fruta[j].prox = -1; // alocar como -1 é a remocao de uma lista estatica
        printf("\n b");

}
void imprimir_frutas(struct fruteira *fruta, int header)
{
    int j = header;
   while(fruta[j].prox != -1)
    {
    printf("%s \n", fruta[j].nome);
    j = fruta[j].prox;
    }
    // o ta sempre imprimindo o header de primeira, mas fica preso no loop sem sair
}


/*
o header ta realmente sempre apontando para o primeiro da lista, o que está dando merda é nos indices prox
*/