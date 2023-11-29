//
// This component implements the binary search with strings.
//

#ifndef PROJETO1_BINARY_SEARCH_H
#define PROJETO1_BINARY_SEARCH_H
#include "../components.h"
#include <string.h>

int upper_bound_name(struct movie_index_name* array, int low, int high,
    char* name);

int lower_bound_name(struct movie_index_name* array, int low, int high,
    char* name);

/**
 * Performs a binary search on an array of movie_index_name for a specifig
 * target name
 *
 * This function will find the target name withing the sorted array  and find
 * the lower and upper bounds for indices with the same name within the array.
 * @param array The sorted array
 * @param target The name of the movie the function should search
 * @param lower The lower bound for the target name. Will be updated if target
 * name is found
 * @param upper The upper bound for the target name. Will be updates if target
 * name is found
 * @return The number of target's ocurrences within the array.
 */
int binary_search_name(struct movie_index_name* array, char* target, int* lower,
    int* upper);

/// @todo program a binary search here

#endif // PROJETO1_BINARY_SEARCH_H
