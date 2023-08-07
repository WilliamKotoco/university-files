

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

#define tam_fila 100  //tamanho max. fila
#define N 5       //Tamanho da matriz de conexões e vetor de distâncias

//ED para fila
//------------------------------------------------------
//Tipo fila
typedef struct
{
  int A[tam_fila];    //Simplificacao p/ aplicacao
  int inicio, fim;
} fila;
//------------------------------------------------------

//Operações da fila
//------------------------------------------------------
//Cria uma fila vazia
void Definir(fila *q) {
   q->fim = 0;
   q->inicio = 0;
   //Obs: ponteiro de início atrasado: aponta para uma posição anterior ao início
}

//Retorna true se fila não contém elementos, false caso contrário
bool Vazia(fila *q) {
	if (q->inicio == q->fim)
   		return true;
   	return false;
}

//Retorna true se fila cheia, false caso contrário
bool Cheia(fila *q) {
	if (q->inicio == ((q->fim + 1) % tam_fila))
		return true;
	return false;
   //Obs: os dois ponteiros diferem de uma posição
}

//Adiciona um elemento no fim da fila q (retorna true se sucesso, false c.c.) 
//Note que uma posição da fila nunca será preenchida
bool Inserir(fila *q, int elem) {	
   if (Cheia(q))
      return false;
   q->fim = (q->fim + 1) % tam_fila;
   q->A[q->fim] = elem;
   return true;
}

//Remove um elemento do início da fila q (retorna true se sucesso, false c.c.)
bool Remover(fila *q, int *elem) {
   if (Vazia(q))
      return false;
   q->inicio = (q->inicio + 1) % tam_fila;
   *elem = q->A[q->inicio];
   return true;
}
//------------------------------------------------------


//------------------------------------------------------
//Principal
//matriz A (de adj.): representa as conexões entre as cidades 0,...,N-1, 
//vetor 'dist': dist[i] é a distância da cidade fixada 'c' até cada cidade 'i'
int main() {
	//Inicialização da matriz com as cidades interconectadas
	int A[N][N] = { {0,1,0,1,1}, {0,0,1,0,0}, {0,0,0,0,1}, {0,0,1,0,1}, {0,0,0,1,0} };
	int dist[N]; //vai guardar a menor distância de c para o resto
	int i, j, c = 0; //c é o vértice inicial (calcula-se caminho mínimo dele pros demais)
	fila F;
	
	for (j=0; j<N; j++)  
	    dist[j] = N; //começa com a maior distância, dist[j], para todo j
    
	dist[c] = 0; //distância de c para ele mesmo (= 0)
    Definir(&F); //cria fila
    Inserir(&F,c); //insere c na fila

	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distancias já computadas
    while (!Vazia(&F)) 
	{ 
       Remover(&F,&i); //Remove da fila (i é o elemento corrente a partir daqui)
       for (j=0; j<N; j++)
          if (A[i][j] == 1 && dist[j] >= N) //anda toda a linha de i da matriz. Se i tem conexãoo com j (A[i][j] == 1) e j ainda não tiver sido checado
		  {
             dist[j] = dist[i] + 1; //está um elemento mais distante de i (se tivesse peso, dist[i] + A[i][j])
             Inserir(&F,j);
          }
    }
	
	//Imprime vetor de distâncias de 'c' para as demais cidades 'i'
	for (i=0; i<N; i++)
	   printf("dist[%d]: %d\n", i, dist[i]);	
}