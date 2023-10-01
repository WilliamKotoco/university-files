/*
 * This simple hashing algorithm has three steps, for strings:
 * 1 - represent the key in the numerical form 
 * 2 - fold and add 
 *  in this step we can fold two numbers. For example: LOWELL = 76 79 87 79 76 76 can be
 *  folded as 7679 8779 7676 and sum them.
 *
 *  3 - divide by a prime number and use the remainder as an address. dividing by a prime number usually produces a more random distributuion  
 */

#include <stddef.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define MAX_CHAR 30
#define MAX_ADDR 900 // the greater the number of address, less likely to have collisions. 
#define MAX_PRIME 19937

struct person {
  char name[MAX_CHAR];
  int age;
};


struct person *hash_table[MAX_ADDR];


int hash(char *key, int maxAddr)
{

    int sum  = 1;
    size_t size = strlen(key);
    for (int i =0; i < size; i += 2)
        sum += (sum * 100 * key[i] * key[i+1]) % MAX_PRIME;
    return sum % maxAddr;
}

void init_hash_table()
{
  for (int i = 0; i < MAX_ADDR; i++)
  {
    hash_table[i] = NULL;
  }
  
}

void insert_hash_table(struct person *person)
{
  int addr = hash(person->name, MAX_ADDR);

  if(hash_table[addr] != NULL)
    puts("This place already holds a key");
  else
    hash_table[addr] = person;

}


void print_hash_table()
{
  printf("Start:");
  for (int i = 0; i < MAX_ADDR; i++)
  {
    if (hash_table[i] == NULL)
      printf("\n%d ----- ", i);
    else
      printf("\n%d ----- %s ", i, hash_table[i]->name);
  }
  printf("End");
}

/// The main advantage of a hashing table is that searching is always O(1)
/// Check the code and see that it requires no loop.
int search_hash(char *name)
{
  int addr = hash(name, MAX_ADDR);

  if (hash_table[addr] != NULL && strcmp(hash_table[addr]->name, name) == 0)
    return addr;
  else
    return -1;
}

int main()
{

  init_hash_table();

  struct person person1;
  strcpy(person1.name, "Alice");
  person1.age = 30;

  struct person person2;
  strcpy(person2.name, "Bob");
  person2.age = 25;

  struct person person3;
  strcpy(person3.name, "Charlie");
  person3.age = 35;

  // Inserindo as pessoas na tabela hash
  insert_hash_table(&person1);
  insert_hash_table(&person2);
  insert_hash_table(&person3);

  print_hash_table();

  int addr = search_hash("asdkjc");
  if (addr != -1)
    printf("\n Found on position %d", addr);
  else
    printf("\n Not on the table");


  return 0;
}
