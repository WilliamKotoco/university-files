struct tree
{
    int val;
    int priority;
    int num_elements;
};
#define PARENT(i) ((i-1)/2) // getting the parent of a node using the formula of a complete binary tree
#define LEFT_SON(i) (2*i+1)
#define RIGHT_SON(i) (2*i+2)

/**
 * this function exchanges two nodes.
*/
void exchange(struct tree *elem1, struct tree *elem2);

/**
 * inserts the elmenent on the array and evaluates if the tree needs to 
 * change due priority issues.
*/
void insert(struct tree elem, struct tree *array);

/**
 * goes up with an element to adjust the tree according to the element's priority
 * used after insertion function.
*/
void goingUp(struct tree *array, int key); 

/**
 * Remove the max priority element and reorder the tree
*/
void removers(struct tree *array);

/**
 * goes down with an element to adjust the tree according to the elements priority. 
 * Used after remove function because it exchanges the last with the first.
*/
void goingDown (struct tree *array, int key);

/**
 * Builds the heap from an array
*/
void buildHeapFromArray(struct tree *array);