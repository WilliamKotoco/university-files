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
struct stack
{
    struct tree *node;
    struct stack *next;
};
struct queue
{
    struct tree *node;
    struct queue *next;
};

struct tree *newNode(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->value = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
/*
returns the new top
*/
struct stack *push(struct tree *node, struct stack *top)
{
    struct stack *new = malloc(sizeof(struct stack));
    new->node = node;
    new->next = top;
    return new;
}

struct queue *q_push(struct tree *node, struct queue *fist)
{
    struct queue *new = malloc(sizeof(struct queue));
    new->node = node;
    struct queue *tmp = fist;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next =  new;
    return fist;
    
        
    return new;
}
/*
free the old top and returns the one who was below the old top as the new top
*/
struct stack *pop(struct stack *top, struct queue **last)
{
    struct stack *tmp = top->next;
    if (tmp &&  tmp->node)
    {
    if(tmp->node->left && tmp->node->left->value == top->node->value)
        tmp->node->left = NULL;
    if(tmp->node->right && tmp->node->right->value == top->node->value)
        tmp->node->right = NULL;
    }
    *last = q_push(top->node, *last);
    free(top);
    return tmp;
}

void non_recursive_post_order(struct tree *node)
{
    struct stack *top = malloc(sizeof(struct stack));
    struct queue *last = malloc(sizeof(struct queue));
    int left_removed = 0;
    int right_removed = 0;

    while (node)
    {
        do
        {
            top = push(node, top);
            node = node->left;
        } while (node->left);

        do
        {
            top = push(node,top);
            node = node->right;
        }   while(node && node->right);
        
    }

    while (top)
    {
        while (top->node && top->node->left)
        {
            top = push(top->node->left, top);
        }
        while (top-> node && top->node->right)
        {
            top = push(top->node->right, top);
        }

        top = pop(top, &last);

    }

    while (last->next)
    {
        if(last->node)
         printf("%d", last->node->value);
        last = last->next;
    }
}

int main()
{
    struct tree *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    non_recursive_post_order(root);
}
