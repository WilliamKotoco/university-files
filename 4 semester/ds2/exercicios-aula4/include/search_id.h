//
// Created by willao on 13/08/23.
//

#ifndef EXERCICIOS_AULA4_SEARCH_ID_H
#define EXERCICIOS_AULA4_SEARCH_ID_H

#include "register.h"

/// search the file by its id in the index_file
void search_by_id(int total_elements);

/// receives the id and prepares for doing the binary search
/// by reading the file. Returns the binary_search result
long int prepare_binary_search_id(int id, int total_elements);

long int binary_search_id(struct index_register_file *elements, int id, int left, int right);

#endif //EXERCICIOS_AULA4_SEARCH_ID_H
