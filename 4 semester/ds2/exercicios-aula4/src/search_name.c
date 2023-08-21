#include "search_name.h"

void search_name(int n)
{
    FILE *fp = fopen("index_name.bin", "rb");
    struct index_name_file elements[n];
    fread(elements, sizeof(struct index_name_file), n, fp);

    for (int i = 0 ; i < n; i++)
        printf("%s \n", elements[i].name);
}