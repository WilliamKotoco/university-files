#include "../include/register.h"
#include "../include/search_id.h"

void search_by_id(int total_elements)
{
    int id;
    printf("Digit the id for searching");
    scanf("%d", &id);

   long int byte_offset = prepare_binary_search(id, total_elements);

    if(byte_offset == -1 )
    {
        printf("Element does not exist");
        exit(0);
    }
    
    FILE *fp = fopen("register.bin", "rb");
    fseek(fp, byte_offset, SEEK_CUR);

    struct register_file element;
    fread(&element, sizeof(struct register_file), 1, fp);

    printf("Name: %s", element.name);
    printf("\n Age: %d", element.age);
    printf("\n Money: %lf", element.money);
 }

long int prepare_binary_search(int id, int total_elements)
{
    FILE *fp = fopen("index_file.bin", "rb");

    struct index_register_file elements[total_elements];

    fread(elements, sizeof(struct index_register_file), total_elements, fp);

   
    return binary_search(elements, id, 0, total_elements);
}

long int binary_search(struct index_register_file *elements, int id, int left, int right)
{

    int mid = (right + left) / 2;
    if (left > right)
        return -1;

    if (elements[mid].index == id)
        return elements[mid].byte_offset;
    else if (elements[mid].index > id)
        return binary_search(elements, id, left, mid - 1);
    else
        return binary_search(elements, id, mid + 1, right);
}
