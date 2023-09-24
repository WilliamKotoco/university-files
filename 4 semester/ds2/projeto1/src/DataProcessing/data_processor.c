#include "../../include/DataProcessing/data_processor.h"

extern int g_total_elements;
extern int g_free_space;
extern long int g_eof;

extern struct movie_index_id *index_id;
extern struct movie_index_name  *index_name;
uint insertion_data_processing (struct movie raw_data) {
    /// the first movie was recorded in 1888, therefore there are no movies before it.
    if (atoi(raw_data.year) < 1888) {
        puts("Não existe nenhum filme antes de 1888");
        return 0;
    }

    if (strcasecmp(raw_data.translated_name, "idem") == 0)
        strcpy(raw_data.translated_name, raw_data.name);


    g_total_elements++;

    format_directors_name(raw_data.director);
    create_movie_id(raw_data.director, raw_data.year, raw_data.id);


     index_id = add_new_index_id(index_id, raw_data.id);
     index_name = add_new_index_name(index_name,raw_data.translated_name, raw_data.id);

    append_movies_file(raw_data);
   return 1;
}



void format_directors_name(char *name) {
    char first_name[NAME_SIZE / 2];
    char last_name[NAME_SIZE / 2];
    // separate the name in first name and surname
    char *token = strtok(name, " ");
    strcpy(first_name, token);
    token = strtok(NULL, "");
    strcpy(last_name, token);
    char formmated_name[NAME_SIZE];

    /// sprintf sends the formatted output to a string.
    sprintf(formmated_name, "%s, %s", last_name, first_name);
    strcpy(name, formmated_name);

}

void create_movie_id(char *director_name, char *year, char *id) {
    id[0] = toupper(director_name[0]);
    id[1] = toupper(director_name[1]);
    id[2] = toupper(director_name[2]);
    id[3] = year[YEAR_SIZE - 3];
    id[4] = year[YEAR_SIZE - 2];
    id[5] = '\0';

}

struct movie_index_id *add_new_index_id(struct movie_index_id *index_id, char *id) {

    if (g_free_space > 0)
    {
        strcpy(index_id[g_total_elements - g_free_space - 1].id, id);
        index_id[g_total_elements - g_free_space - 1].byte_offset = g_eof;
        g_free_space--;

        if (g_total_elements - 1 > 0)
            insertion_sort_id(index_id,g_total_elements);

        return index_id;
    }

    struct movie_index_id *new_index_id = realloc(index_id, sizeof(struct movie_index_id) * g_total_elements);



    strcpy(new_index_id[g_total_elements -1].id, id);
    new_index_id[g_total_elements - 1].byte_offset = g_eof;
    if (g_total_elements - 1> 0)
        insertion_sort_id(new_index_id, g_total_elements);
    g_eof += REGISTER_SIZE;

    return new_index_id;
}

struct movie_index_name *add_new_index_name(struct movie_index_name *index_name, char *name, char *id) {


    if (g_free_space > 0)
    {
        strcpy(index_name[g_total_elements - g_free_space - 1].name, name);
        strcpy(index_name[g_total_elements - g_free_space - 1].id, id);
        g_free_space--;

        if (g_total_elements - 1 > 0)
            insertion_sort_name(index_name,g_total_elements);

        return index_name;
    }

    struct movie_index_name *new_index_name = realloc(index_name, sizeof(struct movie_index_name) * g_total_elements);



    strcpy(new_index_name[g_total_elements-1].name, name);
    strcpy(new_index_name[g_total_elements-1].id,id);



    if(g_total_elements - 1 > 0)
         insertion_sort_name(new_index_name,g_total_elements);

        return new_index_name;
}


void insertion_sort_id(struct movie_index_id index_id[], int number_elements_id) {
    int i, j;
    struct movie_index_id key;

    for (i = 1; i < number_elements_id; i++) {
        key = index_id[i];
        j = i - 1;

        while (j >= 0 && strcmp(index_id[j].id, key.id) > 0) {
            index_id[j + 1] = index_id[j];
            j = j - 1;
        }

        index_id[j + 1] = key;
    }
}

void insertion_sort_name(struct movie_index_name *array, int N) {
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



