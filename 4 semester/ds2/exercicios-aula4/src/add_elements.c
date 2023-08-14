

#include "../include/add_elements.h"
#include "../include/register.h"
/// reads the file and add a new element
void add_element()
{
    FILE *fp = fopen("../register.bin", "a");
    if (fp == NULL)
    {
        printf("File does not exist");
        exit(0);
    }

    struct register_file element;
    printf("Name: ");
    scanf("%s", element.name);
    printf("\n Money: ");
    scanf("%lf", &element.money);
    printf("Age: ");
    scanf("%d", &element.age);


    /// using fwrite because it writes an entire buffer into the file
    /// reducing the number of disk acess
    fwrite(&element, sizeof(struct register_file), 1, fp);
    ///  goes to the end of the file to get the location.

    fseek(fp, SEEK_END, 0);
    long byte_offset = ftell(fp);
    fclose(fp);

    add_index_files(byte_offset);

}

void add_index_files(long int byte_offset)
{
FILE *fp = fopen("index_file.bin", "a+");
int highest_id;
fscanf(fp, "%d", &highest_id);
rewind(fp);
fprintf(fp, "%d", highest_id + 1);
struct index_register_file element;
element.index = highest_id + 1;
element.byte_offset = byte_offset;

fwrite(&element, sizeof(struct index_register_file),1, fp);
fclose(fp);

FILE *fp fopen("index_name.bin", "a");




}