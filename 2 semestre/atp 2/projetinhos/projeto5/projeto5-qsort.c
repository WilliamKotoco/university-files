#include <stdio.h>
#include <stdlib.h>
struct bigInt
{
    int high;
    int low;
};
void quicksort(struct bigInt *number,int low, int high);
int mediana(struct bigInt *number, int low, int mid, int high);
void swap(struct bigInt *a, struct bigInt *b);


int main()
{
    FILE *input, *output;
    int i = 0;
    struct bigInt number [200000];
    input = fopen("bigint.dat", "r");
    do
    {
        fscanf(input, "%d", &number[i].high);
        fscanf(input, "%d", &number[i].low);
        i++;
    }while(!feof(input));

    fclose (input);
    fflush (input);

    quicksort(number, 0,i - 2);

    output = fopen ("quick.dat", "w");
    
    for (int j = 0; j < i-1; j++)
        fprintf(output, "%d %d\n", number[j].high, number[j].low);

    fclose (output);

    return 0;
}
void quicksort(struct bigInt *number, int low, int high)
{
    int i = 0, pivo, bigger;
    if (low < high)
    {
        pivo = mediana(number, low, (low+high)/2, high);
        swap(&number[pivo], &number[high]);
        bigger = low;
        for (i = bigger; i < high; i++)
        {
            if((number[i].high < number[high].high) ||
            (number[i].high == number[high].high && number[i].low < number[high].low) ||
            (number[i].high == number[high].high && number[i].high < 0 && number[i].low > number[high].low) )
            {
                swap(&number[i], &number[bigger]);
                bigger++;
            }
         
        }

        swap (&number[high], &number[bigger]);
        quicksort(number, low, bigger-1);
        quicksort(number, bigger+1, high);
    }

}

void swap(struct bigInt *a, struct bigInt *b)
{
    struct bigInt aux;
    aux = *a;
    *a = *b;
    *b = aux; 
}

int mediana(struct bigInt *number, int low, int mid, int high)
{
    if ((number[low].high <= number[mid].high && number[mid].high <= number[high].high) || 
        (number[low].high >= number[mid].high && number[mid].high >= number[high].high))
        return mid;

    else if((number[mid].high >= number[low].high && number[low].high >= number[high].high) || 
            (number[high].high >= number[low].high && number[low].high >= number[mid].high))
        return low;
    
    return high;
    
}