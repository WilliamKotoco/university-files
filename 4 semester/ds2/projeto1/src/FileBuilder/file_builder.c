#include "../../include/FileBuilder/file_builder.h"
#include "../../include/Search/search_manager.h"
#include "../../include/Search/binary_search.h"

extern int g_total_elements;
extern int g_free_space;
extern struct movie_index_id *index_id;
extern struct movie_index_name  *index_name;

void write_index_id_file() {

    FILE *fp = fopen(PRIMARY_KEY_FILE, "w");
    fprintf(fp, "%d %c ", g_total_elements, '0');
    for (int i = 0; i < g_total_elements; i++) {
        fprintf(fp, "%s %lu ", index_id[i].id, index_id[i].byte_offset);
    }

    fclose(fp);

}

void write_index_name_file() {


    FILE *fp = fopen(SECONDARY_KEY_FILE, "w");
    for (int i = 0; i < g_total_elements; i++) {
        fputs(index_name[i].name, fp);
         fputc('@', fp);
        fputs(index_name[i].id, fp);
        fputc('@', fp);
    }

    fclose(fp);
}

void append_movies_file(struct movie new_data) {
    FILE *fp = fopen(MAIN_FILE, "a");
    fputs(new_data.id, fp);
    fputc(SEPARATOR, fp);
    fputs(new_data.translated_name, fp);
    fputc(SEPARATOR, fp);
    fputs(new_data.name, fp);
    fputc(SEPARATOR, fp);
    fputs(new_data.director, fp);
    fputc(SEPARATOR, fp);
    fputs(new_data.year, fp);
    fputc(SEPARATOR, fp);
    fputs(new_data.country, fp);
    fputc(SEPARATOR, fp);
    fputc(new_data.mark, fp);

    long int used_space = ftell(fp);
    int needspace = (REGISTER_SIZE * g_total_elements) - used_space;
    for (int i = 0; i < needspace; i++)
        fputc('#', fp);

    fclose(fp);
}

void remove_movie_file(long byte_offset) {
    FILE *fp = fopen(MAIN_FILE, "r+");
    fseek(fp, byte_offset, SEEK_SET);
    fputs("*|", fp);
    fclose(fp);
}

void update_mark_movie_file(long byte_offset, char new_mark) {
    FILE *fp = fopen(MAIN_FILE, "r+");
    fseek(fp, byte_offset, SEEK_SET);

    char c;
    while((c = fgetc(fp)) != EOF && c != '#');
    fseek(fp, -2, SEEK_CUR);
     fputc(new_mark, fp);


}

void rebuild_index_file()
{

    FILE *fp = fopen(MAIN_FILE, "r");
    fseek(fp, 0, SEEK_END);
    int size = (ftell(fp))/REGISTER_SIZE;
    rewind(fp);
    index_id = malloc(sizeof(struct movie_index_id) * size);
    index_name = malloc(sizeof(struct movie_index_name) * size);
    int last_not_removed = 0;
    for (int i = 0; i < size; i++ )
    {
        char line[REGISTER_SIZE + 1];
        fgets(line, REGISTER_SIZE + 1, fp);
        char *token = strtok(line, "@");
        if (token[0] == '*')
            continue;
        strcpy(index_id[last_not_removed].id, token);
        strcpy(index_name[last_not_removed].id, token);
        index_id[last_not_removed].byte_offset = i *REGISTER_SIZE;
        token = strtok(NULL, "@");
        strcpy(index_name[last_not_removed].name, token);
        last_not_removed++;

    }
    g_total_elements = last_not_removed;
}

void file_compreesion()
{

    FILE *fp = fopen(TMP_FILE, "w");

    for (int i =0; i < g_total_elements; i++)
    {
        struct movie data = get_element_data(index_id[i].byte_offset);
        fputs(data.id, fp);
        fputc(SEPARATOR, fp);
        fputs(data.translated_name, fp);
        fputc(SEPARATOR, fp);
        fputs(data.name, fp);
        fputc(SEPARATOR, fp);
        fputs(data.director, fp);
        fputc(SEPARATOR, fp);
        fputs(data.year, fp);
        fputc(SEPARATOR, fp);
        fputs(data.country, fp);
        fputc(SEPARATOR, fp);
        fputc(data.mark, fp);

        long int used_space = ftell(fp);
        int needspace = (REGISTER_SIZE * (i+1)) - used_space;
        for (int i = 0; i < needspace; i++)
            fputc('#', fp);
    }
    remove(MAIN_FILE);
    remove(PRIMARY_KEY_FILE);
    remove(SECONDARY_KEY_FILE);
    rename(TMP_FILE, MAIN_FILE);



}
