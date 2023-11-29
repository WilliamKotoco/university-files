//
// Created by willao on 14/09/23.
//

#ifndef PROJETO1_UPDATE_MANAGER_H
#define PROJETO1_UPDATE_MANAGER_H
#include "../FileBuilder/file_builder.h"
#include "../Search/binary_search.h"
#include "../Search/search_manager.h"
#include "../components.h"
/**
 * Calls the function responsible for updating the mark. First it will check if
 * the given id exists, and then calls the function responsible for updating the
 * movies.dat file
 */
void update_call(char* id, char new_mark);

#endif // PROJETO1_UPDATE_MANAGER_H
