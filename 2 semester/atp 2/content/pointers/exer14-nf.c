// Crie uma func¸ao que receba dois parametros: um array e um valor do mesmo tipo do
// array. A func¸ao devera preencher os elementos de array com esse valor. Nao utilize ˜
// ´ındices para percorrer o array, apenas aritmetica de ponteiros.
#include <stdio.h>
void preencher(int array[], int valor);
int main()
{
    int array[5], valor;
    scanf("%d", &valor);
    preencher(array, valor);
    for (int i = 0; i < 5; i++)
    {
        printf("\n %d", array[i]);
    }
    return 0;
}
// cria um ponteiro, ir incrementando o ponteiro até ele apontar para nulo"
void preencher(int array[], int valor)
{

    while (*array != NULL)
    {
        *array = valor;
        printf("\n %p", array);
        *(array)++;
    }
}