#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
    int qtd_elem;
};

struct array
{
    int array[1000];      // stores the values
    int current_position; // stores the current indice
};

struct array *getArrayFromTree(struct tree *root, struct array *array)
{
    getArrayFromTree(root->left, array);
    array->array[array->current_position] = root->value;
    array->current_position++;
    getArrayFromTree(root->right, array);
}
int main()
{
    struct array *array = malloc(sizeof(struct array));
    array->current_position = 0;
    struct tree *root = malloc(sizeof(struct tree));
    array = getArrayFromTree(root, array);
    int mid = (array->current_position)/2;
    for (int i =0 ; i < array->current_position; i++)
    {
        
    }

}       