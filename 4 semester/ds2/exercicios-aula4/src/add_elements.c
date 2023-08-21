

#include "../include/add_elements.h"
#include "../include/register.h"

/// reads the file and add a new element
void add_element(int number_elements) {
    FILE *fp = fopen("register.bin", "ab");
    if (fp == NULL) {
        printf("File does not exist");
        exit(0);
    }

    struct register_file element;
    printf("Name: ");
    scanf("%49s", element.name);
    printf("\n Money: ");
    scanf("%lf", &element.money);
    printf("Age: ");
    scanf("%d", &element.age);


    /// using fwrite because it writes an entire buffer into the file
    /// reducing the number of disk acess
    fwrite(&element, sizeof(struct register_file), 1, fp);
    ///  goes to the end of the file to get the location.

    fseek(fp, 0, SEEK_END);
    long byte_offset = ftell(fp);
    fclose(fp);

    add_index_files(byte_offset, number_elements, element.name);

}

void add_index_files(long int byte_offset, int number_elements, char *name) {
    FILE *fp = fopen("index_file.bin", "ab");

    struct index_register_file index_file_element;
    index_file_element.index = number_elements ;
    index_file_element.byte_offset = byte_offset;
    fwrite(&index_file_element, sizeof(struct index_register_file), 1, fp);
    fclose(fp);

    FILE *fp2 = fopen("index_name.bin", "ab");

    struct index_name_file name_file_element;
    strcpy(name_file_element.name, name);
    name_file_element.index = number_elements;

    fwrite(&name_file_element, sizeof(struct index_name_file), 1, fp2);

    fclose(fp2);

    update_name_file(number_elements);


}
void update_name_file(int n)
{
    FILE *fp = fopen("index_name.bin", "rb");
    fflush(stdin);
    fflush(fp);
    struct index_name_file elements[n];
    fread(elements, sizeof(struct index_name_file), n, fp);
    fclose(fp);

    /// insertion sort
     for (int i = 1; i < n; ++i) {
        struct index_name_file key = elements[i];
        int j = i - 1;
        while (j >= 0 && strcmp(elements[j].name, key.name) > 0) {
            elements[j + 1] = elements[j];
            j = j - 1;
        }
        elements[j + 1] = key;
    }
    
     FILE *write = fopen("index_name.bin", "wb");
     fwrite(elements, sizeof(struct index_name_file), n, write);
     fclose(write);
}