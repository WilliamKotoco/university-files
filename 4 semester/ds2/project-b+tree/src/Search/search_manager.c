#include "../../include/Search/search_manager.h"
extern int g_total_elements;
extern struct b_node* g_buffer;
extern struct movie_index_name* index_name;
extern int g_root;

void search_by_id(char* id)
{
    searching_in_tree(id);

    /// do the search and stores the result in
    /// the buffer case you found it

    if (g_buffer != NULL) {
        int pos = search_through_node(g_buffer, id);
        struct movie data = get_element_data(g_buffer->keys_RRNS[pos] * REGISTER_SIZE);
        print_movie(data);
        free(g_buffer);
    } else {
        printf("Nao tem nenhum filme com esse ID: %s", id);
    }
}

bool searching_in_tree(char* id)
{
    int RRN_node = g_root;

    while (true) {
        struct b_node* node = load_node(RRN_node);
        if (node == NULL)
            return false;
        int pos = search_through_node(node, id);
        if (node->is_leaf == 1) {
            g_buffer = node;

            if (strcasecmp(node->ID[pos], id) == 0) {
                return true;
            } else
                return false;
        }
        /// the pos will always indicate the child index if not found.
        if (strcasecmp(id, node->ID[pos]) >= 0)
            RRN_node = node->children[pos + 1];
        else
            RRN_node = node->children[pos];
    }
}

int search_through_node(struct b_node* node, char* id)
{
    int i = 0;
    while ((strcasecmp(id, node->ID[i]) > 0) && strcmp(node->ID[i], TMP_NAME) != 0)
        i++;
    return i;
}
void print_movie(struct movie raw_data)
{
    printf("\n \x1b[33m"
           "Dados do filme buscado"
           "\x1b[0m \n");
    printf("Nome.............: %s \n"
           "Nome original....: %s \n"
           "Diretor..........: %s \n"
           "Ano de lançamento: %s \n"
           "País de origem...: %s \n"
           "Nota:............: %c \n",
        raw_data.translated_name, raw_data.name, raw_data.director,
        raw_data.year, raw_data.country, raw_data.mark);
}
struct movie get_element_data(long int byteoffset)
{
    struct movie raw_data;
    FILE* fp = fopen(MAIN_FILE, "r");
    fseek(fp, byteoffset, SEEK_SET);
    char line[REGISTER_SIZE + 1];
    fgets(line, REGISTER_SIZE + 1, fp);

    char* token = strtok(line, "@");
    strcpy(raw_data.id, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.translated_name, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.name, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.director, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.year, token);
    token = strtok(NULL, "@");
    strcpy(raw_data.country, token);
    token = strtok(NULL, "@");
    raw_data.mark = *token;

    fclose(fp);
    return raw_data;
}

void search_by_name(char* name)
{

    int lower = -1;
    int upper = -1;

    int ocurrences = binary_search_name(index_name, name, &lower, &upper);

    if (lower == -1) {
        printf("O filme %s não foi cadastrado \n", name);
        return;
    }
    for (int i = lower; i <= upper; i++)
        search_by_id(index_name[i].id);
}

void sequential_search(char* id)
{

    bool check = searching_in_tree(id);

    struct b_node* node = g_buffer;

    int start = search_through_node(node, id);
    while (node) {
        for (int i = start; i < node->numkeys; i++) {
            struct movie data = get_element_data(node->keys_RRNS[i] * REGISTER_SIZE);
            print_movie(data);
        }
        free(node);
        node = load_node(node->next_node);
        start = 0;
    }
}
