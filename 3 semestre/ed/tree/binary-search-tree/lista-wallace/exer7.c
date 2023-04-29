#define MIN(a,b) (((a)<(b))?(a):(b))

/*
verify if it's a complete binary tree: every node have 0 or 2 child and every node are on the same level
*/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
};

struct tree *create(struct tree *node, int value)
{
    node = malloc(sizeof(struct tree));
    node->right = node->left = NULL;
    node->value = value;

    return node;
}
int height(struct tree *node)
{
    if (!node)
        return 0;
    int height_left = height(node->left);
    int height_right = height(node->right); 
    if(height_left != height_right)
        return INT_MIN;
    return MIN(height_left, height_right)  + 1;
    // being the min doesn't change anything because they're supposed to be equal
    // otherwise, it won't pass the test.
}
int verify(struct tree *node)
{
  int n = height(node);
  if (n > 0)
    return 1;
  return 0;
  }
void print(int n)
{
    if (n > 0)
        printf("it's a complete binary tree");
    else
        printf("it's not a complete binary tree");
    printf("\n");
}
int main()
{
    int n = 0;
    struct tree *root1, *aux;
    root1 = create(root1, 3);
    root1->left = aux = create(aux, 2);
    aux->left = create(aux->left, 0);
    aux->right = create(aux->right, 1);
    free(aux);
    root1->right = aux = create(aux, 4);
    aux->left = create(aux->left, 0);
    aux->right = create(aux->right, 1);

    n = verify(root1);
    print(n);


    /*
    Verify the difference between the height in nodes is enough.
    */
}