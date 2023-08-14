

#ifndef EXERCICIOS_AULA4_REGISTER_H
#define EXERCICIOS_AULA4_REGISTER_H
#include<stdio.h>
#include<stdlib.h>
struct register_file
{
    char name[400];
    unsigned int age;
    double money;
};

/// the index register file stores the index and the byte_offset
/// which is necessary for a direct acess.
struct index_register_file
{
    int index;
    long int byte_offset;
};

struct index_name_file
{
    char name[400];
    int index;
};


#endif
