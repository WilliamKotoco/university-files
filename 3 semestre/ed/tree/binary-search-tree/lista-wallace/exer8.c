/*
code a non-recursive post-order
*/
#include <stdlib.h>
#include <stdio.h>
struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
};
