/*
Guardando a posição em que ocorreu a troca, podemos verificar se o novo vetor vai ser menor doq
o daquele lugar. Se for maior, temos um novo ponto de início para a bolha
*/
#define qtd 5
#include <stdio.h>
int main()
{
    int i, j, aux, trocou = 1, array[qtd], k;
    j = qtd, k = 0;
    while (trocou)
    {
        // inicializa
        aux = array[0];
        trocou = 0;
        for (i = 1; i < j; i++)
        {
            if (array[i] > array[k])
            {
                i = k;
            }
            if (array[i] < aux)
            {

                array[i - 1] = array[i];
                trocou = 1;
                k = i;
            }
            else
            {
                array[i - 1] = aux;
                aux = array[i];
            }
        }

        array[i - 1] = aux; // ultimo elemento
        j--;
    }

    return 0;
}
