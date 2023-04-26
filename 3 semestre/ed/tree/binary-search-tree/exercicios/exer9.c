/*
 in this exercise we want to remove every even number from a bst
 first we search for a node and then calls the remove function, repeating it until there's no even
*/
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
};

struct tree *insertion(struct tree *node, int value)
{
    if (node == NULL)
    {
        node = malloc(sizeof(struct tree));
        node->right = node->left = NULL;
        node->value = value;

        return node;
    }
    if (value > node->value)
    {
        node->right = insertion(node->right, value);
    }
    else if (value < node->value)
    {
        node->left = insertion(node->left, value);
    }
    return node;
}

struct tree *remove_even_nodes(struct tree *node)
{

    // base:
    if (node == NULL)
        return NULL;
    else if (node->value % 2 == 0)
    {
        // in this point we want to remove the node
        if (!node->left && !node->right) // leaf
        {
            free(node);
            return NULL;
        }

        else if (!node->left && node->right)
        {
            struct tree *tmp = node->right;
            free(node);
            return tmp;
        }

        else if (node->left && !node->right)
        {
            struct tree *tmp = node->left;
            free(node);
            return tmp;
        }

        else // has both child
        {
            // we use the strategy of exchanging by the biggest on left subtree
            struct tree *tmp = node->left;
            while (tmp->right)
                tmp = tmp->right;
            int value = node->value; // the even number that will be removed
            node->value = tmp->value;
            tmp->value = value;
            node->left = remove_even_nodes(node->left); // eventually a leaf or one child
            node->right = remove_even_nodes(node->right);
            return node;
        }
    }

    return node;
}

struct tree *remove_all_even_nodes(struct tree *node)
{
    while(node && node->value %2 == 0)
    {
        node = remove_even_nodes(node);
    }
    if(node)
    {
        node->left = remove_all_even_nodes(node->left);
        node->right = remove_all_even_nodes(node->right);
    }
    
    return node;
}

void pre_order(struct tree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    pre_order(root->left);
    pre_order(root->right);
}

int main()
{
    struct tree *root = NULL;
    root = insertion(root, 2);
    root = insertion(root, 4);
    root = insertion(root, 3);
    root = insertion(root, 99);
    root = insertion(root, 324);
    root = insertion(root, 5);

    printf("%d", root->value);
    printf("\n");
    pre_order(root);

   root = remove_all_even_nodes(root);    
    printf("\n");
    pre_order(root);
}