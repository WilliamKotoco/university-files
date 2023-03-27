#include <stdlib.h> //Para usar malloc, free, exit ...
#include <stdio.h>  //Para usar printf ,...
#include "lista.h"  //Carrega o arquivo .h criado

#define MAX 100 // estimativa do tamanho m�ximo da lista
#define TRUE 1  // define tipo boleano � n�o existe em C
#define FALSE 0
#define boolean int

// Implementa��o: lista seq.

// Opera��es
//-------------------------------------------
boolean Vazia(lista *L)
{
   // Retorna true (1): se vazia, false (0): caso contr�rio
   return (L->nelem == 0);
}

boolean Cheia(lista *L)
{
   // Retorna true (1): se cheia, false (0): caso contr�rio
   return (L->nelem == MAX);
}

void Definir(lista *L)
{
   /*Cria uma lista vazia. Este procedimento deve ser chamado
   para cada nova lista antes de qualquer outra opera��o.*/
   L->nelem = 0;
   L->A[0].chave = 0;
}

void Apagar(lista *L)
{
   // Apaga "logicamente" uma lista
   L->nelem = 0;
}

boolean Inserir_posic(tipo_elem x, int p, lista *L)
{
   /*Insere x, que � um novo elemento na posi��o p da lista
   Se L = a_1, a_2,... a_n ent�o temos a_1, a_2, ...
   a_{p-1}, x, a_{p+1}, ... an.
   Devolve true se sucesso, false c.c. (isto �: L n�o tem nenhuma
   posi��o p ou lista cheia). Obs: Opera��o para LISTA N�O-ORDENADA */

   int q;

   if (Cheia(L) || p > L->nelem + 1 || p < 1)
   {
      // Lista cheia ou posi��o n�o existe
      printf("ERRO \n");
      return FALSE;
   }
   else
   {
      for (q = L->nelem; q >= p; q--) // Copia vizinho p/ direita
         L->A[q + 1] = L->A[q];
         
      L->nelem++;
      x.chave = L->nelem;
      L->A[p] = x;

      return TRUE; // Inser��o feita com sucesso
   }
}

boolean Buscar(tipo_chave x, lista *L, int *p)
{
   /*Retorna true, se x ocorre na posi��o p. Se x ocorre mais de
   uma vez, retorna a posi��o da primeira ocorr�ncia. Se x n�o
   ocorre, retorna false. Para listas N�O-ORDENADAS*/

   if (!Vazia(L))
   {
      int i = 1;
      while (i <= L->nelem)
         if (L->A[i].chave == x)
         {
            *p = i;
            return TRUE;
         }
         else
            i++;
   }
   return FALSE; // Retorna false se n�o encontrou
}

void Remover_posic(int *p, lista *L)
{
   /*S� � ativada ap�s a busca ter retornado a posi��o p
   do elemento a ser removido - Nro de Mov = (nelem � p)*/

   int i;

   for (i = *p + 1; i <= L->nelem; i++)
      L->A[i - 1] = L->A[i];

   L->nelem--;
}

void Impr_elem(tipo_elem t)
{
 //  printf("chave: %d\n", t.chave);
//   printf("nome: %s\n", t.info.nome);
   printf("idade: %d\n", t.info.idade);
 //  printf("media final: %4.2f\n", t.info.media_final);
   //... (demais dados)
}

void Imprimir(lista *L)
{
   // Imprime os elementos na sua ordem de preced�ncia

   int i;

   if (!Vazia(L))
      for (i = 1; i <= L->nelem; i++)
         Impr_elem(L->A[i]);
}

int Tamanho(lista *L)
{
   // Retorna o tamanho da lista. Se L � vazia retorna 0

   return L->nelem;
}

// Implementa��es para listas ordenadas
//-------------------------------------------

void ordenarLista(lista *list)
{
   // será ordenado pela idade
   int i, j;
   lista aux;
   for (i = 2; i <= list->nelem; i++)
   {
      aux.A[0] = list->A[i];
      j = i;
      while (j > 1 && list->A[j - 1].info.idade > aux.A[0].info.idade)
      {
         list->A[j] = list->A[j - 1];
         j--;
      }
      list->A[j] = aux.A[0];
   }
}
boolean Inserir_ord(tipo_elem x, lista *L)
{
   /*Insere novo elemento de forma a manter a lista ordenada
   (crescente). Devolve true (se sucesso), false (c.c.)*/
   int i = 1;

   ordenarLista(L);

   // agora vamos buscar a posição para inserir
   while (L->A[i].info.idade < x.info.idade && i<=L->nelem)
      i++;
   return Inserir_posic(x, i, L);
}

boolean Busca_bin(tipo_chave x, lista *L, int *p)
{
   /*Retorna em p a posi��o de x na lista ORDENADA e true.
   //Se x n�o ocorre, retorna false*/

   // Implementa��o de busca bin�ria
   int inf = 1;
   int sup = L->nelem;
   int meio;

   while (!(sup < inf))
   {
      meio = (inf + sup) / 2;
      if (L->A[meio].chave == x)
      {
         *p = meio; // Sai da busca
         return TRUE;
      }
      else
      {
         if (L->A[meio].chave < x)
            inf = meio + 1;
         else
            sup = meio - 1;
      }
   }
   return FALSE;
}

boolean Remover_ch(tipo_chave x, lista *L)
{
   /*Remo��o dada a chave. Retorna true, se removeu, ou
   false, c.c.*/

   int *p;
   boolean removeu = FALSE;

   if (Busca_bin(x, L, p)) // Procura via busca bin�ria
   {
      Remover_posic(p, L);
      removeu = TRUE;
   }

   return removeu;
}
//-------------------------------------------