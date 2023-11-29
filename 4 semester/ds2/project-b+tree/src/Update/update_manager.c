//
// Created by willao on 14/09/23.
//
#include "../../include/Update/update_manager.h"
extern int g_total_elements;
extern int g_root;
extern struct b_node* g_buffer;
extern struct movie_index_name* index_name;
void update_call(char* id, char new_mark)
{
    bool check = searching_in_tree(id);
    if (!check) {
        puts("ID nao esta cadastrado, retornando...");
        return;
    }

    int pos = search_through_node(g_buffer, id);
    update_mark_movie_file(g_buffer->keys_RRNS[pos] * REGISTER_SIZE, new_mark);
    free(g_buffer);
}
