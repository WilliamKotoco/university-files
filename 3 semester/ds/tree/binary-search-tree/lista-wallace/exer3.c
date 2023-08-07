#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct tree
{
    char value;
    struct tree *right;
    struct tree *left;
};

/*
exercise a: function to verify if it's an empty tree
*/
bool *is_empty(struct tree *root)
{
    return (root == NULL);
}
/*
exercise b: dinamically creates the node, already passing its children
weird tbh
*/
struct tree *create_node(struct tree *root, char c, struct tree *left_child, struct tree *right_child)
{
    root = malloc(sizeof(struct tree));
    root->value = c;
    root->left = left_child;
    root->right = right_child;

    return root;
}

/*
exercise c: release in memory a node.

TODO:
*/
struct tree *delete_node(struct tree *root, char key)
{
    if(!root)
        return NULL;


    if (root->value == key)
    {
        if (!root->left && !root->right) // leaf
        {
            free(root);
            return NULL;
        }
        if (!root->left && root->right)
        {
            struct tree *tmp = root->right; // father of root will point to its right child;
            free(root);
            return tmp;
        }
        if (root->left && !root->right || (root->left && root->right))
        {
            struct tree *tmp = root->left; // father of root will point to its left child;
            free(root);
            return tmp;

            // if it has two child, the left one will replace the node.
            // there's no problem, because the tree isn't sorted.
        }
    }

    root->right = delete_node(root->right, key);
    root->left = delete_node(root->left, key);

    return root;
}

/*
exercise d: insert a node on left.
*/
struct tree *insert_left(struct tree *node, char value)
{
    struct tree *new = malloc(sizeof(struct tree));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    node->left = new;
    return new;
}
/*
exerise e: prints the tree


*/
void displayTree(struct tree *node, int mode)
{
    if (!node)
        return;
    switch (mode)
    {
    case 1: // display pre-order
        printf("%c ", node->value);
        displayTree(node->left, 1);
        displayTree(node->right, 1);
        break;

    case 2: // in-order
        displayTree(node->left, 2);
        printf("%c ", node->value);
        displayTree(node->right, 2);
        break;

    case 3: //  pos-order
        displayTree(node->left, 3);
        displayTree(node->right, 3);
        printf("%c ", node->value);
    }
}

int main()
{
    struct tree *node = malloc(sizeof(struct tree));
    node->value = 'a';
    printf("%d  \n", is_empty(node));
    struct tree *root;
    root = create_node(root, 'a', node, NULL);
    printf("%c \n", root->value);
    node = insert_left(root, 'b');
    node = insert_left(node, 'c');
    node = insert_left(node, 'd');
    displayTree(root, 3);
    root = delete_node(root, 'd');
    printf("\n");
    displayTree(root, 3);
}