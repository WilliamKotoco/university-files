#include <stdio.h>
// variaveis globais
int torre[3][20]; // 3 lugar
int k;

// protitpos
int mover(int n, int origem, int indice_origem, int auxiliar, int indice_auxiliar, int dest, int indice_dest);
int main()
{
    int n, i, aux;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        torre[0][i] = n - i;
    }
    mover(n, 0, 0, 1, 0, 2, 0);
    i = 0;
    while (torre[0][i])
        i++;
    if (i == 0)
        printf("0");
    for (aux = i - 1; aux >= 0; aux--)
        printf("%d ", torre[0][aux]);
    printf("\n");
    i = 0;
    while (torre[1][i])
        i++;
    if (i == 0)
        printf("0");
    for (aux = i - 1; aux >= 0; aux--)
        printf("%d ", torre[1][aux]);
    printf("\n");

    i = 0;
    while (torre[2][i])
        i++;
    if (i == 0)
        printf("0");
    for (aux = i - 1; aux >= 0; aux--)
        printf("%d ", torre[2][aux]);
    printf("\n");
    return 0;
}

int mover(int n, int origem, int indice_origem, int auxiliar, int indice_auxiliar, int dest, int indice_dest)
{

    if (k != 0)
    {
        if (n == 1)
        {

            torre[dest][indice_dest] = torre[origem][indice_origem];
            torre[origem][indice_origem] = 0;
            k--;
            return 1;
        }
        else
        {
            mover(n - 1, origem, indice_origem + 1, dest, indice_dest, auxiliar, indice_auxiliar);
            if (k != 0)
            {
                torre[dest][indice_dest] = torre[origem][indice_origem];
                torre[origem][indice_origem] = 0;
                k--;
                mover(n - 1, auxiliar, indice_auxiliar, origem, indice_origem, dest, indice_dest + 1);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}
