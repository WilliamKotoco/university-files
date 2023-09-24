#include "../../include/FileReader/file_reader.h"
#include "../../include/FileBuilder/file_builder.h"
#include "../../include/DataProcessing/data_processor.h"
extern int g_total_elements;
extern struct movie_index_id *index_id;
extern struct movie_index_name *index_name ;
void read_file_index_id() {

    FILE *fp = fopen(PRIMARY_KEY_FILE, "r+");
    if (fp == NULL)
        return;

    struct flags *flag = read_flags_from_file(fp);
    if (flag->status_flag == '1') {
         rebuild_index_file();
        insertion_sort_id(index_id, g_total_elements);
        insertion_sort_name(index_name, g_total_elements);
         return;
    }

    index_id = malloc(sizeof(struct movie_index_id) * flag->qtd);

    unsigned i = 0;
    /// @todo fscanf do not report conversion erros, it's not safe reading
    /// types other than string in fscanf. Consider using strtol in case of errors.

    for (i = 0; i < g_total_elements; i++) {
        fscanf(fp, "%s %ld", index_id[i].id, &index_id[i].byte_offset);
    }

    rewind(fp);
    fprintf(fp, "%d %c", g_total_elements, '1');
    fclose(fp);
    free(flag);
    read_file_index_name();


}

void read_file_index_name() {
    FILE *fp = fopen(SECONDARY_KEY_FILE, "r");

    if (fp == NULL)
        return;

     index_name = malloc(sizeof(struct movie_index_name) * g_total_elements);
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    char registro[size];

    fgets(registro, size, fp);
    fclose(fp);

    int i = 0;
    char *token = strtok(registro, "@");

    while (token != NULL) {
        strcpy(index_name[i].name, token);
        token = strtok(NULL, "@");
        strcpy(index_name[i].id, token);
        token = strtok(NULL, "@");
        i++;
    }

}



struct flags *read_flags_from_file(FILE *fp) {

    struct flags *flag = malloc(sizeof(struct flags));
    fscanf(fp, "%d %c", &flag->qtd, &flag->status_flag);
    g_total_elements = flag->qtd;
    return flag;
}
