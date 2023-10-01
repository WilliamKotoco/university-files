#include "../../include/hash/hash.h"
#include <string.h>




int make_address(char *key, int depth)
{
  int retval = 0;
  int mask = 1;
  int hash_val = hash(key);

  for (int i = 0; i < depth; i++) {
    retval = retval << 1;
    int lowbit = hash_val & mask;
    
    retval = retval | lowbit;

    hash_val = hash_val >> 1;

  }

  return retval;
}

int hash(char *key) 
{
int sum = 0;
int len = strlen(key);

if (len % 2 == 1)
    len++;
  for (int j = 0; j < len; j += 2) 
    sum = (sum + 100 * key[j] * key[j+1])/MAX_PRIME;


  return sum;

}
