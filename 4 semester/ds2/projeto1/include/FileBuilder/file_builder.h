
#include "../components.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Reconstructs primary and secondary key files.
 *
 * This function operates when the status flag of `iprimary.idx` is set to `1`,
 * symbolizing that an update is required.
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
 * Reconstructs primary and second  key files.
 *
 * This function operates when the status flag of `iprimary.idx` is set to `1`,
 * symbolizing that an update is required.
 */
void rebuild_index_file();

/**
 * \brief compress the movies.dat file by eliminating the excluded registers from it.
 *
 * Creates a temporary  file to add the existent registers circulating through the primary keys
 * array. After adding all of them, rename this file to "movies.dat" and remove the old one.
 */
void file_compreesion();
