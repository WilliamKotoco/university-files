#include <stdlib.h>
#include <stdio.h>
#include "lista.c"
#include <string.h>
int main()
{
    lista *list = malloc(sizeof(lista));
    Definir(list);
    int N;
    printf("Quantos dados deseja inserir na lista ?");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        tipo_elem elem;
        printf("\n Digite o nome: ");
        scanf("%s", elem.info.nome);
        printf("\n Digite a idade: ");
        scanf("%d", &elem.info.idade);
        printf("\n Digite a média final: ");
        scanf("%f", &elem.info.media_final);
        Inserir_posic(elem, i, list);
    }

    Imprimir(list);

    tipo_elem teste, teste2, teste3, teste4, teste5;
    teste.info.idade = 90;
    strcpy(teste.info.nome, "asdfkds");
    teste.info.media_final = 4;

    teste2.info.idade = 70;
    strcpy(teste2.info.nome, "velhao");
    teste2.info.media_final = 10;

    teste3.info.idade = 0;
    strcpy(teste3.info.nome, "bebezinho");
    teste3.info.media_final = 9;

    teste4.info.idade = 4387;
    strcpy(teste4.info.nome, "nomezinho");
    teste4.info.media_final = 9;

    teste5.info.idade = 57;
    strcpy(teste5.info.nome, "alooo");
    teste5.info.media_final = 39;
    Inserir_posic(teste, 2, list);
    Inserir_posic(teste5, 3, list);
    printf("\n \n \n");

    Imprimir(list);

    Inserir_ord(teste2, list);
    Inserir_ord(teste3, list);
    Inserir_ord(teste4, list);
    printf("\n \n \n");
    Imprimir(list);
}