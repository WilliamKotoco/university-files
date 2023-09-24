
#ifndef PROJETO1_DATA_PROCESSOR_H
#define PROJETO1_DATA_PROCESSOR_H
#include "../components.h"
#include "../FileBuilder/file_builder.h"
#include <string.h>
#include <ctype.h>

/**
* Transforms the raw_data into a desired format for file addition. Once reformatted, it is passed to the function
 * that manages file entries.
 * @param index_id
 * @param index_name
 * @param raw_data
 * @return 1 or 0, being true or false respectively
 */
uint insertion_data_processing( struct movie raw_data);




/**
 * Format the director's name based on the following convention: Surname, FirstName.
 * @param name
 */
void format_directors_name(char *name);


/**
 * Given the director's name and the release year, creates the unique id based on the following rule:
 * the first three letters of directors field + the last two numbers of the realease year.
 */
void create_movie_id(char *director_name, char *year, char *id);


/**
 * Add the new movie on index_id struct and sorts it.

 */
struct movie_index_id* add_new_index_id(struct movie_index_id *index_id, char *id);

/**
 * Add the new move on index_name struct and sorts it

 */
struct movie_index_name * add_new_index_name(struct movie_index_name *index_name, char *name, char *id);

/**
 * Performs the insertion sort in the movie_index_id  struct. Due the fact
 * the array is almost sorted, the insertion sort is more efficiently than the qsort.
 * @param array movie_index_id array
 * @param N number of elements
 */
void insertion_sort_id(struct movie_index_id *array, int N);

/**
 * Performs the insertion sort in the movie_index_name  struct. Due the fact
 * the array is almost sorted, the insertion sort is more efficiently than the qsort.
 * @param array movie_index_name array
 * @param N number of elements
 */
void insertion_sort_name(struct movie_index_name *array, int N);
#endif //PROJETO1_DATA_PROCESSOR_H
