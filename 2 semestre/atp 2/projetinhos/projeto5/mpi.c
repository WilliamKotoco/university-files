#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void bitonic_merge(int *array, int n) {
    int i, j, k;

// controla o tamanho do subvetor a ser comparado
    for (k = 2; k <= n; k = k * 2) {
        // controla o tamanho do deslocamento entre os elementos que serao comaprados
        for (j = k >> 1; j > 0; j = j >> 1) {
            // percorre o array
            for (i = 0; i < n; i++) {
                int ij = i ^ j;
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
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    double start = MPI_Wtime();
    bitonic_merge(array, 524288);
    double end = MPI_Wtime();

    if (rank == 0) {
    /* for (int i = 0; i < 524288; i++) {
        printf("%d ", array[524288]);
    }
    */
    printf("\n Tempo: %f segundos\n", end - start);
}

    MPI_Finalize();
    return 0;
}
