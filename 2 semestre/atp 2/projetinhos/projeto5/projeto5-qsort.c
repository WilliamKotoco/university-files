#include <stdio.h>
#include <stdlib.h>
struct bigInt
{
    long int high;
    long int low;
};
int main()
{
    FILE *input, *output;
    int i = 0;
    struct bigInt *number;
    number = malloc(20000 * sizeof(struct bigInt));
    input = fopen("bigint.dat", "r");
    while (!feof(input))
    {
        fscanf(input, "%ld", &number[i].high);
         fscanf(input, "%ld", &number[i].low);
        i++;
    }
    printf("%ld ", number[9999].low);


// TUDO CERTO EPRGANOS OS NUMBER
    // quicksort(number, 0,20000 );
    return 0;
}