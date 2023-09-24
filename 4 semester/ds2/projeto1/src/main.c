#include <stdio.h>
#include "../include/components.h"
#include "../include/ui.h"
#include "../include/FileReader/file_reader.h"

/// amount of elements added to the movies, even the removed ones.
int g_total_elements = 0;
/// amount of elements removed during the program's execution.
int g_free_space = 0;
long int g_eof = 0;

struct movie_index_id *index_id = NULL;
struct movie_index_name *index_name = NULL;
int main() {

    /// TODO: Using an array for storing the indexes is not optimal
    /// because it's necessary to constantly reallocate memory.
    /// TODO: this should be changed to a better approach such as AVL trees or black-red trees.
    /// it will be changed if time allow me, once it'll be necessary to rebuild the entire project

     read_file_index_id();

// if PRIMARY_KEY_FILE does not exist, the SECONDARY_KEY_FILE will not exist as well.
// then it will create the files and allocate memory for struct
if (index_id == NULL)
{
    FILE *fp_id = fopen(PRIMARY_KEY_FILE, "w");
    FILE *fp_name = fopen(SECONDARY_KEY_FILE, "w");
    FILE *fp_main = fopen(MAIN_FILE, "w");
    fclose(fp_id);
    fclose(fp_name);
    fclose(fp_main);

    index_id = malloc(sizeof(struct movie_index_id));
    index_name = malloc(sizeof(struct movie_index_name));


}
else
{
    FILE *fp = fopen(MAIN_FILE, "r");
    fseek(fp, 0, SEEK_END);
    g_eof = ftell(fp);

}







  options();



    return 0;
}
