/*
create a queue to perform a BFS in a bst
*/
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
};

struct queue 
{
struct queue *next;
struct tree *elem;
};

struct queue *enqueue(struct queue *first, struct tree *node)
{
struct queue *new = malloc(sizeof(struct queue));
new->elem = node;
if (!first)
    return new;
struct queue *tmp = first;
while (tmp->next)
{
    tmp = tmp->next;
}
tmp->next = new;
return first;
}

struct queue *pop(struct queue *first)
{
    struct queue *tmp = first->next;
    free(first);
    return tmp;
}

struct tree *newNode(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->value = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void bfs(struct tree *root)
{
    if (root == NULL)
        return;
    struct queue *queue  = malloc(sizeof(struct queue));
    queue = enqueue(queue, root);

    while(queue)
    {
        struct tree *curren_node = queue->elem;
        queue = pop(queue);
        printf("%d ", curren_node->value);

        if(curren_node->left)
            queue = enqueue(queue, curren_node->left);
        else if (curren_node->right)
            queue = enqueue(queue, curren_node->right);

        
    }

    

}

int main()
{
 struct tree *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    bfs(root);
}