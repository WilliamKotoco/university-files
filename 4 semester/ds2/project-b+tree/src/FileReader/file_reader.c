#include "../../include/FileReader/file_reader.h"
#include "../../include/DataProcessing/data_processor.h"
#include "../../include/FileBuilder/file_builder.h"
extern int g_total_elements;
extern struct movie_index_name* index_name;
extern int g_root;

extern int g_num_nodes;

void read_file_index_name()
{
    FILE* fp = fopen(SECONDARY_KEY_FILE, "r");

    if (fp == NULL)
        return;

    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    struct flags* flag = read_flags_from_file(fp);

    index_name = malloc(sizeof(struct movie_index_name) * g_total_elements);

    char registro[size];

    fgets(registro, size, fp);
    fclose(fp);

    int i = 0;
    char* token = strtok(registro, "@");
    ///@todo check where's the seg fault when trying to read a blank file
    while (token != NULL) {
        strcpy(index_name[i].name, token);
        token = strtok(NULL, "@");
        strcpy(index_name[i].id, token);
        token = strtok(NULL, "@");
        i++;
    }
}

struct flags* read_flags_from_file(FILE* fp)
{

    struct flags* flag = malloc(sizeof(struct flags));
    int root, node;
    fscanf(fp, "%d %d %d", &flag->qtd, &root, &node);
    g_total_elements = flag->qtd;
    g_root = root;
    g_num_nodes = node;
    return flag;
}

struct b_node* load_node(unsigned int RRN)
{
    char c;
    FILE* fp = fopen(PRIMARY_KEY_FILE, "r");
    if ((c = fgetc(fp) == EOF) || RRN == -1)
        return NULL;
    fseek(fp, RRN * B_TREE_NODE_SIZE, SEEK_SET);

    struct b_node* node = malloc(sizeof(struct b_node));
    fscanf(fp, "%d %u %u", &node->is_leaf, &node->RRN, &node->numkeys);

    for (int i = 0; i < ORDER + 1; i++)
        fscanf(fp, "%s", node->ID[i]);

    for (int i = 0; i < ORDER + 1; i++)
        fscanf(fp, "%d", &node->keys_RRNS[i]);

    for (int i = 0; i < ORDER + 2; i++)
        fscanf(fp, "%d", &node->children[i]);

    fscanf(fp, "%d", &node->parent);
    fscanf(fp, "%d", &node->next_node);

    return node;
}
