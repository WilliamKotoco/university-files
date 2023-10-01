#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRIME 19937
/// Function responsible for creating an address based on a hashing formula 
/// It is a simple variaton of the fold-and-add algorithm.
int hash (char *key);


///  since we are using extensible hashing, we do not need the fully address,
///  only a portion of it. This funciton returns this portion based on the
///  currently depth we are on the directory trie..
int make_address(char *key, int depth);


