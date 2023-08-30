/*
 * This simple hashing algorithm has three steps, for strings:
 * 1 - represent the key in the numerical form 
 * 2 - fold and add 
 *  in this step we can fold two numbers. For example: LOWELL = 76 79 87 79 76 76 can be
 *  folded as 7679 8779 7676 and sum them.
 *
 *  3 - divide by a prime number and use the remainder as an address. dividing by a prime number usually produces a more random distributuion  
 */

#include<stdio.h>
#include <stdlib.h>
#define MAX_CHAR 30

int hash(char *key, int maxAddr)
{
    int sum  = 0;
    for (int i =0; i < MAX_CHAR; i += 2)
        sum = (sum * 100 * key[i] * key[i+1]) % 19937;
    return sum % maxAddress;
}
