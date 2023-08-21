#include <stdio.h>
#include<stdlib.h>
#include "include/register.h"
#include "include/search_id.h"
#include "include/add_elements.h"
#include "include/search_name.h"

int main() {

    int number_elements = 0;
    FILE *read = fopen("qtd.txt", "r");
    if(read != NULL)
    {
        fscanf(read, "%d", &number_elements);
        fclose(read);
    }
    int op;
    printf("[1] for inserting a new register \n"
           "[2] for searching by index"
           "\n [3] for searching by name");
    scanf("%d", &op);
    switch (op)
    {
        case 1:
            add_element(number_elements);
            FILE *write = fopen("qtd.txt", "w");
            fprintf(write, "%d", number_elements + 1);
            break;
        case 2:
            search_by_id(number_elements);
            break;
        case 3:
            search_name(number_elements);
            break;
    }
}
