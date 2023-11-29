
#ifndef PROJETO1_COMPONENTS_H
#define PROJETO1_COMPONENTS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAIN_FILE "movies.dat"
#define PRIMARY_KEY_FILE \
    "ibtree.idx"
#define SECONDARY_KEY_FILE \
    "ititle.idx"
#define TMP_FILE "temp.dat"

/// tmp dps mudar
// #define PRIMARY_KEY_FILE "/home/william/Documents/projeto-ribas-new/ibtree.idx"
// #define SECONDARY_KEY_FILE "/home/william/Documents/projeto-ribas-new/ititle.idx"
// #define MAIN_FILE "/home/william/Documents/projeto-ribas-new/movies.dat"

///
#define TMP_NAME "ZZZ99"
#define REGISTER_SIZE 192
#define ID_SIZE 6
#define NAME_SIZE 54
#define COUNTRY_SIZE 13
#define YEAR_SIZE 5

#define B_TREE_NODE_SIZE 192
#define ORDER 4
#define SEPARATOR '@'
/**
 * Defines the main structs used for the program. The size is fixed to 192
 * bytes.
 */

struct movie {
    /// \brief the first three digits of the director's surname + the last two
    /// digits of the year.
    char id[ID_SIZE];
    char name[NAME_SIZE];
    char translated_name[NAME_SIZE];
    char director[NAME_SIZE];
    char country[COUNTRY_SIZE];
    char year[YEAR_SIZE];
    char mark;
};

/// \brief B+ tree node
/// This struct is represents a node from a B+ tree, responsible
/// for storing nodes information
///
/// This struct stores leaf nodes and internal nodes.
struct b_node {
    /// \brief flag to verify if it is a leaf node
    int is_leaf;

    /// \brief node's RRN.
    unsigned int RRN;

    /// \brief array with the keys in that node.
    char ID[ORDER + 1][ID_SIZE];

    /// \brief Arrays with the RRNs associated with the keys.
    /// This field is only usable in a leaf node, since internal
    /// nodes do not store information
    int keys_RRNS[ORDER + 1];

    /// \brief RRNS to children in the specific position
    ///
    /// The children for 2th key will be in children[3] and children[2]
    int children[ORDER + 2];

    /// \brief The number of keys this nodes stores.
    unsigned int numkeys;

    /// \brief Reference to node's parent.
    int parent;
    /// \brief Reference to the next node in the linked list
    ///
    /// This field is only usable if the current node is a leaf
    int next_node;
};
/**
 * Retrieves the id by the name. This struct will be sorted as well for perform
 * a binary search.
 *
 * After retrieving the id, the register's position can be accessed using the
 * struct movie_index_id
 * @see struct movie_index_id
 *
 */
struct movie_index_name {
    char name[NAME_SIZE];
    char id[ID_SIZE];
};

/**
 * Stores the flags needed
 */
struct flags {
    char status_flag;
    int qtd;
};

#endif // PROJETO1_COMPONENTS_H
