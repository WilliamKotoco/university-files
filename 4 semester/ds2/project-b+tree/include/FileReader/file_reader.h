
#ifndef PROJETO1_FILE_READER_H
#define PROJETO1_FILE_READER_H
#include "../components.h"
#include <string.h>
/**
 * \brief This function reads the ititle.idx file and returns the struct filled
 * with its data.
 *
 * The function also verify flags.
 *
 * The data in function is separated by the character @, like the data file. The
 * data is read by using strtok to separate the string using that special
 * character, since it's not possible to use blankspace as separator.
 * @return movie_index_name filled.
 */
void read_file_index_name();

/**
 * \brief Loads the node with the given RRN
 * @param rrn
 * @return the node
 */
struct b_node* load_node(unsigned int rrn);
/**
 * Reads flags from a file.
 *
 * This function reads flags from a file
 * line by line and stores each flag in a dynamically allocated array until the
 * end of the file is reached.
 *
 * @param fp The file pointer for the opened file.
 * @return An array of dynamically allocated strings containing the read flags,
 * or NULL if an error occurred. The caller is responsible for freeing the
 * memory allocated for the array and its elements when no longer needed.
 *
 * @note This function allocates memory for the returned array and the flag
 * strings using `malloc`. It is the caller's responsibility to free this memory
 * when it is no longer needed in order to prevent memory leaks.
 */

struct flags* read_flags_from_file(FILE* fp);

#endif // PROJETO1_FILE_READER_H
