#include "../../include/FileBuilder/file_builder.h"
#include "../../include/Search/binary_search.h"
#include "../../include/Search/search_manager.h"
#include <stdio.h>

extern int g_total_elements;
extern int g_free_space;
extern struct b_node* g_buffer;
extern int g_root;
extern struct movie_index_name* index_name;
extern int g_num_nodes;
void write_index_id_file()
{

    FILE* fp = fopen(PRIMARY_KEY_FILE, "r+");
    long int where = g_buffer->RRN * B_TREE_NODE_SIZE;
    fseek(fp, where, SEEK_SET);
    fprintf(fp, "%d %d %d ", g_buffer->is_leaf, g_buffer->RRN, g_buffer->numkeys);
    for (int i = 0; i < ORDER + 1; i++)
        fprintf(fp, "%s ", g_buffer->ID[i]);

    for (int i = 0; i < ORDER + 1; i++)
        fprintf(fp, "%d ", g_buffer->keys_RRNS[i]);
    for (int i = 0; i < ORDER + 2; i++)
        fprintf(fp, "%d ", g_buffer->children[i]);
    fprintf(fp, "%d ", g_buffer->parent);
    fprintf(fp, "%d ", g_buffer->next_node);
    int size = (where + B_TREE_NODE_SIZE) - ftell(fp);
    for (int i = 0; i < size - 1; i++)
        fputc('#', fp);
    fputc(' ', fp);
    fclose(fp);
}

void write_index_name_file()
{

    FILE* fp = fopen(SECONDARY_KEY_FILE, "w");
    fprintf(fp, "%d %d %d ", g_total_elements, g_root, g_num_nodes);
    for (int i = 0; i < g_total_elements; i++) {
        fputs(index_name[i].name, fp);
        fputc('@', fp);
        fputs(index_name[i].id, fp);
        fputc('@', fp);
    }

    fclose(fp);
}

void append_movies_file(struct movie new_data)
{
    FILE* fp = fopen(MAIN_FILE, "a");
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

void remove_movie_file(long byte_offset)
{
    FILE* fp = fopen(MAIN_FILE, "r+");
    fseek(fp, byte_offset, SEEK_SET);
    fputs("*|", fp);
    fclose(fp);
}

void update_mark_movie_file(long byte_offset, char new_mark)
{
    FILE* fp = fopen(MAIN_FILE, "r+");
    fseek(fp, byte_offset, SEEK_SET);

    char c;
    while ((c = fgetc(fp)) != EOF && c != '#')
        ;
    fseek(fp, -2, SEEK_CUR);
    fputc(new_mark, fp);
    fclose(fp); /// AHAHAHAHAHAHAHAHA TOME
}

void rebuild_index_file()
{

    FILE* fp = fopen(MAIN_FILE, "r");
    fseek(fp, 0, SEEK_END);
    int size = (ftell(fp)) / REGISTER_SIZE;
    rewind(fp);
    index_name = malloc(sizeof(struct movie_index_name) * size);
    int last_not_removed = 0;
    for (int i = 0; i < size; i++) {
        char line[REGISTER_SIZE + 1];
        fgets(line, REGISTER_SIZE + 1, fp);
        char* token = strtok(line, "@");
        if (token[0] == '*')
            continue;
        strcpy(index_name[last_not_removed].id, token);
        token = strtok(NULL, "@");
        strcpy(index_name[last_not_removed].name, token);
        last_not_removed++;
    }
    g_total_elements = last_not_removed;
}

void print_id()
{
    for (int i = 0; i < 5; i++)
        printf("%s ", g_buffer->ID[i]);
}

void insertion_sort_id()
{
    int i, j;
    char tmp_id[ID_SIZE];
    int tmp_key;
    int tmp_child;
    for (i = 0; i < ORDER + 1; i++) {
        strcpy(tmp_id, g_buffer->ID[i]);
        tmp_child = g_buffer->children[i];
        tmp_key = g_buffer->keys_RRNS[i];
        j = i - 1;

        while (j >= 0 && strcasecmp(g_buffer->ID[j], tmp_id) > 0) {
            strcpy(g_buffer->ID[j + 1], g_buffer->ID[j]);

            /// swap other arrays due the necessity to synchronize the indices
            g_buffer->keys_RRNS[j + 1] = g_buffer->keys_RRNS[j];
            g_buffer->children[j + 1] = g_buffer->children[j];

            j = j - 1;
        }

        strcpy(g_buffer->ID[j + 1], tmp_id);
        g_buffer->children[j + 1] = tmp_child;
        g_buffer->keys_RRNS[j + 1] = tmp_key;
    }
}
