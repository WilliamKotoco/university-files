#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tree {
    char value;
    struct tree *right;
    struct tree *left;
};

/*
exercise a: function to verify if it's an empty tree
*/
bool  *is_empty(struct tree *root)
{
 return (root == NULL);
}
/*
exercise b: dinamically creates the node, already passing its children
weird tbh
*/
struct tree *create_node(struct tree *root, char c,struct tree *left_child, struct tree *right_child)
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
    if (root->value != key)
    {

    }
}


/*
exercise d: insert a node on left.
TODO
*/

/*
exerise e: prints the tree

TODO
*/

int main()
{
    struct tree *node = malloc(sizeof(struct tree));
    node->value = 'a';
    printf("%d ", is_empty(node));
    struct tree *root;
    root = create_node(root, 'a', node, NULL);
    printf("%c ", root->value);
}