//
// This component handles the search by id, search by name and search in movies.dat
//

#ifndef PROJETO1_SEARCH_MANAGER_H
#define PROJETO1_SEARCH_MANAGER_H
#include "../components.h"
#include "binary_search.h"

/**
 * Search by the id and returns the results, which can be the movie's data or a message indicating that
 * the movie is not yet added.
 */
void search_by_id( char *id);

/**
 *  Search by the name and calls the search by id function if the name was found in the
 *  index_name struct.
 */
void search_by_name(char *name);

/**
 * Reads from file in the specific byteoffset and returns the movie.
 * @param byteoffset
 */
struct movie get_element_data(long int byteoffset);
#endif //PROJETO1_SEARCH_MANAGER_H
