#include "../../include/SplitManager/split_manager.h"

extern struct b_node* g_buffer;
extern int g_root;
extern int g_total_elements;
extern int g_num_nodes;
void split_leaf()
{

    struct b_node* new_node = malloc(sizeof(struct b_node));

    struct b_node* parent = load_node(g_buffer->parent);
    /// if parent does not exist (first split) create the parent

    if (parent == NULL) {
        parent = create_parent();
    }

    g_num_nodes++;
    new_node->RRN = g_num_nodes - 1;
    new_node->next_node = g_buffer->next_node;
    g_buffer->next_node = new_node->RRN;
    new_node->parent = parent->RRN; // id of parent that was not created yet
    g_buffer->parent = parent->RRN; // id of parent that was not created yet

    /// split of order 5 promoving the first in right
    g_buffer->numkeys = 2;
    new_node->numkeys = 3;

    strcpy(new_node->ID[0], g_buffer->ID[MID_INDEX + 1]);
    strcpy(g_buffer->ID[MID_INDEX + 1], TMP_NAME);
    strcpy(new_node->ID[1], g_buffer->ID[MID_INDEX + 2]);
    strcpy(g_buffer->ID[MID_INDEX + 2], TMP_NAME);
    strcpy(new_node->ID[2], g_buffer->ID[MID_INDEX + 3]);
    strcpy(g_buffer->ID[MID_INDEX + 3], TMP_NAME);
    strcpy(new_node->ID[3], TMP_NAME);
    strcpy(new_node->ID[4], TMP_NAME);

    new_node->keys_RRNS[0] = g_buffer->keys_RRNS[MID_INDEX + 1];
    g_buffer->keys_RRNS[MID_INDEX + 1] = -1;
    new_node->keys_RRNS[1] = g_buffer->keys_RRNS[MID_INDEX + 2];
    g_buffer->keys_RRNS[MID_INDEX + 2] = -1;
    new_node->keys_RRNS[2] = g_buffer->keys_RRNS[MID_INDEX + 3];
    g_buffer->keys_RRNS[MID_INDEX + 3] = -1;

    new_node->children[0] = -1;
    new_node->children[1] = -1;
    new_node->children[2] = -1;
    new_node->children[3] = -1;
    new_node->children[4] = -1;
    new_node->children[5] = -1;

    new_node->is_leaf = 1;

    /// write the new leafs in file
    int left_child = g_buffer->RRN;
    int right_child = new_node->RRN;

    write_index_id_file();
    free(g_buffer);
    g_buffer = new_node;
    write_index_id_file();

    insert_in_parent(parent, new_node->ID[0], left_child, right_child);
}

void insert_in_parent(struct b_node* parent, char* id, int left_child, int right_child)
{
    int pos = search_through_node(parent, id);

    /// split
    if (parent->numkeys + 1 > ORDER) {
        int index = parent->numkeys;
        strcpy(parent->ID[index], id);
        parent->children[index] = left_child;
        parent->children[index + 1] = right_child;
        g_buffer = parent;
        insertion_sort_id();

        struct b_node* new_node = malloc(sizeof(struct b_node));
        struct b_node* new_parent = create_parent();
        g_num_nodes++;
        new_node->RRN = g_num_nodes - 1;
        new_node->is_leaf = 0;
        /// create parent functions changes the global root.
        new_node->parent = parent->parent = g_root;
        char promoted_key[ID_SIZE];
        parent->numkeys = 2;
        new_node->numkeys = 2;
        new_node->next_node = -1;

        strcpy(new_node->ID[0], parent->ID[MID_INDEX + 2]);
        strcpy(promoted_key, parent->ID[MID_INDEX + 1]);
        strcpy(parent->ID[MID_INDEX + 1], TMP_NAME);
        strcpy(parent->ID[MID_INDEX + 2], TMP_NAME);
        strcpy(new_node->ID[1], parent->ID[MID_INDEX + 3]);
        strcpy(parent->ID[MID_INDEX + 3], TMP_NAME);
        strcpy(new_node->ID[2], TMP_NAME);
        strcpy(new_node->ID[3], TMP_NAME);
        strcpy(new_node->ID[4], TMP_NAME);

        new_node->children[0] = parent->children[MID_INDEX + 2];
        parent->children[MID_INDEX + 1] = -1;
        parent->children[MID_INDEX + 2] = -1;
        new_node->children[1] = parent->children[MID_INDEX + 3];
        parent->children[MID_INDEX + 3] = -1;
        new_node->children[2] = parent->children[MID_INDEX + 4];
        parent->children[MID_INDEX + 4] = -1;
        new_node->children[3] = -1;
        new_node->children[4] = -1;
        new_node->children[5] = -1;


        new_node->keys_RRNS[0] = -1;
        new_node->keys_RRNS[1] = -1;
        new_node->keys_RRNS[2] = -1;
        new_node->keys_RRNS[3] = -1;
        new_node->keys_RRNS[4] = -1;

        int left_child = parent->RRN;
        int right_child = new_node->RRN;

        g_buffer = parent;
        write_index_id_file();

        /// update children's parent to be the new node.
        for (int i =0; i < new_node->numkeys + 1; i++)
        {
            struct b_node *tmp = load_node(new_node->children[i]);
            tmp->parent = new_node->RRN;
            g_buffer = tmp;
            write_index_id_file();
        }
        free(g_buffer);
        g_buffer = new_node;
        write_index_id_file();
        insert_in_parent(new_parent, promoted_key, left_child, right_child);
    } else {
        parent->numkeys++;
        int index = parent->numkeys - 1;
        strcpy(parent->ID[index], id);
        parent->children[index] = left_child;
        parent->children[index + 1] = right_child;
        g_buffer = parent;
        insertion_sort_id();
        write_index_id_file();
    }
}
struct b_node* create_parent()
{
    g_num_nodes++;
    struct b_node* parent = malloc(sizeof(struct b_node));
    parent->is_leaf = 0;
    parent->numkeys = 0;
    parent->RRN = g_num_nodes - 1;
    strcpy(parent->ID[0], TMP_NAME);
    strcpy(parent->ID[1], TMP_NAME);
    strcpy(parent->ID[2], TMP_NAME);
    strcpy(parent->ID[3], TMP_NAME);
    strcpy(parent->ID[4], TMP_NAME);

    parent->children[0] = -1;
    parent->children[1] = -1;
    parent->children[2] = -1;
    parent->children[3] = -1;
    parent->children[4] = -1;
    parent->children[5] = -1;

    parent->keys_RRNS[0] = -1;
    parent->keys_RRNS[1] = -1;
    parent->keys_RRNS[2] = -1;
    parent->keys_RRNS[3] = -1;
    parent->keys_RRNS[4] = -1;

    parent->next_node = -1;
    parent->parent = -1;
    /// the last created parent is the root always.
    g_root = parent->RRN;
    return parent;
}
