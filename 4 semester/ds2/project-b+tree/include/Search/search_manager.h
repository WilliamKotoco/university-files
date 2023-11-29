//
// This component handles the search by id, search by name and search in
// movies.dat
//

#ifndef PROJETO1_SEARCH_MANAGER_H
#define PROJETO1_SEARCH_MANAGER_H
#include "../FileReader/file_reader.h"
#include "../components.h"
#include "binary_search.h"

/**
 * \brief Search for the movie and prints information if the movie was found.
 *
 * The function calls for searching in tree to check the existence and, if found, prints the information calling the print function.
 */
void search_by_id(char* id);

/**
 * \brief Search for the id in the b+ tree. If found, stores the information in the ´g_buffer´
 *
 * The algorithm travels the tree until it arrives in a leaf, where it will check every key and compare it to
 * the given id. In the B+ tree, every tree node is a duplicate of the original leaf node. Thus, it is only possible
 * to assert the existence of an element if the element has its duplicate in the leaf.
 * @param id
 * @return True if found, false otherwise.
 */
bool searching_in_tree(char* id);
/**
 *  Search by the name and calls the search by id function if the name was found
 * in the index_name struct.
 */

/// \brief Search for an id in a given b+tree node.
///
/// Traverse the node do find the ID. If found, returns the index. If not found, returns
/// the position before the first element greater than id. This position allow us to search in the children.
///  \param node
/// \return the position
int search_through_node(struct b_node* node, char* id);

void search_by_name(char* name);

/**
 * Reads from file in the specific byteoffset and returns the movie.
 * @param byteoffset
 */
struct movie get_element_data(long int byteoffset);

/// \brief appealing way to show movie's data.
/// \param raw_data movie's data
void print_movie(struct movie raw_data);

void sequential_search(char* id);
#endif // PROJETO1_SEARCH_MANAGER_H
