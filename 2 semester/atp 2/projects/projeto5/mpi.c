#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void bitonic_merge(int *array, int n) {
    int i, j, k;

// controla o tamanho do subvetor a ser comparado
    for (k = 2; k <= n; k = k * 2) {
        // controla o tamanho do deslocamento entre os elementos que serao comaprados
        // >> desloca 
        for (j = k >> 1; j > 0; j = j >> 1) {
            // "k" é multiplicado por 2 até que "k" seja maior ou igual a "n".
            // Isso permite que o algoritmo divida o vetor em subvetores cada vez maiores, 
            //até que o vetor inteiro seja comparado e ordenado.
            for (i = 0; i < n; i++) {
                int ij = i ^ j;
                // ^ representa xor, sendo 
                //possível obter a posição do elemento deslocado em relação ao elemento atual, comparando
                // elementos adjacentes sem precisar desloca-los na memoria

                // verifica se o elmeneto precisa ser comparado com o deslocado
                if ((ij) > i) {
                    // compara e troca
                    if ((i & k) == 0 && array[i] > array[ij] ||
                        ((i & k) != 0 && array[i] < array[ij])) {
                        int temp = array[i];
                        array[i] = array[ij];
                        array[ij] = temp;
                    }
                }
            }
        }
    }

    
}
// pq q tem que ter essa desgraça de argc
int main(int argc, char **argv)  {
    int array[524288];
    for (int i =0; i < 524288; i++)
        array[i] = rand()%1000;

    MPI_Init(&argc, &argv);
    int rank, size;
    // obtem o identificarod unico do processo atual
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //obtem o numero total de processos dentro do  comunicador
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    double start = MPI_Wtime();
    bitonic_merge(array, 524288);
    double end = MPI_Wtime();

     for (int i = 0; i < 524288; i++) {
        printf("%d ", array[i]);
     }
    
    printf("\n Tempo: %f segundos\n", end - start);
     MPI_Finalize();
    return 0;

}

   
