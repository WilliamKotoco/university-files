/*
Arquivo que guarda as definições e funções para as árvores.
Há uma árvore dinâmica e uma em forma de vetor.
*/

#define num 15

typedef int *static_tree;

typedef struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
} dynamic_tree;


dynamic_tree *inserirTree(dynamic_tree *root, int value);

void percursos(dynamic_tree *root, int flag); // recebe a flag indicando qual percurso realizar

// para árvores estáticas
void static_inserirEsquerda(int parent, int value, static_tree tree);
void static_inserirDireita(int parent, int value, static_tree tree); // recebe o índice do pai e cria filho pra ele 


void static_percursos(static_tree tree, int flag, int index); //idem ao dinamico



