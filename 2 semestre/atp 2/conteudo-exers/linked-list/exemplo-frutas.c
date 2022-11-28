
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct fruta
{
    char nome[40];
    int cor;
    int sabor;
    float peso;
    struct fruta *prox; // ponteiro para a proxima fruta
};
struct fruta *leArquivo(struct fruta *head);
struct fruta *preencheFruta(char *);
struct fruta *insereLista(struct fruta *, struct fruta *);
struct fruta *buscaFruta(struct fruta *, char *);
struct fruta *removeFruta(struct fruta *, char *);
void salvarMudancas(struct fruta *);
int main()
{
    char fruta[40];
    int op;
    struct fruta *cadastro, *novafruta, *pointer;
    cadastro = NULL; // inicializa vazio o ponteiro
    cadastro = leArquivo(cadastro);
    printf("1- cadastro, 2- busca, 3- remocao: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\n Digite o nome da fruta: ");
        scanf("%s", fruta);
        novafruta = preencheFruta(fruta);
        cadastro = insereLista(cadastro, novafruta);
        break;
    case 2:
        printf("\n Digite o nome da fruta: ");
        scanf("%s", fruta);
        pointer = buscaFruta(cadastro, fruta);
        printf("\n a fruta %s esta no endereco de memoria %p", fruta, pointer);
        break;
    case 3:
        printf("\n Digite o nome da fruta: ");
        scanf("%s", fruta);
        removeFruta(cadastro, fruta);
        break;
    }
    salvarMudancas(cadastro);

    return 0;
}
struct fruta *leArquivo(struct fruta *head) // head é o primeiro elemento da lista, que vc vai colocar no cadastro
{
    FILE *fp;
    struct fruta *aux;
    char nome_fruta[40];
    fp = fopen("frutas.dat", "r");
    fscanf(fp, "%s", nome_fruta); // começa a ler o arquivo
    while (!feof(fp))
    {
        aux = malloc(sizeof(struct fruta));
        aux->prox = NULL; // ta colocando na lista sem se importar com a ordenacao
        strcpy(aux->nome, nome_fruta);
        fscanf(fp, "%d %d %f", &aux->cor, &aux->sabor, &aux->peso);
        head = insereLista(head, aux);
        fscanf(fp, "%s", nome_fruta);
    }
    if (head == NULL)
    {
        printf("\n Arquivo veio vazio");
    }
    fclose(fp);
    return head;
}
struct fruta *preencheFruta(char *name)
{
    struct fruta *fruta;
    strcpy(fruta->nome, name);
    printf("\n Digite a cor, o sabor e o peso");
    scanf("%d %d %f", &fruta->cor, &fruta->sabor, &fruta->peso);
    return fruta;
}
struct fruta *insereLista(struct fruta *inicio, struct fruta *novafruta)
{
    // ja insere ordennando
    struct fruta *aux, *antes;
    // retorna ponteiro pro primeiro elemento da lista, mas funciona quase igual a um void. Serve so para ordenar
    if (inicio == NULL)
    {
        inicio = novafruta;
        return inicio;
    }
    aux = antes = inicio;                                           // todos começam apontando para o mesmo lugar
    while (aux != NULL && (strcmp(aux->nome, novafruta->nome) < 0)) // verifica se aux precede
    {
        antes = aux;
        aux = aux->prox;
    }
    // achou o lugar de insercao
    if (aux == inicio)
    {
        novafruta->prox = inicio;
        inicio = novafruta;
    }
    else
    {
        novafruta->prox = aux;
        antes->prox = novafruta;
    }
    return inicio;
}
struct fruta *buscaFruta(struct fruta *header, char *nome)
{
    struct fruta *aux, *antes;
    header->prox = aux;
    if (header == NULL)
    {
        printf("\n Nao tem nenhum elemento na lista");
    }
    if (strcmp(header->nome, nome) == 0)
        return header;
    while (strcmp(aux->nome, nome) != 0)
    {
        antes->prox = aux;
        aux = aux->prox;
    }
    return aux;
}
struct fruta *removeFruta(struct fruta *ward, char *nomeFruta) // ward tambem é um nome para head
{
    struct fruta *aux, *antes;
    aux = antes = ward;
    while (aux->prox != NULL && (strcmp(aux->nome, nomeFruta) < 0)) // verifica se aux está antes da fruta
    {
        aux = aux->prox;
        antes->prox = aux;
    }
    if (strcmp(nomeFruta, aux->nome) == 0)
    {
        if (aux != ward)
            antes->prox = aux->prox; // retira o campo ponteiro do aux para nao tornar os outros inacessiveis
        else
            ward = aux->prox; // aux é o primeiro da lista, entao o ward vai se tornar o aux e a ward antiga vai morrer
        free(aux);
    }
    else
        printf("\n fruta nao esta na lista");
    return ward;
}
void salvarMudancas(struct fruta *ward)
{
    FILE *fp;
    struct fruta *aux;
    aux = ward;
    fp = fopen("frutas.dat", "w");
    while (ward != NULL)
    {
        fprintf(fp, "%s %d %d %f \n", aux->nome, aux->cor, aux->sabor, aux->peso);
        ward = aux->prox; // a ward sempre aponta para o primeiro da lista. Estamos salvado do primeiro para o ulimo
        free(aux);
        aux = ward;
    }
    fclose(fp);
}