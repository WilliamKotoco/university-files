// Crie um programa que leia e permita armazenar o nome, altura e peso de 5 pessoas.
// Cada pessoa deve ser representada por uma struct, que dever ́a ser alocada dentro de um
// vetor (vetor de structs). Ap ́os isso, o programa dever ́a:
// (a) Ler um valor de altura e um de peso espec ́ıfico;
// (b) Listar todos os nomes com alturas maiores daquela que foi fornecida em (a);
// (c) Listar todos os nomes com respectivos pesos acima do peso fornecido em (a).
#include <stdio.h>
#define pessoas 5
int main(){
   
    struct dados {
        int altura;
        float peso;
        char nome[40];
    } pessoa[pessoas];
    
    int altura_ref, i;
    float peso_ref;
    for ( i = 0; i < pessoas; i++){
        printf("Digite o nome: ");
        scanf("%s", pessoa[i].nome);
        printf("\n Digite o peso: ");
        scanf("%f", &pessoa[i].peso);
        printf("\n Digite a altura: ");
        scanf("%d", &pessoa[i].altura);
    
    }
    printf("\n Digite o peso para referencia: ");
    scanf("%f", &peso_ref);
    printf("\n Digite a altura para referencia: ");
    scanf("%d", &altura_ref);
    printf("\n Os que tem altura maior que %d: ", altura_ref);
    for ( i = 0; i < pessoas; i++){
        if (pessoa[i].altura > altura_ref){
            printf("\n %s ",pessoa[i].nome);
        }
    }
     printf("\n Os que tem peso maior que %f: ", peso_ref);
    for ( i = 0; i < pessoas; i++){
        if (pessoa[i].peso > peso_ref){
            printf("\n %s ",pessoa[i].nome);
        }
    }
    return 0;
}
