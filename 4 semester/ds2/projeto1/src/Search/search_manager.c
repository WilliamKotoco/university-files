#include "../../include/Search/search_manager.h"
extern int g_total_elements;
extern struct movie_index_id *index_id;
extern struct movie_index_name  *index_name;

void search_by_id( char *id){

    int index = binary_search_id(index_id, id, 0, g_total_elements - 1);

    if (index == -1)
    {
        printf("ID %s não cadastrado.", id);
        return ;
    }
  struct movie raw_data =  get_element_data(index_id[index].byte_offset);

    /// changes color of output to be yellow just for being more readable.
    printf("\n \x1b[33m" "Dados do filme buscado" "\x1b[0m \n");
    printf(
           "Nome.............: %s \n"
           "Nome original....: %s \n"
           "Diretor..........: %s \n"
           "Ano de lançamento: %s \n"
           "País de origem...: %s \n"
           "Nota:............: %c \n",
           raw_data.translated_name, raw_data.name, raw_data.director, raw_data.year
           ,raw_data.country, raw_data.mark);

}

struct movie get_element_data(long int byteoffset)
{
    struct movie raw_data;
    FILE *fp = fopen(MAIN_FILE, "r");
    fseek(fp, byteoffset, SEEK_SET);
    char line[REGISTER_SIZE + 1];
    fgets(line, REGISTER_SIZE + 1, fp);

    char *token = strtok(line, "@");
    strcpy(raw_data.id, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.translated_name, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.name, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.director, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.year, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.country, token);
    token = strtok(NULL, "@");
    raw_data.mark = *token;

    fclose(fp);
    return raw_data;

}

void search_by_name( char *name)
{

    int lower = -1;
    int upper = -1;

    int ocurrences = binary_search_name(index_name, name, &lower, &upper);

    if (lower == -1)
    {
        printf("O filme %s não foi cadastrado \n", name);
        return;
    }
    for (int i = lower; i <= upper; i++)
        search_by_id( index_name[i].id);
}

