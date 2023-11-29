#include "../../include/Remove/remove_manager.h"
#include "../../include/Search/search_manager.h"
extern int g_free_space;
extern int g_total_elements;
extern int g_eof;

extern struct movie_index_id* index_id;
extern struct movie_index_name* index_name;
void remove_caller(char* id)
{
    int index_of_id = -1;
    if (index_of_id == -1) {
        printf("Não existe filme com id %s", id);
        return;
    }
    struct movie raw_data;
    int index_of_name;
    int lower_index = 0;
    int higher_index = 0;
    int tmp = binary_search_name(index_name, raw_data.name, &lower_index,
        &higher_index);
    /// there are no need to check the movie's existence once the id does exist
    for (int i = lower_index; i <= higher_index; i++) {
        if (strcasecmp(index_name[i].id, id) == 0)
            index_of_name = i;
    }
    long int i = 23;
    remove_movie_file(i);
    remove_movie_index_name(index_of_name);
}

void remove_movie_index_name(int index)
{
    for (int i = index; i < g_total_elements; i++) {
        index_name[i] = index_name[i + 1];
    }
}
