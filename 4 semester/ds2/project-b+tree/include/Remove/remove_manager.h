
#ifndef PROJETO1_REMOVE_MANAGER_H
#define PROJETO1_REMOVE_MANAGER_H
#include "../FileBuilder/file_builder.h"
#include "../Search/binary_search.h"
#include "../components.h"
/**
 * Calls functions to remove the element both from struct_movie_index_id and
 * from movie_index_name after attest the existence of it.
 */
void remove_caller(char* id);

/**
 *  Removes the element with the corresponding id form the array.
 *
 *  Does that by moving backwards from N to i. For example, if we removed the
 * element from the 3th position, we move the 4th position to 3th position, the
 * 5th to 4th and so on...
 *
 */
void remove_movie_index_id(int index);

/**
 *  Removes the element with the corresponding id form the array.
 *
 *  Does that by moving backwards from N to i. For example, if we removed the
 * element from the 3th position, we move the 4th position to 3th position, the
 * 5th to 4th and so on...
 *
 */
void remove_movie_index_name(int index);

#endif // PROJETO1_REMOVE_MANAGER_H
