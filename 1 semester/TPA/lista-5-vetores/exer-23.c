/*
Escreva um programa em linguagem C para que usuário digite um nome e um sobrenome,
sendo esses armazenados em variáveis nome e sobrenome, respectivamente. As strings têm
tamanhos máximos de 40 caracteres. Em seguida, o programa deve percorrer as strings,
concatenar as entradas e armazenar o resultado em uma string nomeada resultado,
declarada com tamanho 80. Ao final, o programa deverá apresentar o resultado da
concatenação com o total de algarismos existentes.
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char nome[40], sobrenome[40], resultado[80];
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("\n Digite o sobrenome: ");
    scanf("%s", sobrenome);
    nome[strlen(nome) + 1] = " ";
    strcat(resultado, nome);
    strcat(resultado, " ");
    strcat(resultado, sobrenome);
    printf("\n %s", resultado);

    printf("\n Ha  %d letras no nome total: ", strlen(resultado) - 1);
    return 0;
}