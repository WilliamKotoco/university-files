#include "../include/register.h"
#include "../include/search_id.h"

struct register_file search_by_id()
{
FILE *fp = fopen("../register.bin", "r");
struct register_file person;

    fread(&person, sizeof(struct register_file), 1,fp );

    printf("%s", person.name);
}
