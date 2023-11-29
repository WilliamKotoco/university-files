
#include "../components.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 */
void write_index_id_file();

/**
 * Writes the information on the ititle.idx
 * @param index_name
 */
void write_index_name_file();

/**
 * Open the file movies.dat in the append mode and add the new information.
 * @param new_data
 */
void append_movies_file(struct movie new_data);

/**
 * Remove the file by adding  ** in the beginning of the deleted register.
 * @param byte_offset
 */
void remove_movie_file(long byte_offset);

/**
 * Updates the mark.
 * @param byte_offset
 */
void update_mark_movie_file(long byte_offset, char new_mark);

/**
 * Reconstructs secondary  key files.
 *
 * This function operates when the status flag of `ititle.idx` is set to `1`,
 * symbolizing that an update is required.
 */
void rebuild_index_file();

/// \brief Sorts the keys in a b_tree node
///
/// \note This function is called only to sort a array almost sorted. Each
/// insertion there will
///
/// be a sorting process, so the array will almost be sorted as well.
void insertion_sort_id();
void print_id();
