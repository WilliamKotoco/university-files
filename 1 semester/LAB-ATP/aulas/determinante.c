#include <stdio.h>

int main() {
  float A[2][2], determinante;
  int i, j;
  for (i = 0; i<2;i++){
    // o for interno vai dar todos os loops, só assim o for externo será executado novamente
    for(j=0;j<2;j++){
      printf("A[%d][%d]: ", i, j);
      scanf("%f", &A[i][j]);
    }
    
  }
  determinante = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
  printf("Determinante: %f", determinante);
    return 0;
}
  
