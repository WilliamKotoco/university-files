#include <stdio.h>
#include <stdlib.h>
struct bigInt
{
    long int high;
    long int low;
};
void insertion (struct bigInt *number);
int main()
{
    FILE *input, *output;
    int i = 0;
    struct bigInt *number;
    number = malloc(200000 * sizeof(struct bigInt));
    input = fopen("bigint.dat", "r");
    do
    {
        fscanf(input, "%ld", &number[i].high);
         fscanf(input, "%ld", &number[i].low);
        i++;
    }while(!feof(input));
    fclose(input);
    fflush(input);
    insertion(number);
    output = fopen("quick.dat", "w");
    for (i = 0; i < 200000; i++)
        fprintf(output, "%ld %ld \n", number[i].high, number[i].low);
    fclose(output);
    
    return 0;
}
void insertion (struct bigInt *number)
{
 int i, j;
 struct bigInt aux;
    for (i = 1; i < 200000; i++)
    {
        aux =  number[i];
        j = i;
        while(j > 0 && (
        (number[j-1].high > aux.high) || 
        (aux.high == number[j-1].high && number[j-1].low > aux.low) || 
        (aux.high == number[j-1].high && aux.high < 0 && number[j-1].low < aux.low )))
            { number[j] = number[j-1]; 
            j--; 
            }
            number[j] = aux;
    }
}
