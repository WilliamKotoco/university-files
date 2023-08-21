#include "search_name.h"
#include <string.h>
void search_name(int n)
{
    char name[40];
    FILE *fp = fopen("index_name.bin", "rb");
    struct index_name_file elements[n];
    fread(elements, sizeof(struct index_name_file), n, fp);

    // for (int i = 0 ; i < n; i++)
    //     printf("%s \n", elements[i].name);
    fflush(fp);
    fclose(fp);
    printf("Digit the name for searching: ");
    scanf("%s", name);

    int index = binary_search_name(elements, n, name);
    if(index == -1){
        puts("Element not found, exiting...");
        exit(0);
    }

    long int position = prepare_binary_search_id(index, n);
    /// if it's found in the name's file there's no need to double check the existence

  FILE *found = fopen("register.bin", "rb");
    fseek(found, position, SEEK_CUR);

    struct register_file element;
    fread(&element, sizeof(struct register_file), 1, fp);

    printf("Name: %s", element.name);
    printf("\n Age: %d", element.age);
    printf("\n Money: %lf", element.money);
    fclose(found);
}
 int binary_search_name(struct index_name_file *array, int n, char *name)
{
 int left = 0;
 int right = n - 1;

 while (left <= right)
 {
    int mid = left + (right - left)/2;

    int result = strcmp(name, array[mid].name);
    if (result == 0)
        return array[mid].index;
    if (result < 0)
        right = mid -1;
    else
        left = mid + 1;

 }
 return -1;
}