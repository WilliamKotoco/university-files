#include "../include/FileReader/file_reader.h"
#include "../include/components.h"
#include "../include/ui.h"
#include <stdio.h>

/// amount of elements added to the movies, even the removed ones.
int g_total_elements = 0;

long int g_eof = 0;
/// amount of elements removed during the program's execution.
int g_free_space = 0;

int g_num_nodes = 0;
/// \brief stores the RRN of the root.
int g_root = 0;
/// \brief This struct will be a buffer to temporarily stores
/// a node. It is useful for operations that requires searching.
///
struct b_node* g_buffer = NULL;
struct movie_index_name* index_name;



int main()
{
    read_file_index_name();
    // functions to open secondary key file
    // then it will create the files and allocate memory for struct
    if (index_name == NULL) {
        FILE* fp_name = fopen(SECONDARY_KEY_FILE, "w");
        FILE* fp_main = fopen(MAIN_FILE, "w");
        FILE* fp_id = fopen(PRIMARY_KEY_FILE, "w");
        fclose(fp_name);
        fclose(fp_main);
        fclose(fp_id);

        index_name = malloc(sizeof(struct movie_index_name));

    } else {
        FILE* fp = fopen(MAIN_FILE, "r");
        fseek(fp, 0, SEEK_END);
        g_eof = ftell(fp);
    }
    options();

    return 0;
}
