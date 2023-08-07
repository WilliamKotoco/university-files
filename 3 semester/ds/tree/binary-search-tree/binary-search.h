struct tree;
struct tree *search(struct tree *root, int value);
struct tree *insertion(struct tree *root, int value);
struct tree *delete(struct tree *root, int value);
struct tree *delete_two_nodes(struct tree *root, struct tree *sucessor);
void in_order(struct tree *root);