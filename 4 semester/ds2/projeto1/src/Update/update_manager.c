//
// Created by willao on 14/09/23.
//
#include "../../include/Update/update_manager.h"
extern int g_total_elements;
extern struct movie_index_id *index_id;
extern struct movie_index_name  *index_name;
void update_call( char *id, char new_mark)
{
    int index = binary_search_id(index_id, id, 0,g_total_elements);

    if (index == -1)
    {
        printf("O ID %s não está cadastrado: ", id);
        return;
    }

    update_mark_movie_file(index_id[index].byte_offset, new_mark);



}
