// Crie uma func¸ao que receba como par ˜ ametro um array e o imprima. N ˆ ao utilize ˜ ´ındices
// para percorrer o array, apenas aritmetica de ponteiros.
#include <stdio.h>
void percorrer_array(int array[]);
int main()
{
    int array[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &array[i]);
    }
    percorrer_array(array);
}
void percorrer_array(int array[])
{
    while (*array != NULL)
    {

        printf("%d ", *array);
        *(array)++;
    }
}