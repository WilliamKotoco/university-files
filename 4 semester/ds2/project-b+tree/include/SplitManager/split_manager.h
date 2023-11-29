
#ifndef PROJETO1_SPLIT_MANAGER_HPP
#define PROJETO1_SPLIT_MANAGER_HPP
#include "../FileBuilder/file_builder.h"
#include "../FileReader/file_reader.h"
#include "../Search/search_manager.h"
#include "../components.h"

#define MID_INDEX 1

/// \brief This function is responsible for splitting in the leaf.
///
/// The function splits the leaf and inserts in the parent the promoted key.
void split_leaf();

/// \brief Creates a new parent
/// The parent node is not leaf and thus does not have rrns for keys and does not have next node either.
/// This function returns a struct b_node with initial information.
struct b_node* create_parent();

/// \brief Insertes the promoted key in parent.
///
/// The function also handle internal splits, calling itself recursively for adding the parent of the previous parent.
void insert_in_parent(struct b_node* parent, char* id, int left_child, int right_child);

#endif // PROJETO1_SPLIT_MANAGER_HPP
