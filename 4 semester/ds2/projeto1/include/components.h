
#ifndef PROJETO1_COMPONENTS_H
#define PROJETO1_COMPONENTS_H
#include <stdio.h>
#include <stdlib.h>
#define MAIN_FILE "movies.dat"
#define PRIMARY_KEY_FILE "iprimary.idx"
#define SECONDARY_KEY_FILE "ititle.idx"
#define  TMP_FILE  "temp.dat"
#define REGISTER_SIZE 192
#define ID_SIZE 6
#define NAME_SIZE 54
#define COUNTRY_SIZE 13
#define YEAR_SIZE 5

#define SEPARATOR '@'
/**
 * Defines the main structs used for the program. The size is fixed to 192 bytes.
 */


 struct movie
 {
     /// \brief the first three digits of the director's surname + the last two digits of the year.
     char id[ID_SIZE];
     char name[NAME_SIZE];
     char translated_name[NAME_SIZE];
     char director[NAME_SIZE];
     char country[COUNTRY_SIZE];
     char year[YEAR_SIZE];
     char mark;

 };

/**
 * Struct responsible for being a faster way to access the data. The file will be small enough
 * to fit in the RAM, so processing that data should be fast.
 *
 * This struct will be sorted in order to perform a binary search and retrieve the position faster.
 */
 struct movie_index_id{
     char id[ID_SIZE];

     /// \brief Stores the byte position in the movies.dat
     long int byte_offset;
 };


 /**
  * Retrieves the id by the name. This struct will be sorted as well for perform a binary search.
  *
  * After retrieving the id, the register's position can be accessed using the struct movie_index_id
  * @see struct movie_index_id
  *
  */
 struct movie_index_name
 {
     char name[NAME_SIZE];
     char id[ID_SIZE];
 };


 /**
  * Stores the flags needed
  */
 struct flags
 {
     char status_flag;
     int qtd;
 };




#endif //PROJETO1_COMPONENTS_H
