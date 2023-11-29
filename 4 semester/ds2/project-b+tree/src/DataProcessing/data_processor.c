#include "../../include/DataProcessing/data_processor.h"
#include "../../include/SplitManager/split_manager.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

extern int g_total_elements;
extern int g_free_space;

extern int g_num_nodes;
extern int g_root;
extern struct movie_index_name* index_name;
extern struct b_node* g_buffer;

uint insertion_data_processing(struct movie raw_data)
{
    /// the first movie was recorded in 1888, therefore there are no movies before
    /// it.
    if (atoi(raw_data.year) < 1888) {
        puts("Não existe nenhum filme antes de 1888");
        return 0;
    }

    if (strcasecmp(raw_data.translated_name, "idem") == 0)
        strcpy(raw_data.translated_name, raw_data.name);

    g_total_elements++;

    format_directors_name(raw_data.director);
    create_movie_id(raw_data.director, raw_data.year, raw_data.id);

    bool query = add_new_index_id(raw_data.id);
    if (query == false) {
        puts("Já existe um registro com esse ID, por favor tente novamente.");
        return 0;
    }
    index_name = add_new_index_name(index_name, raw_data.translated_name, raw_data.id);

    write_index_name_file();
    append_movies_file(raw_data);
    free(g_buffer);
    return 1;
}

void format_directors_name(char* name)
{
    char first_name[NAME_SIZE / 2];
    char last_name[NAME_SIZE / 2];
    // separate the name in first name and surname
    char* token = strtok(name, " ");
    strcpy(first_name, token);
    token = strtok(NULL, "");
    strcpy(last_name, token);
    char formmated_name[NAME_SIZE];

    /// sprintf sends the formatted output to a string.
    sprintf(formmated_name, "%s, %s", last_name, first_name);
    strcpy(name, formmated_name);
}

void create_movie_id(char* director_name, char* year, char* id)
{
    id[0] = toupper(director_name[0]);
    id[1] = toupper(director_name[1]);
    id[2] = toupper(director_name[2]);
    id[3] = year[YEAR_SIZE - 3];
    id[4] = year[YEAR_SIZE - 2];
    id[5] = '\0';
}

bool add_new_index_id(char* id)
{

    /// if the element is found, it should not proceed with the insertion.
    if (searching_in_tree(id) == true)
        return false;

    /// if the search by id returned false, then the buffer is filled with the
    /// desired node unless there are no nodes in the btree. In the last case, it
    /// will be added as the first.

    if (g_buffer == NULL) {
        g_num_nodes++;
        g_buffer = malloc(sizeof(struct b_node));
        strcpy(g_buffer->ID[0], id);
        strcpy(g_buffer->ID[1], TMP_NAME);
        strcpy(g_buffer->ID[2], TMP_NAME);
        strcpy(g_buffer->ID[3], TMP_NAME);
        strcpy(g_buffer->ID[4], TMP_NAME);
        g_buffer->numkeys = 1;
        g_buffer->RRN = 0; ///< this will be the first node
        g_buffer->parent = -1; ///< there are no parents
        g_buffer->is_leaf = 1; ///< the first node is always a leaf
        g_buffer->children[0] = -1;
        g_buffer->children[1] = -1;
        g_buffer->children[2] = -1;
        g_buffer->children[3] = -1;
        g_buffer->children[4] = -1;
        g_buffer->children[5] = -1;

        g_buffer->keys_RRNS[0] = 0; ///< the first key will point to the first register in movies.dat
        g_buffer->keys_RRNS[1] = -1;
        g_buffer->keys_RRNS[2] = -1;
        g_buffer->keys_RRNS[3] = -1;
        g_buffer->keys_RRNS[4] = -1;

        g_buffer->next_node = -1;
        write_index_id_file();

    }

    /// load the node where it will be inserted
    else {
        /// case the insertion will not cause overflow.
        if (g_buffer->numkeys + 1 <= ORDER) {
            g_buffer->numkeys++;
            int index = g_buffer->numkeys - 1;
            strcpy(g_buffer->ID[index], id);
            g_buffer->keys_RRNS[index] = g_total_elements - 1;
            g_buffer->children[index] = -1;
            insertion_sort_id();
            write_index_id_file();

        }

        /// the insertion will cause overflow
        /// add the node as if nothing happened and calls the split function
        /// to handle the partition and promotion
        else {
            int index = g_buffer->numkeys;
            g_buffer->numkeys++;
            strcpy(g_buffer->ID[index], id);
            g_buffer->keys_RRNS[index] = g_total_elements - 1;
            g_buffer->children[index] = -1;
            insertion_sort_id();

            print_id();
            split_leaf();
        }
    }
    return true;
}

struct movie_index_name* add_new_index_name(struct movie_index_name* index_name,
    char* name, char* id)
{

    if (g_free_space > 0) {
        strcpy(index_name[g_total_elements - g_free_space - 1].name, name);
        strcpy(index_name[g_total_elements - g_free_space - 1].id, id);
        g_free_space--;

        if (g_total_elements - 1 > 0)
            insertion_sort_name(index_name, g_total_elements);

        return index_name;
    }

    struct movie_index_name* new_index_name = realloc(index_name, sizeof(struct movie_index_name) * g_total_elements);

    strcpy(new_index_name[g_total_elements - 1].name, name);
    strcpy(new_index_name[g_total_elements - 1].id, id);

    if (g_total_elements - 1 > 0)
        insertion_sort_name(new_index_name, g_total_elements);

    return new_index_name;
}

void insertion_sort_name(struct movie_index_name* array, int N)
{
    int i, j;
    struct movie_index_name key;

    for (i = 1; i < N; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && strcasecmp(array[j].name, key.name) > 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}
